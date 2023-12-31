#include "pch.hpp"
#include "amgl_state.hpp"

namespace amgl
{   
    amgl_state &get_amgl_global_state() noexcept
    {
        static amgl_state state;
        return state;
    }

    void amgl_state::bind_buffer_to_target(enum_t target, id_t buffer) noexcept
    {
        switch (target) {
        case ARRAY_BUFFER: 
            vbo = buffer; 
            return;
        case ELEMENT_ARRAY_BUFFER:
            ebo = buffer; 
            return;           
        case COPY_READ_BUFFER:
            copy_read_buffer = buffer; 
            return;               
        case COPY_WRITE_BUFFER:
            copy_write_buffer = buffer; 
            return;              
        case SHADER_STORAGE_BUFFER:
            shader_storage_buffer = buffer; 
            return;          
        case UNIFORM_BUFFER:
            uniform_buffer = buffer; 
            return;
        }
    }


    id_t amgl_state::get_buffer_binded_to_target(enum_t target) const noexcept
    {
        switch (target) {
        case ARRAY_BUFFER:          return vbo;
        case ELEMENT_ARRAY_BUFFER:  return ebo;           
        case COPY_READ_BUFFER:      return copy_read_buffer;               
        case COPY_WRITE_BUFFER:     return copy_write_buffer;
        case SHADER_STORAGE_BUFFER: return shader_storage_buffer;
        case UNIFORM_BUFFER:        return uniform_buffer;
        }

        return 0;
    }
}