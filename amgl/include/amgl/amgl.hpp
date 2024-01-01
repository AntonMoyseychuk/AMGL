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
        AMGL_NO_ERROR,
        AMGL_INVALID_ENUM,
        AMGL_INVALID_VALUE,
        AMGL_INVALID_OPERATION,
        AMGL_INVALID_FRAMEBUFFER_OPERATION,
        AMGL_OUT_OF_MEMORY,
        AMGL_STACK_UNDERFLOW,
        AMGL_STACK_OVERFLOW,

        _BUFFER_TARGET_BLOCK_BEGIN,
            AMGL_ARRAY_BUFFER,
            AMGL_ELEMENT_ARRAY_BUFFER,
            AMGL_COPY_READ_BUFFER,
            AMGL_COPY_WRITE_BUFFER,
            AMGL_SHADER_STORAGE_BUFFER,
            AMGL_UNIFORM_BUFFER,
        _BUFFER_TARGET_BLOCK_END,

        _BUFFER_USAGE_BLOCK_BEGIN,
            AMGL_STATIC_DRAW,
            AMGL_DYNAMIC_DRAW,
        _BUFFER_USAGE_BLOCK_END,

        _BUFFER_ACCESS_BLOCK_BEGIN,
            AMGL_READ_ONLY,
            AMGL_WRITE_ONLY,
            AMGL_READ_WRITE,
        _BUFFER_ACCESS_BLOCK_END,

        _STATE_VARS_BLOCK_BEGIN,
            AMGL_BLEND_COLOR,
            
            _BLEND_EQUATIONS_BLOCK_BEGIN,
                AMGL_FUNC_ADD, 
                AMGL_FUNC_SUBTRACT, 
                AMGL_FUNC_REVERSE_SUBTRACT, 
                AMGL_MIN, 
                AMGL_MAX,               
            _BLEND_EQUATIONS_BLOCK_END,

            _BLEND_FUNCS_BLOCK_BEGIN,
                AMGL_ZERO,
                AMGL_ONE,
                AMGL_SRC_COLOR, 
                AMGL_ONE_MINUS_SRC_COLOR, 
                AMGL_DST_COLOR, 
                AMGL_ONE_MINUS_DST_COLOR, 
                AMGL_SRC_ALPHA, 
                AMGL_ONE_MINUS_SRC_ALPHA, 
                AMGL_DST_ALPHA, 
                AMGL_ONE_MINUS_DST_ALPHA, 
                AMGL_CONSTANT_COLOR, 
                AMGL_ONE_MINUS_CONSTANT_COLOR, 
                AMGL_CONSTANT_ALPHA,
                AMGL_ONE_MINUS_CONSTANT_ALPHA,   
            _BLEND_FUNCS_BLOCK_END, 
            
            _DEPTH_FUNCS_BLOCK_BEGIN,
                AMGL_NEVER,
                AMGL_LESS,
                AMGL_EQUAL,
                AMGL_LEQUAL,
                AMGL_GREATER,
                AMGL_NOTEQUAL,
                AMGL_GEQUAL,
                AMGL_ALWAYS,
            _DEPTH_FUNCS_BLOCK_END,         

            _LOGIC_OPERATORS_BLOCK_BEGIN,
                AMGL_CLEAR,
                AMGL_SET,
                AMGL_COPY,
                AMGL_COPY_INVERTED,
                AMGL_NOOP,
                AMGL_INVERT,
                AMGL_AND,
                AMGL_NAND,
                AMGL_OR,
                AMGL_NOR,
                AMGL_XOR,
                AMGL_EQUIV,
                AMGL_AND_REVERSE,
                AMGL_AND_INVERTED,
                AMGL_OR_REVERSE,
                AMGL_OR_INVERTED, 
            _LOGIC_OPERATORS_BLOCK_END,

            _POLYGON_FACES_BLOCK_BEGIN,
                AMGL_FRONT,
                AMGL_BACK,
                AMGL_FRONT_AND_BACK,
            _POLYGON_FACES_BLOCK_END,

            _FRONT_FACE_ORIENTATIONS_BLOCK_BEGIN,
                AMGL_CW,
                AMGL_CCW,
            _FRONT_FACE_ORIENTATIONS_BLOCK_END,

            _POLYGONE_MODES_BLOCK_BEGIN,
                AMGL_POINT,
                AMGL_LINE,
                AMGL_FILL,
            _POLYGONE_MODES_BLOCK_END,

            _GLOBAL_STATE_VARS_BLOCK_BEGIN,
                AMGL_BLEND,
                AMGL_CLIP_DISTANCE0,
                AMGL_CLIP_DISTANCE1,
                AMGL_CLIP_DISTANCE2,
                AMGL_CLIP_DISTANCE3,
                AMGL_CLIP_DISTANCE4,
                AMGL_CLIP_DISTANCE5,
                AMGL_CLIP_DISTANCE6,
                AMGL_CLIP_DISTANCE7,
                AMGL_COLOR_LOGIC_OP,
                AMGL_CULL_FACE,
                AMGL_DEBUG_OUTPUT,
                AMGL_DEBUG_OUTPUT_SYNCHRONOUS,
                AMGL_DEPTH_CLAMP,
                AMGL_DEPTH_TEST,
                AMGL_DITHER,
                AMGL_FRAMEBUFFER_SRGB,
                AMGL_LINE_SMOOTH,
                AMGL_MULTISAMPLE,
                AMGL_POLYGON_OFFSET_FILL,
                AMGL_POLYGON_OFFSET_LINE,
                AMGL_POLYGON_OFFSET_POINT,
                AMGL_POLYGON_SMOOTH,
                AMGL_PRIMITIVE_RESTART,
                AMGL_PRIMITIVE_RESTART_FIXED_INDEX,
                AMGL_RASTERIZER_DISCARD,
                AMGL_SAMPLE_ALPHA_TO_COVERAGE,
                AMGL_SAMPLE_ALPHA_TO_ONE,
                AMGL_SAMPLE_COVERAGE,
                AMGL_SAMPLE_SHADING,
                AMGL_SAMPLE_MASK,
                AMGL_SCISSOR_TEST,
                AMGL_STENCIL_TEST,
                AMGL_TEXTURE_CUBE_MAP_SEAMLESS,
                AMGL_PROGRAM_POINT_SIZE,
            _GLOBAL_STATE_VARS_BLOCK_END,
        _STATE_VARS_BLOCK_END,
    };


#pragma region debug
    using debugproc = void (*)(enum_t source, enum_t type, uint32_t id, enum_t severity,
        uint64_t length, const char* message, const void* user_param);
#pragma endregion debug


#pragma region state management
    void blend_color(float red, float green, float blue, float alpha) noexcept;
    void blend_equation(enum_t mode) noexcept;
    void blend_equation_separate(enum_t mode_rgb, enum_t mode_alpha) noexcept;
    void blend_func(enum_t sfactor, enum_t dfactor) noexcept;
    void blend_func_separate(enum_t src_rgb, enum_t dst_rgb, enum_t src_alpha, enum_t dst_alpha) noexcept;
    
    void stencil_func(enum_t func, int32_t ref, uint32_t mask) noexcept;                                    // todo
    void stencil_func_separate(enum_t face, enum_t func, int32_t ref, uint32_t mask) noexcept;              // todo
    void stencil_mask(uint32_t mask) noexcept;                                                              // todo
    void stencil_mask_separate(enum_t face, uint32_t mask) noexcept;                                        // todo
    void stencil_op(enum_t sfail, enum_t dpfail, enum_t dppass) noexcept;                                   // todo
    void stencil_op_separate(enum_t face, enum_t sfail, enum_t dpfail, enum_t dppass) noexcept;             // todo
    
    void color_mask(bool red, bool green, bool blue, bool alpha) noexcept;
    void logic_op(enum_t opcode) noexcept;
    void cull_face(enum_t mode) noexcept;
    void front_face(enum_t mode) noexcept;
    void polygon_mode(enum_t face, enum_t mode) noexcept;

    void depth_func(enum_t func) noexcept;
    void depth_mask(bool flag) noexcept;
    void depth_range(float near, float far) noexcept;
    
    void enable(enum_t flag) noexcept;
    void disable(enum_t flag) noexcept;
    bool is_enabled(enum_t flag) noexcept;

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

    void scissor(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept;
    void viewport(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept;

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