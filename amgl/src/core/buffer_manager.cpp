#include "pch.hpp"

#include "buffer_manager.hpp"
#include "context.hpp"

#include "id_storage.hpp"

namespace amgl
{
#if defined(_DEBUG) || defined(DEBUG) || !defined(NDEBUG)
    #define PUSH_INVALID_VAO_ID_ERROR_MSG() NOT_IMPLEMENTED_YET("Invalid VAO ID. Call some function from debug processing code or something like that")
    #define PUSH_INVALID_BUFFER_ID_ERROR_MSG() NOT_IMPLEMENTED_YET("Invalid buffer ID. Call some function from debug processing code or something like that")
    #define PUSH_INVALID_BUFFER_TARGET_ERROR_MSG() NOT_IMPLEMENTED_YET("Invalid buffer target. Call some function from debug processing code or something like that")
    #define PUSH_INVALID_BUFFER_USAGE_ERROR_MSG() NOT_IMPLEMENTED_YET("Invalid buffer usage. Call some function from debug processing code or something like that")
    #define PUSH_INVALID_BUFFER_ACCESS_ERROR_MSG() NOT_IMPLEMENTED_YET("Invalid buffer access. Call some function from debug processing code or something like that")
    #define PUSH_BUFFER_OVERFLOW_ERROR_MSG() NOT_IMPLEMENTED_YET("offset + size >= buffer.size. Call some function from debug processing code or something like that")
    #define PUSH_BUFFER_OVERLAP_ERROR_MSG() NOT_IMPLEMENTED_YET("[read_offset,read_offset+size) and [write_offset,write_offset+size) overlap. Call some function from debug processing code or something like that")
#else
    #define PUSH_INVALID_VAO_ID_ERROR_MSG()
    #define PUSH_INVALID_BUFFER_ID_ERROR_MSG()
    #define PUSH_INVALID_BUFFER_TARGET_ERROR_MSG()
    #define PUSH_INVALID_BUFFER_USAGE_ERROR_MSG()
    #define PUSH_INVALID_BUFFER_ACCESS_ERROR_MSG()
    #define PUSH_BUFFER_OVERFLOW_ERROR_MSG()
    #define PUSH_BUFFER_OVERLAP_ERROR_MSG()
#endif

    struct buffers
    {
        std::array<std::vector<byte_t>, id_storage::MAX_UNIQUE_IDS> memory_blocks;
        std::array<enum_t, id_storage::MAX_UNIQUE_IDS> targets;
        id_storage ids;
    };

    struct vertex_arrays
    {
        std::array<id_t, id_storage::MAX_UNIQUE_IDS> binded_vbos;
        std::array<id_t, id_storage::MAX_UNIQUE_IDS> binded_ebos;
        // todo: add other bindings if exist
        id_storage ids;
    };

    struct buffer_mng_internal_storage
    {
        buffers buffs;
        vertex_arrays vaos;
    };
    static buffer_mng_internal_storage gs_storage;


    static inline bool is_valid_buffer(const buffers& buffers_storage, id_t buffer) noexcept
    {
        return buffers_storage.ids.is_busy(buffer);
    }


    static inline bool is_valid_buffer_target(enum_t target) noexcept
    {
        return IN_INTERVAL_INCLUSIVE(_BUFFER_TARGET_BLOCK_BEGIN + 1, _BUFFER_TARGET_BLOCK_END - 1, target);
    }


    static inline bool is_valid_buffer_usage(enum_t usage) noexcept
    {
        return IN_INTERVAL_INCLUSIVE(_BUFFER_USAGE_BLOCK_BEGIN + 1, _BUFFER_USAGE_BLOCK_END - 1, usage);
    }


    static inline bool is_valid_buffer_access(enum_t access) noexcept
    {
        return IN_INTERVAL_INCLUSIVE(_BUFFER_ACCESS_BLOCK_BEGIN + 1, _BUFFER_ACCESS_BLOCK_END - 1, access);
    }


    static inline bool is_valid_vao(const vertex_arrays& vao_storage, id_t vao) noexcept
    {
        return vao_storage.ids.is_busy(vao);
    }


    static void bind_buffer_to_vao(vertex_arrays& vao_storage, id_t vao, enum_t target, id_t buffer) noexcept
    {
        switch (target)
        {
        case AMGL_ARRAY_BUFFER:
            vao_storage.binded_vbos[vao] = buffer;
            break;
        case AMGL_ELEMENT_ARRAY_BUFFER:
            vao_storage.binded_ebos[vao] = buffer;
            break;
        case AMGL_COPY_READ_BUFFER:
            NOT_IMPLEMENTED_YET("AMGL_COPY_READ_BUFFER");
            break;               
        case AMGL_COPY_WRITE_BUFFER:
            NOT_IMPLEMENTED_YET("AMGL_COPY_WRITE_BUFFER");
            break;              
        case AMGL_SHADER_STORAGE_BUFFER:
            NOT_IMPLEMENTED_YET("AMGL_SHADER_STORAGE_BUFFER");
            break;          
        case AMGL_UNIFORM_BUFFER:
            NOT_IMPLEMENTED_YET("AMGL_UNIFORM_BUFFER");
            break;
        default:
            NOT_IMPLEMENTED_YET("target");
            return;
        }
    }


    static void update_state_target_buffer(context& state, enum_t target, id_t buffer) noexcept
    {
        switch (target) {
        case AMGL_ARRAY_BUFFER: 
            state.binded_buffers.vbo = buffer; 
            return;
        case AMGL_ELEMENT_ARRAY_BUFFER:
            state.binded_buffers.ebo = buffer; 
            return;           
        case AMGL_COPY_READ_BUFFER:
            state.binded_buffers.crbo = buffer; 
            return;               
        case AMGL_COPY_WRITE_BUFFER:
            state.binded_buffers.cwbo = buffer; 
            return;              
        case AMGL_SHADER_STORAGE_BUFFER:
            state.binded_buffers.ssbo = buffer; 
            return;          
        case AMGL_UNIFORM_BUFFER:
            state.binded_buffers.ubo = buffer; 
            return;
        default:
            NOT_IMPLEMENTED_YET("target");
            return;
        }
    }


    static id_t get_buffer_by_target_from_state(context& state, enum_t target) noexcept
    {
        switch (target) {
        case AMGL_ARRAY_BUFFER:          return state.binded_buffers.vbo;
        case AMGL_ELEMENT_ARRAY_BUFFER:  return state.binded_buffers.ebo;           
        case AMGL_COPY_READ_BUFFER:      return state.binded_buffers.crbo;               
        case AMGL_COPY_WRITE_BUFFER:     return state.binded_buffers.cwbo;
        case AMGL_SHADER_STORAGE_BUFFER: return state.binded_buffers.ssbo;
        case AMGL_UNIFORM_BUFFER:        return state.binded_buffers.ubo;
        default: NOT_IMPLEMENTED_YET("target");
        }

        return 0;
    }


    buffer_mng &buffer_mng::instance() noexcept
    {
        static buffer_mng s_buffer_mng;
        return s_buffer_mng;
    }


    id_t buffer_mng::generate_buffer() const noexcept
    {
        return gs_storage.buffs.ids.generate_id();
    }

    
    void buffer_mng::free_buffer(id_t buffer) const noexcept
    {
        if (IS_DEFAULT_ID(buffer)) {
            return;
        }

        deallocate_named_memory(buffer);
        gs_storage.buffs.ids.free_id(buffer);
    }

    
    void buffer_mng::bind_buffer(enum_t target, id_t buffer) const noexcept
    {
        static context& state = context::instance();

        if (!is_valid_buffer_target(target)) {
            PUSH_INVALID_BUFFER_TARGET_ERROR_MSG();
            return;
        }

        if (!is_valid_buffer(gs_storage.buffs, buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        update_state_target_buffer(state, target, buffer);

        if (!IS_DEFAULT_ID(buffer)) {
            gs_storage.buffs.targets[buffer] = target;
        }
        
        if (!IS_DEFAULT_ID(state.binded_buffers.vao)) {
            bind_buffer_to_vao(gs_storage.vaos, state.binded_buffers.vao, target, buffer);
        }
    }


    void buffer_mng::bind_buffer_base(enum_t target, uint32_t index, id_t buffer) noexcept
    {
        NOT_IMPLEMENTED_YET("void buffer_mng::bind_buffer_base(enum_t target, uint32_t index, id_t buffer) noexcept");
    }


    void buffer_mng::allocate_named_memory(id_t buffer, uint64_t size, const void *data, enum_t usage) const noexcept
    {
        if (!is_valid_buffer_usage(usage)) {
            PUSH_INVALID_BUFFER_USAGE_ERROR_MSG();
            return;
        }

        if (!is_valid_buffer(gs_storage.buffs, buffer) || IS_DEFAULT_ID(buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        gs_storage.buffs.memory_blocks[buffer].resize(size, 0);

        if (data != nullptr) {
            memcpy_s(gs_storage.buffs.memory_blocks[buffer].data(), size, data, size);
        }
    }

    
    void buffer_mng::allocate_memory(enum_t target, uint64_t size, const void *data, enum_t usage) const noexcept
    {
        static context& state = context::instance();

        if (!is_valid_buffer_target(target)) {
            PUSH_INVALID_BUFFER_TARGET_ERROR_MSG();
            return;
        }

        if (!is_valid_buffer_usage(usage)) {
            PUSH_INVALID_BUFFER_USAGE_ERROR_MSG();
            return;
        }
    
        const id_t buffer = get_buffer_by_target_from_state(state, target);
        allocate_named_memory(buffer, size, data, usage);
    }

    
    void buffer_mng::named_sub_data(id_t buffer, uint64_t offset, uint64_t size, const void *data) noexcept
    {
        if (!is_valid_buffer(gs_storage.buffs, buffer) || IS_DEFAULT_ID(buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        const uint64_t buffer_size = gs_storage.buffs.memory_blocks[buffer].size();
        if (offset + size >= buffer_size) {
            PUSH_BUFFER_OVERFLOW_ERROR_MSG();
            return;
        }

        if (data == nullptr) {
            return;
        }

        byte_t* dst = gs_storage.buffs.memory_blocks[buffer].data() + offset;
        memcpy_s(dst, buffer_size, data, size);
    }

    
    void buffer_mng::sub_data(enum_t target, uint64_t offset, uint64_t size, const void *data) noexcept
    {
        static context& state = context::instance();

        if (!is_valid_buffer_target(target)) {
            PUSH_INVALID_BUFFER_TARGET_ERROR_MSG();
            return;
        }

        const id_t buffer = get_buffer_by_target_from_state(state, target);
        named_sub_data(buffer, offset, size, data);
    }

    void buffer_mng::deallocate_named_memory(id_t buffer) const noexcept
    {
        if (IS_DEFAULT_ID(buffer)) {
            return;
        }

        if (!is_valid_buffer(gs_storage.buffs, buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        gs_storage.buffs.memory_blocks[buffer].clear();
        gs_storage.buffs.memory_blocks[buffer].shrink_to_fit();
    }

    
    void buffer_mng::copy_buffer_sub_data(enum_t read_target, enum_t write_target, uint64_t read_offset, uint64_t write_offset, uint64_t size) noexcept
    {
        static context& state = context::instance();

        if (!is_valid_buffer_target(read_target)) {
            PUSH_INVALID_BUFFER_TARGET_ERROR_MSG();
            return;
        }

        if (!is_valid_buffer_target(write_target)) {
            PUSH_INVALID_BUFFER_TARGET_ERROR_MSG();
            return;
        }

        const id_t read_buffer = get_buffer_by_target_from_state(state, read_target);
        const id_t write_buffer = get_buffer_by_target_from_state(state, write_target);
        copy_named_buffer_sub_data(read_buffer, write_buffer, read_offset, write_offset, size);
    }

    
    void buffer_mng::copy_named_buffer_sub_data(id_t read_buffer, id_t write_buffer, uint64_t read_offset, uint64_t write_offset, uint64_t size) noexcept
    {
        if (!is_valid_buffer(gs_storage.buffs, read_buffer) || IS_DEFAULT_ID(read_buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        if (!is_valid_buffer(gs_storage.buffs, write_buffer) || IS_DEFAULT_ID(write_buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        const uint64_t read_buffer_size = gs_storage.buffs.memory_blocks[read_buffer].size();
        if (read_offset + size >= read_buffer_size) {
            PUSH_BUFFER_OVERFLOW_ERROR_MSG();
            return;
        }

        const uint64_t write_buffer_size = gs_storage.buffs.memory_blocks[write_buffer].size();
        if (write_offset + size >= write_buffer_size) {
            PUSH_BUFFER_OVERFLOW_ERROR_MSG();
            return;
        }

        const bool is_overlaped = 
            IN_INTERVAL_INCLUSIVE(write_offset, write_offset + size, read_offset) || 
            IN_INTERVAL_INCLUSIVE(read_offset, read_offset + size, write_offset);
        if (read_buffer == write_buffer && is_overlaped) {
            PUSH_BUFFER_OVERLAP_ERROR_MSG();
            return;
        }
    }


    void buffer_mng::get_buffer_sub_data(enum_t target, uint64_t offset, uint64_t size, void* data) noexcept
    {
        static context& state = context::instance();

        const id_t buffer = get_buffer_by_target_from_state(state, target);
        get_named_buffer_sub_data(buffer, offset, size, data);
    }


    void buffer_mng::get_named_buffer_sub_data(id_t buffer, uint64_t offset, uint64_t size, void* data) noexcept
    {
        if (!is_valid_buffer(gs_storage.buffs, buffer) || IS_DEFAULT_ID(buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return;
        }

        const uint64_t buffer_size = gs_storage.buffs.memory_blocks[buffer].size();
        if (offset + size >= buffer_size) {
            PUSH_BUFFER_OVERFLOW_ERROR_MSG();
            return;
        }

        if (data == nullptr) {
            return;
        }

        const byte_t* src = gs_storage.buffs.memory_blocks[buffer].data() + offset;
        memcpy_s(data, size, src, buffer_size);
    }

    
    bool buffer_mng::is_buffer(id_t buffer) const noexcept
    {
        if (IS_DEFAULT_ID(buffer)) {
            return false;
        }

        if (!is_valid_buffer(gs_storage.buffs, buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return false;
        }

        return true;
    }

    
    void *buffer_mng::map_named_buffer(id_t buffer, enum_t access) const noexcept
    {
        if (!is_valid_buffer_access(access)) {
            PUSH_INVALID_BUFFER_ACCESS_ERROR_MSG();
            return nullptr;
        }

        if (!is_valid_buffer(gs_storage.buffs, buffer)) {
            PUSH_INVALID_BUFFER_ID_ERROR_MSG();
            return nullptr;
        }

        if (IS_DEFAULT_ID(buffer)) {
            return nullptr;
        }

        return gs_storage.buffs.memory_blocks[buffer].data();
    }

    
    void *buffer_mng::map_buffer(enum_t target, enum_t access) const noexcept
    {
        static context& state = context::instance();

        if (!is_valid_buffer_target(target)) {
            PUSH_INVALID_BUFFER_TARGET_ERROR_MSG();
            return nullptr;
        }

        if (!is_valid_buffer_access(access)) {
            PUSH_INVALID_BUFFER_ACCESS_ERROR_MSG();
            return nullptr;
        }
        
        const id_t buffer = get_buffer_by_target_from_state(state, target);
        return map_named_buffer(buffer, access);
    }

    
    id_t buffer_mng::generate_vertex_array() const noexcept
    {
        return gs_storage.vaos.ids.generate_id();
    }

    
    void buffer_mng::free_vertex_array(id_t array) const noexcept
    {
        static context& state = context::instance();

        if (IS_DEFAULT_ID(array)) {
            return;
        }

        gs_storage.vaos.ids.free_id(array);
        if (state.binded_buffers.vao == array) {
            state.binded_buffers.vao = 0;
        }
    }
    
    
    void buffer_mng::bind_vertex_array(id_t array) const noexcept
    {
        static context& state = context::instance();

        if (!is_valid_vao(gs_storage.vaos, array)) {
            PUSH_INVALID_VAO_ID_ERROR_MSG();
            return;
        }

        if (IS_DEFAULT_ID(array)) {
            return;
        }

        state.binded_buffers.vao = array;
        state.binded_buffers.vbo = gs_storage.vaos.binded_vbos[array];
        state.binded_buffers.ebo = gs_storage.vaos.binded_ebos[array];
        // todo: make for other targets and layout
    }
}