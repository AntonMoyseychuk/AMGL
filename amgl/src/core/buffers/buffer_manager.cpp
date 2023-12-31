#include "pch.hpp"

#include "core/amgl_state.hpp"

#include "buffer_manager.hpp"
#include "core/id_storage.hpp"

namespace amgl
{
    struct vertex_arrays
    {
        std::array<id_t, id_storage::MAX_UNIQUE_IDS> binded_vbos;
        std::array<id_t, id_storage::MAX_UNIQUE_IDS> binded_ebos;
        id_storage ids;
    };

    
    struct buffers
    {
        std::array<byte_buffer, id_storage::MAX_UNIQUE_IDS> memory_blocks;
        
        std::array<enum_t, id_storage::MAX_UNIQUE_IDS> targets;
        id_storage ids;
    };

    
    struct buffer_mng_internal_storage
    {
        buffers vbos;
        vertex_arrays vaos;
    };

    
    static buffer_mng_internal_storage gs_storage;
    static amgl_state& gs_amgl_state = get_amgl_global_state();


    static bool _check_vao_validity(id_t vao) noexcept
    {
        if (gs_storage.vaos.ids.is_busy(vao)) {
            return true;
        }

        // todo: push invalid vao id error message
        return false;
    }


    static bool _check_buffer_args_validity(const id_t* buffer, const enum_t* target, const enum_t* usage, const enum_t* access) noexcept
    {
        if (buffer && !is_buffer(*buffer)) {
            // todo: push invalid id error message
            return false;
        }

        if (target && !IN_INTERVAL_INCLUSIVE(_BUFFER_TARGET_BLOCK_BEGIN + 1, _BUFFER_TARGET_BLOCK_END - 1, *target)) {
            // todo: push invalid target error message
            return false;
        }

        if (usage && !IN_INTERVAL_INCLUSIVE(_BUFFER_USAGE_BLOCK_BEGIN + 1, _BUFFER_USAGE_BLOCK_END - 1, *usage)) {
            // todo: push invalid usage error message
            return false;
        }

        if (access && !IN_INTERVAL_INCLUSIVE(_BUFFER_ACCESS_BLOCK_BEGIN + 1, _BUFFER_ACCESS_BLOCK_END - 1, *access)) {
            // todo: push invalid access error message
            return false;
        }

        return true;
    }


    static void _bind_buffer_to_vao(id_t vao, enum_t target, id_t buffer) noexcept
    {
        switch (target)
        {
        case ARRAY_BUFFER:
            gs_storage.vaos.binded_vbos[vao] = buffer;
            break;
        case ELEMENT_ARRAY_BUFFER:
            gs_storage.vaos.binded_ebos[vao] = buffer;
            break;
        case COPY_READ_BUFFER: // todo
            break;               
        case COPY_WRITE_BUFFER: // todo
            break;              
        case SHADER_STORAGE_BUFFER: // todo
            break;          
        case UNIFORM_BUFFER: //todo
            break;
        }
    }


    buffer_mng &buffer_mng::instance() noexcept
    {
        static buffer_mng s_buffer_mng;
        return s_buffer_mng;
    }


    id_t buffer_mng::generate_buffer() const noexcept
    {
        return gs_storage.vbos.ids.generate_id();
    }

    
    void buffer_mng::free_id(id_t id) const noexcept
    {
        gs_storage.vbos.ids.free_id(id);
    }

    
    void buffer_mng::bind_buffer(enum_t target, id_t buffer) const noexcept
    {
        if (!_check_buffer_args_validity(&buffer, &target, nullptr, nullptr)) {
            return;
        }

        gs_amgl_state.bind_buffer_to_target(target, buffer);
        gs_storage.vbos.targets[buffer] = target;
        
        if (gs_amgl_state.vao != 0) {
            _bind_buffer_to_vao(gs_amgl_state.vao, target, buffer);
        }
    }

    
    void buffer_mng::allocate_named_memory(id_t buffer, uint64_t size, const void *data, enum_t usage) const noexcept
    {
        if (!_check_buffer_args_validity(&buffer, nullptr, &usage, nullptr)) {
            return;
        }

        gs_storage.vbos.memory_blocks[buffer].resize(size, 0);

        if (data != nullptr) {
            memcpy_s(gs_storage.vbos.memory_blocks[buffer].data(), size, data, size);
        }
    }

    
    void buffer_mng::allocate_memory(enum_t target, uint64_t size, const void *data, enum_t usage) const noexcept
    {
        if (!_check_buffer_args_validity(nullptr, &target, &usage, nullptr)) {
            return;
        }
    
        const id_t buffer = gs_amgl_state.get_buffer_binded_to_target(target);
        allocate_named_memory(buffer, size, data, usage);
    }

    
    bool buffer_mng::is_buffer(id_t buffer) const noexcept
    {
        return gs_storage.vbos.ids.is_busy(buffer);
    }

    
    void *buffer_mng::map_named_buffer(id_t buffer, enum_t access) const noexcept
    {
        if (!_check_buffer_args_validity(&buffer, nullptr, nullptr, &access)) {
            return nullptr;
        }

        return gs_storage.vbos.memory_blocks[buffer].data();
    }

    
    void *buffer_mng::map_buffer(enum_t target, enum_t access) const noexcept
    {
        if (!_check_buffer_args_validity(nullptr, &target, nullptr, &access)) {
            return nullptr;
        }
        
        const id_t buffer = gs_amgl_state.get_buffer_binded_to_target(target);
        return map_named_buffer(buffer, access);
    }

    
    id_t buffer_mng::generate_vertex_array() const noexcept
    {
        return gs_storage.vaos.ids.generate_id();
    }

    
    void buffer_mng::free_vertex_array(id_t array) const noexcept
    {
        gs_storage.vaos.ids.free_id(array);
    }
    
    
    void buffer_mng::bind_vertex_array(id_t array) const noexcept
    {
        if (!_check_vao_validity(array)) {
            return;
        }

        gs_amgl_state.vao = array;
        gs_amgl_state.vbo = gs_storage.vaos.binded_vbos[array];
        gs_amgl_state.ebo = gs_storage.vaos.binded_ebos[array];
        // todo: make for other targets
    }
}