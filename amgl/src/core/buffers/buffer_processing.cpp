#include "pch.hpp"
#include "amgl/amgl.hpp"

#include "buffer_manager.hpp"

#include "core/id_storage.hpp"

namespace amgl
{
    static buffer_mng& gs_buffer_mng_inst = buffer_mng::instance();
    
    void gen_buffers(uint64_t n, id_t* buffers) noexcept
    {
        RETURN_IF_NULLPTR(buffers);

        for (uint64_t i = 0; i < n; ++i) {
            buffers[i] = gs_buffer_mng_inst.generate_buffer();
        }
    }


    void delete_buffers(uint64_t n, const id_t* buffers) noexcept
    {
        RETURN_IF_NULLPTR(buffers);

        for (uint64_t i = 0; i < n; ++i) {
            gs_buffer_mng_inst.free_id(buffers[i]);
        }
    }


    void bind_buffer(enum_t target, id_t buffer) noexcept
    {
        gs_buffer_mng_inst.bind_buffer(target, buffer);
    }


    void buffer_data(enum_t target, uint64_t size, const void* data, enum_t usage) noexcept
    {
        gs_buffer_mng_inst.allocate_memory(target, size, data, usage);
    }


    void named_buffer_data(id_t buffer, uint64_t size, const void* data, enum_t usage) noexcept
    {
        gs_buffer_mng_inst.allocate_named_memory(buffer, size, data, usage);
    }


    bool is_buffer(id_t buffer) noexcept
    {
        return gs_buffer_mng_inst.is_buffer(buffer);
    }


    void* map_named_buffer(id_t buffer, enum_t access) noexcept
    {
        return gs_buffer_mng_inst.map_named_buffer(buffer, access);
    }


    void* map_buffer(enum_t target, enum_t access) noexcept
    {
        return gs_buffer_mng_inst.map_buffer(target, access);
    }


    void gen_vertex_arrays(uint64_t n, id_t* arrays) noexcept
    {
        RETURN_IF_NULLPTR(arrays);

        for (uint64_t i = 0; i < n; ++i) {
            arrays[i] = gs_buffer_mng_inst.generate_vertex_array();
        }
    }


    void delete_vertex_arrays(uint64_t n, const id_t* arrays) noexcept
    {
        RETURN_IF_NULLPTR(arrays);

        for (uint64_t i = 0; i < n; ++i) {
            gs_buffer_mng_inst.free_vertex_array(arrays[i]);
        }
    }


    void bind_vertex_array(id_t array) noexcept
    {
        gs_buffer_mng_inst.bind_vertex_array(array);
    }
}