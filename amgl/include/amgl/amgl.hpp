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
        AMGL_NONE = 0,
        AMGL_NO_ERROR = 0,
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

        _GLOBAL_STATE_FLAGS_BLOCK_BEGIN,
            AMGL_BLEND,
            AMGL_CLIP_DISTANCE0, // clip distances block begin
            AMGL_CLIP_DISTANCE1,
            AMGL_CLIP_DISTANCE2,
            AMGL_CLIP_DISTANCE3,
            AMGL_CLIP_DISTANCE4,
            AMGL_CLIP_DISTANCE5,
            AMGL_CLIP_DISTANCE6,
            AMGL_CLIP_DISTANCE7,
            AMGL_COLOR_LOGIC_OP, // clip distances block end
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
            AMGL_DEPTH_WRITEMASK,
            // AMGL_DOUBLEBUFFER,
        _GLOBAL_STATE_FLAGS_BLOCK_END,

        _GLOBAL_STATE_VARS_BLOCK_BEGIN,
            AMGL_ACTIVE_TEXTURE,
            AMGL_ALIASED_LINE_WIDTH_RANGE,
            AMGL_ARRAY_BUFFER_BINDING,
            AMGL_BLEND_COLOR,
            AMGL_BLEND_DST_ALPHA,
            AMGL_BLEND_DST_RGB,
            AMGL_BLEND_EQUATION_RGB,
            AMGL_BLEND_EQUATION_ALPHA,
            AMGL_BLEND_SRC_ALPHA,
            AMGL_BLEND_SRC_RGB,
            AMGL_COLOR_CLEAR_VALUE,
            AMGL_COLOR_WRITEMASK,
            AMGL_CURRENT_PROGRAM,
            AMGL_DEPTH_CLEAR_VALUE,
            AMGL_DEPTH_FUNC,
            AMGL_DEPTH_RANGE,
            AMGL_DRAW_BUFFER,
            AMGL_DRAW_BUFFER0,
            AMGL_DRAW_BUFFER1,
            AMGL_DRAW_BUFFER2,
            AMGL_DRAW_BUFFER3,
            AMGL_DRAW_BUFFER4,
            AMGL_DRAW_BUFFER5,
            AMGL_DRAW_BUFFER6,
            AMGL_DRAW_BUFFER7,
            AMGL_DRAW_BUFFER8,
            AMGL_DRAW_BUFFER9,
            AMGL_DRAW_BUFFER10,
            AMGL_DRAW_BUFFER11,
            AMGL_DRAW_BUFFER12,
            AMGL_DRAW_BUFFER13,
            AMGL_DRAW_BUFFER14,
            AMGL_DRAW_BUFFER15,
            AMGL_DRAW_FRAMEBUFFER_BINDING,
            AMGL_READ_FRAMEBUFFER_BINDING,
            AMGL_ELEMENT_ARRAY_BUFFER_BINDING,
            AMGL_FRAGMENT_SHADER_DERIVATIVE_HINT,
            AMGL_IMPLEMENTATION_COLOR_READ_FORMAT,
            AMGL_IMPLEMENTATION_COLOR_READ_TYPE,
            AMGL_LINE_SMOOTH_HINT,
            AMGL_LINE_WIDTH,
            AMGL_LAYER_PROVOKING_VERTEX,
            AMGL_LOGIC_OP_MODE,
            AMGL_MAX_3D_TEXTURE_SIZE,
            AMGL_MAX_ARRAY_TEXTURE_LAYERS,
            AMGL_MAX_CLIP_DISTANCES,
            AMGL_MAX_COLOR_TEXTURE_SAMPLES,
            AMGL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,
            AMGL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,
            AMGL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
            AMGL_MAX_COMBINED_UNIFORM_BLOCKS,
            AMGL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,
            AMGL_MAX_CUBE_MAP_TEXTURE_SIZE,
            AMGL_MAX_DEPTH_TEXTURE_SAMPLES,
            AMGL_MAX_DRAW_BUFFERS,
            AMGL_MAX_DUAL_SOURCE_DRAW_BUFFERS,
            AMGL_MAX_ELEMENTS_INDICES,
            AMGL_MAX_ELEMENTS_VERTICES,
            AMGL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS,
            AMGL_MAX_FRAGMENT_INPUT_COMPONENTS,
            AMGL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
            AMGL_MAX_FRAGMENT_UNIFORM_VECTORS,
            AMGL_MAX_FRAGMENT_UNIFORM_BLOCKS,
            AMGL_MAX_FRAMEBUFFER_WIDTH,
            AMGL_MAX_FRAMEBUFFER_HEIGHT,
            AMGL_MAX_FRAMEBUFFER_LAYERS,
            AMGL_MAX_FRAMEBUFFER_SAMPLES,
            AMGL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS,
            AMGL_MAX_GEOMETRY_INPUT_COMPONENTS,
            AMGL_MAX_GEOMETRY_OUTPUT_COMPONENTS,
            AMGL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,
            AMGL_MAX_GEOMETRY_UNIFORM_BLOCKS,
            AMGL_MAX_GEOMETRY_UNIFORM_COMPONENTS,
            AMGL_MAX_INTEGER_SAMPLES,
            AMGL_MIN_MAP_BUFFER_ALIGNMENT,
            AMGL_MAX_LABEL_LENGTH,
            AMGL_MAX_PROGRAM_TEXEL_OFFSET,
            AMGL_MIN_PROGRAM_TEXEL_OFFSET,
            AMGL_MAX_RECTANGLE_TEXTURE_SIZE,
            AMGL_MAX_RENDERBUFFER_SIZE,
            AMGL_MAX_SAMPLE_MASK_WORDS,
            AMGL_MAX_SHADER_STORAGE_BUFFER_BINDINGS,
            AMGL_MAX_TEXTURE_BUFFER_SIZE,
            AMGL_MAX_TEXTURE_IMAGE_UNITS,
            AMGL_MAX_TEXTURE_LOD_BIAS,
            AMGL_MAX_TEXTURE_SIZE,
            AMGL_MAX_UNIFORM_BUFFER_BINDINGS,
            AMGL_MAX_UNIFORM_BLOCK_SIZE,
            AMGL_MAX_UNIFORM_LOCATIONS,
            AMGL_MAX_VARYING_COMPONENTS,
            AMGL_MAX_VARYING_VECTORS,
            AMGL_MAX_VARYING_FLOATS,
            AMGL_MAX_VERTEX_ATTRIBS,
            AMGL_MAX_VERTEX_SHADER_STORAGE_BLOCKS,
            AMGL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
            AMGL_MAX_VERTEX_UNIFORM_COMPONENTS,
            AMGL_MAX_VERTEX_UNIFORM_VECTORS,
            AMGL_MAX_VERTEX_OUTPUT_COMPONENTS,
            AMGL_MAX_VERTEX_UNIFORM_BLOCKS,
            AMGL_MAX_VIEWPORT_DIMS,
            AMGL_PACK_ALIGNMENT,
            AMGL_PACK_IMAGE_HEIGHT,
            AMGL_PACK_LSB_FIRST,
            AMGL_PACK_ROW_LENGTH,
            AMGL_PIXEL_PACK_BUFFER_BINDING,
            AMGL_PIXEL_UNPACK_BUFFER_BINDING,
            AMGL_POINT_FADE_THRESHOLD_SIZE,
            AMGL_PROGRAM_PIPELINE_BINDING,
            AMGL_POINT_SIZE_GRANULARITY,
            AMGL_POINT_SIZE_RANGE,
            AMGL_POINT_SIZE,
            AMGL_POLYGON_OFFSET_FACTOR,
            AMGL_POLYGON_OFFSET_UNITS,
            AMGL_POLYGON_SMOOTH_HINT,
            AMGL_READ_BUFFER,
            AMGL_RENDERBUFFER_BINDING,
            AMGL_SAMPLE_BUFFERS,
            AMGL_SAMPLE_COVERAGE_VALUE,
            AMGL_SAMPLE_COVERAGE_INVERT,
            AMGL_SAMPLE_MASK_VALUE,
            AMGL_SAMPLER_BINDING,
            AMGL_SAMPLES,
            AMGL_SCISSOR_BOX,
            AMGL_SHADER_STORAGE_BUFFER_BINDING,
            AMGL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT,
            AMGL_SHADER_STORAGE_BUFFER_START,
            AMGL_SHADER_STORAGE_BUFFER_SIZE,
            AMGL_SMOOTH_LINE_WIDTH_RANGE,
            AMGL_SMOOTH_LINE_WIDTH_GRANULARITY,
            AMGL_STENCIL_BACK_FAIL,
            AMGL_STENCIL_BACK_FUNC,
            AMGL_STENCIL_BACK_PASS_DEPTH_FAIL,
            AMGL_STENCIL_BACK_PASS_DEPTH_PASS,
            AMGL_STENCIL_BACK_REF,
            AMGL_STENCIL_BACK_VALUE_MASK,
            AMGL_STENCIL_BACK_WRITEMASK,
            AMGL_STENCIL_CLEAR_VALUE,
            AMGL_STENCIL_FAIL,
            AMGL_STENCIL_FUNC,
            AMGL_STENCIL_PASS_DEPTH_FAIL,
            AMGL_STENCIL_PASS_DEPTH_PASS,
            AMGL_STENCIL_REF,
            AMGL_STENCIL_VALUE_MASK,
            AMGL_STENCIL_WRITEMASK,
            AMGL_STEREO,
            AMGL_SUBPIXEL_BITS,
            AMGL_TEXTURE_BINDING_1D,
            AMGL_TEXTURE_BINDING_1D_ARRAY,
            AMGL_TEXTURE_BINDING_2D,
            AMGL_TEXTURE_BINDING_2D_ARRAY,
            AMGL_TEXTURE_BINDING_2D_MULTISAMPLE,
            AMGL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,
            AMGL_TEXTURE_BINDING_3D,
            AMGL_TEXTURE_BINDING_BUFFER,
            AMGL_TEXTURE_BINDING_CUBE_MAP,
            AMGL_TEXTURE_BINDING_RECTANGLE,
            AMGL_TEXTURE_COMPRESSION_HINT,
            AMGL_TEXTURE_BUFFER_OFFSET_ALIGNMENT,
            AMGL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
            AMGL_TRANSFORM_FEEDBACK_BUFFER_START,
            AMGL_TRANSFORM_FEEDBACK_BUFFER_SIZE,
            AMGL_UNIFORM_BUFFER_BINDING,
            AMGL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,
            AMGL_UNIFORM_BUFFER_SIZE,
            AMGL_UNIFORM_BUFFER_START,
            AMGL_UNPACK_ALIGNMENT,
            AMGL_UNPACK_IMAGE_HEIGHT,
            AMGL_UNPACK_LSB_FIRST,
            AMGL_UNPACK_ROW_LENGTH,
            AMGL_UNPACK_SKIP_IMAGES,
            AMGL_UNPACK_SKIP_PIXELS,
            AMGL_UNPACK_SKIP_ROWS,
            AMGL_UNPACK_SWAP_BYTES,
            AMGL_VERTEX_ARRAY_BINDING,
            AMGL_VERTEX_BINDING_DIVISOR,
            AMGL_VERTEX_BINDING_OFFSET,
            AMGL_VERTEX_BINDING_STRIDE,
            AMGL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET,
            AMGL_MAX_VERTEX_ATTRIB_BINDINGS,
            AMGL_VIEWPORT,
            AMGL_VIEWPORT_BOUNDS_RANGE,
            AMGL_VIEWPORT_INDEX_PROVOKING_VERTEX,
            AMGL_VIEWPORT_SUBPIXEL_BITS,
            AMGL_MAX_ELEMENT_INDEX,
        _GLOBAL_STATE_VARS_BLOCK_END,

        _TEXTURE_UNITS_BLOCK_BEGIN,
            AMGL_TEXTURE0,
            AMGL_TEXTURE1,
            AMGL_TEXTURE2,
            AMGL_TEXTURE3,
            AMGL_TEXTURE4,
            AMGL_TEXTURE5,
            AMGL_TEXTURE6,
            AMGL_TEXTURE7,
            AMGL_TEXTURE8,
            AMGL_TEXTURE9,
            AMGL_TEXTURE10,
            AMGL_TEXTURE11,
            AMGL_TEXTURE12,
            AMGL_TEXTURE13,
            AMGL_TEXTURE14,
            AMGL_TEXTURE15,
            AMGL_TEXTURE16,
            AMGL_TEXTURE17,
            AMGL_TEXTURE18,
            AMGL_TEXTURE19,
            AMGL_TEXTURE20,
            AMGL_TEXTURE21,
            AMGL_TEXTURE22,
            AMGL_TEXTURE23,
            AMGL_TEXTURE24,
            AMGL_TEXTURE25,
            AMGL_TEXTURE26,
            AMGL_TEXTURE27,
            AMGL_TEXTURE28,
            AMGL_TEXTURE29,
            AMGL_TEXTURE30,
            AMGL_TEXTURE31,
        _TEXTURE_UNITS_BLOCK_END,
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