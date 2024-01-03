#include "pch.hpp"
#include "amgl/amgl.hpp"

#include "buffer_manager.hpp"
#include "id_storage.hpp"

namespace amgl
{
    static buffer_mng& gs_buffer_mng = buffer_mng::instance();
    
    void gen_buffers(uint64_t n, id_t* buffers) noexcept
    {
        RETURN_IF_NULLPTR(buffers);

        for (uint64_t i = 0; i < n; ++i) {
            buffers[i] = gs_buffer_mng.generate_buffer();
        }
    }


    void delete_buffers(uint64_t n, const id_t* buffers) noexcept
    {
        RETURN_IF_NULLPTR(buffers);

        for (uint64_t i = 0; i < n; ++i) {
            gs_buffer_mng.free_buffer(buffers[i]);
        }
    }


    void bind_buffer(enum_t target, id_t buffer) noexcept
    {
        gs_buffer_mng.bind_buffer(target, buffer);
    }

    void bind_buffer_base(enum_t target, uint32_t index, id_t buffer) noexcept
    {
        gs_buffer_mng.bind_buffer_base(target, index, buffer);
    }
    
    void buffer_data(enum_t target, uint64_t size, const void *data, enum_t usage) noexcept
    {
        gs_buffer_mng.allocate_memory(target, size, data, usage);
    }


    void named_buffer_data(id_t buffer, uint64_t size, const void* data, enum_t usage) noexcept
    {
        gs_buffer_mng.allocate_named_memory(buffer, size, data, usage);
    }


    void named_buffer_sub_data(id_t buffer, uint64_t offset, uint64_t size, const void* data) noexcept
    {
        gs_buffer_mng.named_sub_data(buffer, offset, size, data);
    }

    
    void copy_buffer_sub_data(enum_t read_target, enum_t write_target, uint64_t read_offset, uint64_t write_offset, uint64_t size) noexcept
    {
        gs_buffer_mng.copy_buffer_sub_data(read_target, write_target, read_offset, write_offset, size);
    }

    
    void copy_named_buffer_sub_data(id_t read_buffer, id_t write_buffer, uint64_t read_offset, uint64_t write_offset, uint64_t size) noexcept
    {
        gs_buffer_mng.copy_named_buffer_sub_data(read_buffer, write_buffer, read_offset, write_offset, size);
    }


    void get_buffer_sub_data(enum_t target, uint64_t offset, uint64_t size, void* data) noexcept
    {
        gs_buffer_mng.get_buffer_sub_data(target, offset, size, data);
    }


    void get_named_buffer_sub_data(id_t buffer, uint64_t offset, uint64_t size, void* data) noexcept
    {
        gs_buffer_mng.get_named_buffer_sub_data(buffer, offset, size, data);
    }

    
    void buffer_sub_data(enum_t target, uint64_t offset, uint64_t size, const void* data) noexcept
    {
        gs_buffer_mng.sub_data(target, offset, size, data);
    }


    bool is_buffer(id_t buffer) noexcept
    {
        return gs_buffer_mng.is_buffer(buffer);
    }


    void* map_named_buffer(id_t buffer, enum_t access) noexcept
    {
        return gs_buffer_mng.map_named_buffer(buffer, access);
    }


    void* map_buffer(enum_t target, enum_t access) noexcept
    {
        return gs_buffer_mng.map_buffer(target, access);
    }


    void gen_vertex_arrays(uint64_t n, id_t* arrays) noexcept
    {
        RETURN_IF_NULLPTR(arrays);

        for (uint64_t i = 0; i < n; ++i) {
            arrays[i] = gs_buffer_mng.generate_vertex_array();
        }
    }


    void delete_vertex_arrays(uint64_t n, const id_t* arrays) noexcept
    {
        RETURN_IF_NULLPTR(arrays);

        for (uint64_t i = 0; i < n; ++i) {
            gs_buffer_mng.free_vertex_array(arrays[i]);
        }
    }


    void bind_vertex_array(id_t array) noexcept
    {
        gs_buffer_mng.bind_vertex_array(array);
    }
}