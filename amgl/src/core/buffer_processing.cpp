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


    void buffer_data(enum_t target, uint64_t size, const void* data, enum_t usage) noexcept
    {
        gs_buffer_mng.allocate_memory(target, size, data, usage);
    }


    void named_buffer_data(id_t buffer, uint64_t size, const void* data, enum_t usage) noexcept
    {
        gs_buffer_mng.allocate_named_memory(buffer, size, data, usage);
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