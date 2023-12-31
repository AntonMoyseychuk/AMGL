#pragma once
#include <cstdint>

namespace amgl 
{
    using id_t = uint16_t;
    using enum_t = uint16_t;
    using ubyte_t = uint8_t;

    enum constants : enum_t
    {
        _BUFFER_TARGET_BLOCK_BEGIN = 1,
            ARRAY_BUFFER,                   
            ELEMENT_ARRAY_BUFFER,           
            COPY_READ_BUFFER,               
            COPY_WRITE_BUFFER,              
            SHADER_STORAGE_BUFFER,          
            UNIFORM_BUFFER,                 
        _BUFFER_TARGET_BLOCK_END,

        _BUFFER_USAGE_BLOCK_BEGIN,
            STATIC_DRAW,                    
            DYNAMIC_DRAW,                   
        _BUFFER_USAGE_BLOCK_END,

        _BUFFER_ACCESS_BLOCK_BEGIN,
            READ_ONLY,                      
            WRITE_ONLY,                     
            READ_WRITE,                     
        _BUFFER_ACCESS_BLOCK_END,
    };

#pragma region buffer objects
    void gen_buffers(uint64_t n, id_t* buffers) noexcept;
    void delete_buffers(uint64_t n, const id_t* buffers) noexcept;

    void bind_buffer(enum_t target, id_t buffer) noexcept;

    void named_buffer_data(id_t buffer, uint64_t size, const void* data, enum_t usage /* unused yet */) noexcept;
    void buffer_data(enum_t target, uint64_t size, const void* data, enum_t usage /* unused yet */) noexcept;

    bool is_buffer(id_t buffer) noexcept;

    void* map_named_buffer(id_t buffer, enum_t access) noexcept;
    void* map_buffer(enum_t target, enum_t access) noexcept;
#pragma endregion buffer objects

#pragma region vertex array objects
    void gen_vertex_arrays(uint64_t n, id_t* arrays) noexcept;
    void delete_vertex_arrays(uint64_t n, const id_t* arrays) noexcept;

    void bind_vertex_array(id_t array) noexcept;
#pragma endregion vertex array objects
}