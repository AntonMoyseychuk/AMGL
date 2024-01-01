#pragma once
#include <cstdint>

namespace amgl 
{
    using byte_t = uint8_t;
    using short_t = int16_t;
    using ushort_t = uint16_t;
    using id_t = ushort_t;
    using enum_t = ushort_t;

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


#pragma region debug
    using debugproc = void (*)(enum_t source, enum_t type, uint32_t id, enum_t severity,
        uint64_t length, const char* message, const void* user_param);
#pragma endregion debug


#pragma region state management
    void blend_color(float red, float green, float blue, float alpha) noexcept;
    void blend_equation(enum_t mode) noexcept;                                                              // todo
    void blend_equation_separate(enum_t mode_rgb, enum_t mode_alpha) noexcept;                              // todo
    void blend_func(enum_t sfactor, enum_t dfactor) noexcept;                                               // todo
    void blend_func_separate(enum_t src_rgb, enum_t dst_rgb, enum_t src_alpha, enum_t dst_alpha) noexcept;  // todo
    
    void stencil_func(enum_t func, int32_t ref, uint32_t mask) noexcept;                                    // todo
    void stencil_func_separate(enum_t face, enum_t func, int32_t ref, uint32_t mask) noexcept;              // todo
    void stencil_mask(uint32_t mask) noexcept;                                                              // todo
    void stencil_mask_separate(enum_t face, uint32_t mask) noexcept;                                        // todo
    void stencil_op(enum_t sfail, enum_t dpfail, enum_t dppass) noexcept;                                   // todo
    void stencil_op_separate(enum_t face, enum_t sfail, enum_t dpfail, enum_t dppass) noexcept;             // todo
    
    void logic_op(enum_t opcode) noexcept;                                                                  // todo
    void clip_control(enum_t origin, enum_t depth) noexcept;                                                // todo
    void color_mask(bool red, bool green, bool blue, bool alpha) noexcept;                                  // todo
    void cull_face(enum_t mode) noexcept;                                                                   // todo
    void front_face(enum_t mode) noexcept;                                                                  // todo
    void polygon_mode(enum_t face, enum_t mode) noexcept;                                                   // todo

    void depth_func(enum_t func) noexcept;                                                                  // todo
    void depth_mask(bool flag) noexcept;                                                                    // todo
    void depth_range(float near, float far) noexcept;                                                       // todo
    
    void enable(enum_t cap) noexcept;                                                                       // todo
    void enablei(enum_t cap, uint32_t index) noexcept;                                                        // todo
    void disable(enum_t cap) noexcept;                                                                      // todo
    void disablei(enum_t cap, uint32_t index) noexcept;                                                       // todo
    bool is_enabled(enum_t cap) noexcept;                                                                   // todo
    bool is_enabledi(enum_t cap, uint32_t index) noexcept;                                                  // todo

    void get_booleanv(enum_t pname, bool* data) noexcept;                                                   // todo
    void get_doublev(enum_t pname, double* data) noexcept;                                                  // todo
    void get_floatv(enum_t pname, float* data) noexcept;                                                    // todo
    void get_integerv(enum_t pname, int32_t* data) noexcept;                                                // todo
    void get_integer64v(enum_t pname, int64_t* data) noexcept;                                              // todo
    void get_booleani_v(enum_t target, uint32_t index, bool* data) noexcept;                                // todo
    void get_integeri_v(enum_t target, uint32_t index, int32_t* data) noexcept;                             // todo
    void get_floati_v(enum_t target, uint32_t index, float* data) noexcept;                                 // todo
    void get_doublei_v(enum_t target, uint32_t index, double* data) noexcept;                               // todo
    void get_integer64i_v(enum_t target, uint32_t index, int64_t* data) noexcept;                           // todo

    void scissor(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept;                           // todo
    void viewport(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept;                          // todo

    enum_t get_error() noexcept;                                                                            // todo

#pragma endregion state management


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