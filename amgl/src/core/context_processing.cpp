#include "pch.hpp"
#include "context.hpp"


namespace amgl
{   
    static context& gs_context = context::instance();

    // todo: merge different vars to duitable get_* functions
    template <typename T>
    static void _get_state_variable(enum_t pname, int32_t index, T* data) noexcept
    {
        if (data == nullptr) {
            return;
        }

        switch(pname) {
            case AMGL_ACTIVE_TEXTURE:
                *data = gs_context.active_texture_unit;
                return;
            case AMGL_ALIASED_LINE_WIDTH_RANGE:
                NOT_IMPLEMENTED_YET("AMGL_ALIASED_LINE_WIDTH_RANGE");
                return;
            case AMGL_ARRAY_BUFFER_BINDING:
                *data = gs_context.binded_buffers.vbo;
                return;
            case AMGL_BLEND:
                *data = gs_context.state_flags.get(AMGL_BLEND);
                return;
            case AMGL_BLEND_COLOR:
                data[0] = (T)gs_context.blend_color.red;
                data[1] = (T)gs_context.blend_color.green;
                data[2] = (T)gs_context.blend_color.blue;
                data[3] = (T)gs_context.blend_color.alpha;
                return;
            case AMGL_BLEND_DST_ALPHA:
                *data = gs_context.blend_dst_alpha;
                return;
            case AMGL_BLEND_DST_RGB:
                *data = gs_context.blend_dst_rgb;
                return;
            case AMGL_BLEND_EQUATION_RGB:
                *data = gs_context.blend_equation_rgb;
                return;
            case AMGL_BLEND_EQUATION_ALPHA:
                *data = gs_context.blend_equation_alpha;
                return;
            case AMGL_BLEND_SRC_ALPHA:
                *data = gs_context.blend_src_alpha;
                return;
            case AMGL_BLEND_SRC_RGB:
                *data = gs_context.blend_src_rgb;
                return;
            case AMGL_COLOR_CLEAR_VALUE:
                data[0] = (T)gs_context.clear_color.red;
                data[1] = (T)gs_context.clear_color.green;
                data[2] = (T)gs_context.clear_color.blue;
                data[3] = (T)gs_context.clear_color.alpha;
                return;
            case AMGL_COLOR_LOGIC_OP:
                *data = gs_context.state_flags.get(AMGL_COLOR_LOGIC_OP);
                return;
            case AMGL_COLOR_WRITEMASK:
                data[0] = (T)gs_context.color_mask.red;
                data[1] = (T)gs_context.color_mask.green;
                data[2] = (T)gs_context.color_mask.blue;
                data[3] = (T)gs_context.color_mask.alpha;
                return;
            case AMGL_CULL_FACE:
                *data = gs_context.state_flags.get(AMGL_CULL_FACE);
                return;
            case AMGL_CURRENT_PROGRAM:
                *data = gs_context.shader_program;
                return;
            case AMGL_DEPTH_CLEAR_VALUE:
                *data = (T)gs_context.depth_clear_value;
                return;
            case AMGL_DEPTH_FUNC:
                *data = gs_context.depth_func;
                return;
            case AMGL_DEPTH_RANGE:
                data[0] = (T)gs_context.depth_range.near;
                data[1] = (T)gs_context.depth_range.far;
                return;
            case AMGL_DEPTH_TEST:
                *data = gs_context.state_flags.get(AMGL_DEPTH_TEST);
                return;
            case AMGL_DEPTH_WRITEMASK:
                *data = gs_context.state_flags.get(AMGL_DEPTH_WRITEMASK);
                return;
            case AMGL_DITHER:
                *data = gs_context.state_flags.get(AMGL_DITHER);
                return;
            case AMGL_DRAW_BUFFER:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER");
                return;
            case AMGL_DRAW_BUFFER0:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER0");
                return;
            case AMGL_DRAW_BUFFER1:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER1");
                return;
            case AMGL_DRAW_BUFFER2:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER2");
                return;
            case AMGL_DRAW_BUFFER3:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER3");
                return;
            case AMGL_DRAW_BUFFER4:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER4");
                return;
            case AMGL_DRAW_BUFFER5:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER5");
                return;
            case AMGL_DRAW_BUFFER6:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER6");
                return;
            case AMGL_DRAW_BUFFER7:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER7");
                return;
            case AMGL_DRAW_BUFFER8:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER8");
                return;
            case AMGL_DRAW_BUFFER9:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER9");
                return;
            case AMGL_DRAW_BUFFER10:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER10");
                return;
            case AMGL_DRAW_BUFFER11:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER11");
                return;
            case AMGL_DRAW_BUFFER12:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER12");
                return;
            case AMGL_DRAW_BUFFER13:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER13");
                return;
            case AMGL_DRAW_BUFFER14:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER14");
                return;
            case AMGL_DRAW_BUFFER15:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_BUFFER15");
                return;
            case AMGL_DRAW_FRAMEBUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_DRAW_FRAMEBUFFER_BINDING");
                return;
            case AMGL_READ_FRAMEBUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_READ_FRAMEBUFFER_BINDING");
                return;
            case AMGL_ELEMENT_ARRAY_BUFFER_BINDING:
                *data = gs_context.binded_buffers.ebo;
                return;
            case AMGL_FRAGMENT_SHADER_DERIVATIVE_HINT:
                NOT_IMPLEMENTED_YET("AMGL_FRAGMENT_SHADER_DERIVATIVE_HINT");
                return;
            case AMGL_IMPLEMENTATION_COLOR_READ_FORMAT:
                NOT_IMPLEMENTED_YET("AMGL_IMPLEMENTATION_COLOR_READ_FORMAT");
                return;
            case AMGL_IMPLEMENTATION_COLOR_READ_TYPE:
                NOT_IMPLEMENTED_YET("AMGL_IMPLEMENTATION_COLOR_READ_TYPE");
                return;
            case AMGL_LINE_SMOOTH:
                *data = gs_context.state_flags.get(AMGL_LINE_SMOOTH);
                return;
            case AMGL_LINE_SMOOTH_HINT:
                NOT_IMPLEMENTED_YET("AMGL_LINE_SMOOTH_HINT");
                return;
            case AMGL_LINE_WIDTH:
                *data = (T)gs_context.line_width;
                return;
            case AMGL_LAYER_PROVOKING_VERTEX:
                NOT_IMPLEMENTED_YET("AMGL_LAYER_PROVOKING_VERTEX");
                return;
            case AMGL_LOGIC_OP_MODE:
                *data = gs_context.logic_op_mode;
                return;
            case AMGL_MAX_3D_TEXTURE_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_3D_TEXTURE_SIZE");
                return;
            case AMGL_MAX_ARRAY_TEXTURE_LAYERS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_ARRAY_TEXTURE_LAYERS");
                return;
            case AMGL_MAX_CLIP_DISTANCES:
                *data = (T)gs_context.CLIP_DISTANCES_COUNT;
                return;
            case AMGL_MAX_COLOR_TEXTURE_SAMPLES:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COLOR_TEXTURE_SAMPLES");
                return;
            case AMGL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_COMBINED_TEXTURE_IMAGE_UNITS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COMBINED_TEXTURE_IMAGE_UNITS");
                return;
            case AMGL_MAX_COMBINED_UNIFORM_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COMBINED_UNIFORM_BLOCKS");
                return;
            case AMGL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_CUBE_MAP_TEXTURE_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_DEPTH_TEXTURE_SAMPLES:
                NOT_IMPLEMENTED_YET("AMGL_MAX_DEPTH_TEXTURE_SAMPLES");
                return;
            case AMGL_MAX_DRAW_BUFFERS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_DRAW_BUFFERS");
                return;
            case AMGL_MAX_DUAL_SOURCE_DRAW_BUFFERS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_DUAL_SOURCE_DRAW_BUFFERS");
                return;
            case AMGL_MAX_ELEMENTS_INDICES:
                NOT_IMPLEMENTED_YET("AMGL_MAX_ELEMENTS_INDICES");
                return;
            case AMGL_MAX_ELEMENTS_VERTICES:
                NOT_IMPLEMENTED_YET("AMGL_MAX_ELEMENTS_VERTICES");
                return;
            case AMGL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS");
                return;
            case AMGL_MAX_FRAGMENT_INPUT_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAGMENT_INPUT_COMPONENTS");
                return;
            case AMGL_MAX_FRAGMENT_UNIFORM_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAGMENT_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_FRAGMENT_UNIFORM_VECTORS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAGMENT_UNIFORM_VECTORS");
                return;
            case AMGL_MAX_FRAGMENT_UNIFORM_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAGMENT_UNIFORM_BLOCKS");
                return;
            case AMGL_MAX_FRAMEBUFFER_WIDTH:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAMEBUFFER_WIDTH");
                return;
            case AMGL_MAX_FRAMEBUFFER_HEIGHT:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAMEBUFFER_HEIGHT");
                return;
            case AMGL_MAX_FRAMEBUFFER_LAYERS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAMEBUFFER_LAYERS");
                return;
            case AMGL_MAX_FRAMEBUFFER_SAMPLES:
                NOT_IMPLEMENTED_YET("AMGL_MAX_FRAMEBUFFER_SAMPLES");
                return;
            case AMGL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS");
                return;
            case AMGL_MAX_GEOMETRY_INPUT_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_GEOMETRY_INPUT_COMPONENTS");
                return;
            case AMGL_MAX_GEOMETRY_OUTPUT_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_GEOMETRY_OUTPUT_COMPONENTS");
                return;
            case AMGL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS");
                return;
            case AMGL_MAX_GEOMETRY_UNIFORM_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_GEOMETRY_UNIFORM_BLOCKS");
                return;
            case AMGL_MAX_GEOMETRY_UNIFORM_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_GEOMETRY_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_INTEGER_SAMPLES:
                NOT_IMPLEMENTED_YET("AMGL_MAX_INTEGER_SAMPLES");
                return;
            case AMGL_MIN_MAP_BUFFER_ALIGNMENT:
                NOT_IMPLEMENTED_YET("AMGL_MIN_MAP_BUFFER_ALIGNMENT");
                return;
            case AMGL_MAX_LABEL_LENGTH:
                NOT_IMPLEMENTED_YET("AMGL_MAX_LABEL_LENGTH");
                return;
            case AMGL_MAX_PROGRAM_TEXEL_OFFSET:
                NOT_IMPLEMENTED_YET("AMGL_MAX_PROGRAM_TEXEL_OFFSET");
                return;
            case AMGL_MIN_PROGRAM_TEXEL_OFFSET:
                NOT_IMPLEMENTED_YET("AMGL_MIN_PROGRAM_TEXEL_OFFSET");
                return;
            case AMGL_MAX_RECTANGLE_TEXTURE_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_RECTANGLE_TEXTURE_SIZE");
                return;
            case AMGL_MAX_RENDERBUFFER_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_RENDERBUFFER_SIZE");
                return;
            case AMGL_MAX_SAMPLE_MASK_WORDS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_SAMPLE_MASK_WORDS");
                return;
            case AMGL_MAX_SHADER_STORAGE_BUFFER_BINDINGS:
                *data = (T)gs_context.MAX_SHADER_STORAGE_BUFFER_BINDINGS;
                return;
            case AMGL_MAX_TEXTURE_BUFFER_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_TEXTURE_BUFFER_SIZE");
                return;
            case AMGL_MAX_TEXTURE_IMAGE_UNITS:
                *data = (T)gs_context.MAX_FRAGMENT_TEXTURE_UNITS;
                return;
            case AMGL_MAX_TEXTURE_LOD_BIAS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_TEXTURE_LOD_BIAS");
                return;
            case AMGL_MAX_TEXTURE_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_TEXTURE_SIZE");
                return;
            case AMGL_MAX_UNIFORM_BUFFER_BINDINGS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_UNIFORM_BUFFER_BINDINGS");
                return;
            case AMGL_MAX_UNIFORM_BLOCK_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_MAX_UNIFORM_BLOCK_SIZE");
                return;
            case AMGL_MAX_UNIFORM_LOCATIONS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_UNIFORM_LOCATIONS");
                return;
            case AMGL_MAX_VARYING_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VARYING_COMPONENTS");
                return;
            case AMGL_MAX_VARYING_VECTORS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VARYING_VECTORS");
                return;
            case AMGL_MAX_VARYING_FLOATS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VARYING_FLOATS");
                return;
            case AMGL_MAX_VERTEX_ATTRIBS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_ATTRIBS");
                return;
            case AMGL_MAX_VERTEX_SHADER_STORAGE_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_SHADER_STORAGE_BLOCKS");
                return;
            case AMGL_MAX_VERTEX_TEXTURE_IMAGE_UNITS:
                *data = (T)gs_context.MAX_VERTEX_TEXTURE_UNITS;
                return;
            case AMGL_MAX_VERTEX_UNIFORM_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_UNIFORM_COMPONENTS");
                return;
            case AMGL_MAX_VERTEX_UNIFORM_VECTORS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_UNIFORM_VECTORS");
                return;
            case AMGL_MAX_VERTEX_OUTPUT_COMPONENTS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_OUTPUT_COMPONENTS");
                return;
            case AMGL_MAX_VERTEX_UNIFORM_BLOCKS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_UNIFORM_BLOCKS");
                return;
            case AMGL_MAX_VIEWPORT_DIMS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VIEWPORT_DIMS");
                return;
            case AMGL_PACK_ALIGNMENT:
                NOT_IMPLEMENTED_YET("AMGL_PACK_ALIGNMENT");
                return;
            case AMGL_PACK_IMAGE_HEIGHT:
                NOT_IMPLEMENTED_YET("AMGL_PACK_IMAGE_HEIGHT");
                return;
            case AMGL_PACK_LSB_FIRST:
                NOT_IMPLEMENTED_YET("AMGL_PACK_LSB_FIRST");
                return;
            case AMGL_PACK_ROW_LENGTH:
                NOT_IMPLEMENTED_YET("AMGL_PACK_ROW_LENGTH");
                return;
            case AMGL_PIXEL_PACK_BUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_PIXEL_PACK_BUFFER_BINDING");
                return;
            case AMGL_PIXEL_UNPACK_BUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_PIXEL_UNPACK_BUFFER_BINDING");
                return;
            case AMGL_POINT_FADE_THRESHOLD_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_POINT_FADE_THRESHOLD_SIZE");
                return;
            case AMGL_PROGRAM_PIPELINE_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_PROGRAM_PIPELINE_BINDING");
                return;
            case AMGL_PROGRAM_POINT_SIZE:
                *data = gs_context.state_flags.get(AMGL_PROGRAM_POINT_SIZE);
                return;
            case AMGL_POINT_SIZE:
                *data = (T)gs_context.point_size;
                return;
            case AMGL_POINT_SIZE_GRANULARITY:
                NOT_IMPLEMENTED_YET("AMGL_POINT_SIZE_GRANULARITY");
                return;
            case AMGL_POINT_SIZE_RANGE:
                NOT_IMPLEMENTED_YET("AMGL_POINT_SIZE_RANGE");
                return;
            case AMGL_POLYGON_OFFSET_FACTOR:
                NOT_IMPLEMENTED_YET("AMGL_POLYGON_OFFSET_FACTOR");
                return;
            case AMGL_POLYGON_OFFSET_UNITS:
                NOT_IMPLEMENTED_YET("AMGL_POLYGON_OFFSET_UNITS");
                return;
            case AMGL_POLYGON_SMOOTH:
                *data = gs_context.state_flags.get(AMGL_POLYGON_SMOOTH);
                return;
            case AMGL_POLYGON_SMOOTH_HINT:
                NOT_IMPLEMENTED_YET("AMGL_POLYGON_SMOOTH_HINT");
                return;
            case AMGL_READ_BUFFER:
                NOT_IMPLEMENTED_YET("AMGL_READ_BUFFER");
                return;
            case AMGL_RENDERBUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_RENDERBUFFER_BINDING");
                return;
            case AMGL_SAMPLE_BUFFERS:
                NOT_IMPLEMENTED_YET("AMGL_SAMPLE_BUFFERS");
                return;
            case AMGL_SAMPLE_COVERAGE_VALUE:
                NOT_IMPLEMENTED_YET("AMGL_SAMPLE_COVERAGE_VALUE");
                return;
            case AMGL_SAMPLE_COVERAGE_INVERT:
                NOT_IMPLEMENTED_YET("AMGL_SAMPLE_COVERAGE_INVERT");
                return;
            case AMGL_SAMPLE_MASK_VALUE:
                NOT_IMPLEMENTED_YET("AMGL_SAMPLE_MASK_VALUE");
                return;
            case AMGL_SAMPLER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_SAMPLER_BINDING");
                return;
            case AMGL_SAMPLES:
                NOT_IMPLEMENTED_YET("AMGL_SAMPLES");
                return;
            case AMGL_SCISSOR_BOX:
                data[0] = (T)gs_context.scissor_rect.x;
                data[1] = (T)gs_context.scissor_rect.y;
                data[2] = (T)gs_context.scissor_rect.width;
                data[3] = (T)gs_context.scissor_rect.height;
                return;
            case AMGL_SHADER_STORAGE_BUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_SHADER_STORAGE_BUFFER_BINDING");
                return;
            case AMGL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT:
                NOT_IMPLEMENTED_YET("AMGL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT");
                return;
            case AMGL_SHADER_STORAGE_BUFFER_START:
                NOT_IMPLEMENTED_YET("AMGL_SHADER_STORAGE_BUFFER_START");
                return;
            case AMGL_SHADER_STORAGE_BUFFER_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_SHADER_STORAGE_BUFFER_SIZE");
                return;
            case AMGL_SMOOTH_LINE_WIDTH_RANGE:
                NOT_IMPLEMENTED_YET("AMGL_SMOOTH_LINE_WIDTH_RANGE");
                return;
            case AMGL_SMOOTH_LINE_WIDTH_GRANULARITY:
                NOT_IMPLEMENTED_YET("AMGL_SMOOTH_LINE_WIDTH_GRANULARITY");
                return;
            case AMGL_STENCIL_TEST:
                *data = gs_context.state_flags.get(AMGL_STENCIL_TEST);
                return;
            case AMGL_STENCIL_BACK_FAIL:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_FAIL");
                return;
            case AMGL_STENCIL_BACK_FUNC:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_FUNC");
                return;
            case AMGL_STENCIL_BACK_PASS_DEPTH_FAIL:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_PASS_DEPTH_FAIL");
                return;
            case AMGL_STENCIL_BACK_PASS_DEPTH_PASS:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_PASS_DEPTH_PASS");
                return;
            case AMGL_STENCIL_BACK_REF:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_REF");
                return;
            case AMGL_STENCIL_BACK_VALUE_MASK:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_VALUE_MASK");
                return;
            case AMGL_STENCIL_BACK_WRITEMASK:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_BACK_WRITEMASK");
                return;
            case AMGL_STENCIL_CLEAR_VALUE:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_CLEAR_VALUE");
                return;
            case AMGL_STENCIL_FAIL:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_FAIL");
                return;
            case AMGL_STENCIL_FUNC:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_FUNC");
                return;
            case AMGL_STENCIL_PASS_DEPTH_FAIL:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_PASS_DEPTH_FAIL");
                return;
            case AMGL_STENCIL_PASS_DEPTH_PASS:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_PASS_DEPTH_PASS");
                return;
            case AMGL_STENCIL_REF:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_REF");
                return;
            case AMGL_STENCIL_VALUE_MASK:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_VALUE_MASK");
                return;
            case AMGL_STENCIL_WRITEMASK:
                NOT_IMPLEMENTED_YET("AMGL_STENCIL_WRITEMASK");
                return;
            case AMGL_STEREO:
                NOT_IMPLEMENTED_YET("AMGL_STEREO");
                return;
            case AMGL_SUBPIXEL_BITS:
                NOT_IMPLEMENTED_YET("AMGL_SUBPIXEL_BITS");
                return;
            case AMGL_TEXTURE_BINDING_1D:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_1D");
                return;
            case AMGL_TEXTURE_BINDING_1D_ARRAY:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_1D_ARRAY");
                return;
            case AMGL_TEXTURE_BINDING_2D:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_2D");
                return;
            case AMGL_TEXTURE_BINDING_2D_ARRAY:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_2D_ARRAY");
                return;
            case AMGL_TEXTURE_BINDING_2D_MULTISAMPLE:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_2D_MULTISAMPLE");
                return;
            case AMGL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY");
                return;
            case AMGL_TEXTURE_BINDING_3D:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_3D");
                return;
            case AMGL_TEXTURE_BINDING_BUFFER:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_BUFFER");
                return;
            case AMGL_TEXTURE_BINDING_CUBE_MAP:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_CUBE_MAP");
                return;
            case AMGL_TEXTURE_BINDING_RECTANGLE:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BINDING_RECTANGLE");
                return;
            case AMGL_TEXTURE_COMPRESSION_HINT:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_COMPRESSION_HINT");
                return;
            case AMGL_TEXTURE_BUFFER_OFFSET_ALIGNMENT:
                NOT_IMPLEMENTED_YET("AMGL_TEXTURE_BUFFER_OFFSET_ALIGNMENT");
                return;
            case AMGL_TRANSFORM_FEEDBACK_BUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_TRANSFORM_FEEDBACK_BUFFER_BINDING");
                return;
            case AMGL_TRANSFORM_FEEDBACK_BUFFER_START:
                NOT_IMPLEMENTED_YET("AMGL_TRANSFORM_FEEDBACK_BUFFER_START");
                return;
            case AMGL_TRANSFORM_FEEDBACK_BUFFER_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_TRANSFORM_FEEDBACK_BUFFER_SIZE");
                return;
            case AMGL_UNIFORM_BUFFER_BINDING:
                NOT_IMPLEMENTED_YET("AMGL_UNIFORM_BUFFER_BINDING");
                return;
            case AMGL_UNIFORM_BUFFER_OFFSET_ALIGNMENT:
                NOT_IMPLEMENTED_YET("AMGL_UNIFORM_BUFFER_OFFSET_ALIGNMENT");
                return;
            case AMGL_UNIFORM_BUFFER_SIZE:
                NOT_IMPLEMENTED_YET("AMGL_UNIFORM_BUFFER_SIZE");
                return;
            case AMGL_UNIFORM_BUFFER_START:
                NOT_IMPLEMENTED_YET("AMGL_UNIFORM_BUFFER_START");
                return;
            case AMGL_UNPACK_ALIGNMENT:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_ALIGNMENT");
                return;
            case AMGL_UNPACK_IMAGE_HEIGHT:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_IMAGE_HEIGHT");
                return;
            case AMGL_UNPACK_LSB_FIRST:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_LSB_FIRST");
                return;
            case AMGL_UNPACK_ROW_LENGTH:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_ROW_LENGTH");
                return;
            case AMGL_UNPACK_SKIP_IMAGES:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_SKIP_IMAGES");
                return;
            case AMGL_UNPACK_SKIP_PIXELS:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_SKIP_PIXELS");
                return;
            case AMGL_UNPACK_SKIP_ROWS:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_SKIP_ROWS");
                return;
            case AMGL_UNPACK_SWAP_BYTES:
                NOT_IMPLEMENTED_YET("AMGL_UNPACK_SWAP_BYTES");
                return;
            case AMGL_VERTEX_ARRAY_BINDING:
                *data = gs_context.binded_buffers.vao;
                return;
            case AMGL_VERTEX_BINDING_DIVISOR:
                NOT_IMPLEMENTED_YET("AMGL_VERTEX_BINDING_DIVISOR");
                return;
            case AMGL_VERTEX_BINDING_OFFSET:
                NOT_IMPLEMENTED_YET("AMGL_VERTEX_BINDING_OFFSET");
                return;
            case AMGL_VERTEX_BINDING_STRIDE:
                NOT_IMPLEMENTED_YET("AMGL_VERTEX_BINDING_STRIDE");
                return;
            case AMGL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET");
                return;
            case AMGL_MAX_VERTEX_ATTRIB_BINDINGS:
                NOT_IMPLEMENTED_YET("AMGL_MAX_VERTEX_ATTRIB_BINDINGS");
                return;
            case AMGL_VIEWPORT:
                data[0] = (T)gs_context.viewport_rect.x;
                data[1] = (T)gs_context.viewport_rect.y;
                data[2] = (T)gs_context.viewport_rect.width;
                data[3] = (T)gs_context.viewport_rect.height;
                return;
            case AMGL_VIEWPORT_BOUNDS_RANGE:
                NOT_IMPLEMENTED_YET("AMGL_VIEWPORT_BOUNDS_RANGE");
                return;
            case AMGL_VIEWPORT_INDEX_PROVOKING_VERTEX:
                NOT_IMPLEMENTED_YET("AMGL_VIEWPORT_INDEX_PROVOKING_VERTEX");
                return;
            case AMGL_VIEWPORT_SUBPIXEL_BITS:
                NOT_IMPLEMENTED_YET("AMGL_VIEWPORT_SUBPIXEL_BITS");
                return;
            case AMGL_MAX_ELEMENT_INDEX:
                NOT_IMPLEMENTED_YET("AMGL_MAX_ELEMENT_INDEX");
                return;
            default:
                NOT_IMPLEMENTED_YET("Set invalid pname error. Push error message to queue, if debug layer is enable");
                return;
        }
    }


    static void _set_amgl_global_flag(enum_t flag, bool value) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_GLOBAL_STATE_FLAGS_BLOCK_BEGIN + 1, _GLOBAL_STATE_FLAGS_BLOCK_END - 1, flag)) {
            NOT_IMPLEMENTED_YET("Set invalid flag error. Push error message to queue, if debug layer is enable");
            return;
        }
        
        gs_context.state_flags.set(flag, value);
    }


    void blend_color(float red, float green, float blue, float alpha) noexcept
    {
        gs_context.blend_color.red = glm::clamp(red, 0.0f, 1.0f);
        gs_context.blend_color.green = glm::clamp(green, 0.0f, 1.0f);
        gs_context.blend_color.blue = glm::clamp(blue, 0.0f, 1.0f);
        gs_context.blend_color.alpha = glm::clamp(alpha, 0.0f, 1.0f);
    }


    void blend_equation(enum_t mode) noexcept
    {
        blend_equation_separate(mode, mode);
    }


    void blend_equation_separate(enum_t mode_rgb, enum_t mode_alpha) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_BLEND_EQUATIONS_BLOCK_BEGIN + 1, _BLEND_EQUATIONS_BLOCK_END - 1, mode_rgb)) {
            NOT_IMPLEMENTED_YET("Set invalid rgb blend equation func error. Push error message to queue, if debug layer is enable");
            return;
        }

        if (!IN_INTERVAL_INCLUSIVE(_BLEND_EQUATIONS_BLOCK_BEGIN + 1, _BLEND_EQUATIONS_BLOCK_END - 1, mode_alpha)) {
            NOT_IMPLEMENTED_YET("Set invalid alpha blend equation func error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_context.blend_equation_rgb = mode_rgb;
        gs_context.blend_equation_alpha = mode_alpha;
    }


    void blend_func(enum_t sfactor, enum_t dfactor) noexcept
    {
        blend_func_separate(sfactor, sfactor, dfactor, dfactor);
    }


    void blend_func_separate(enum_t src_rgb, enum_t dst_rgb, enum_t src_alpha, enum_t dst_alpha) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_BLEND_FUNCS_BLOCK_BEGIN + 1, _BLEND_FUNCS_BLOCK_END - 1, src_rgb)) {
            NOT_IMPLEMENTED_YET("Set invalid src_rgb blend func error. Push error message to queue, if debug layer is enable");
            return;
        }

        if (!IN_INTERVAL_INCLUSIVE(_BLEND_FUNCS_BLOCK_BEGIN + 1, _BLEND_FUNCS_BLOCK_END - 1, dst_rgb)) {
            NOT_IMPLEMENTED_YET("Set invalid dst_rgb blend func error. Push error message to queue, if debug layer is enable");
            return;
        }

        if (!IN_INTERVAL_INCLUSIVE(_BLEND_FUNCS_BLOCK_BEGIN + 1, _BLEND_FUNCS_BLOCK_END - 1, src_alpha)) {
            NOT_IMPLEMENTED_YET("Set invalid src_alpha blend func error. Push error message to queue, if debug layer is enable");
            return;
        }

        if (!IN_INTERVAL_INCLUSIVE(_BLEND_FUNCS_BLOCK_BEGIN + 1, _BLEND_FUNCS_BLOCK_END - 1, dst_alpha)) {
            NOT_IMPLEMENTED_YET("Set invalid dst_alpha blend func error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_context.blend_src_rgb = src_rgb;
        gs_context.blend_src_alpha = src_alpha;
        gs_context.blend_dst_rgb = dst_rgb;
        gs_context.blend_dst_alpha = dst_alpha;
    }

    
    void stencil_func(enum_t func, int32_t ref, uint32_t mask) noexcept
    {
        NOT_IMPLEMENTED_YET("void stencil_func(enum_t func, int32_t ref, uint32_t mask) noexcept");
    }


    void stencil_func_separate(enum_t face, enum_t func, int32_t ref, uint32_t mask) noexcept
    {
        NOT_IMPLEMENTED_YET("void stencil_func_separate(enum_t face, enum_t func, int32_t ref, uint32_t mask) noexcept");
    }


    void stencil_mask(uint32_t mask) noexcept
    {
        NOT_IMPLEMENTED_YET("void stencil_mask(uint32_t mask) noexcept");
    }


    void stencil_mask_separate(enum_t face, uint32_t mask) noexcept
    {
        NOT_IMPLEMENTED_YET("void stencil_mask_separate(enum_t face, uint32_t mask) noexcept");
    }


    void stencil_op(enum_t sfail, enum_t dpfail, enum_t dppass) noexcept
    {
        NOT_IMPLEMENTED_YET("void stencil_op(enum_t sfail, enum_t dpfail, enum_t dppass) noexcept");
    }


    void stencil_op_separate(enum_t face, enum_t sfail, enum_t dpfail, enum_t dppass) noexcept
    {
        NOT_IMPLEMENTED_YET("void stencil_op_separate(enum_t face, enum_t sfail, enum_t dpfail, enum_t dppass) noexcept");
    }
    

    void logic_op(enum_t opcode) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_LOGIC_OPERATORS_BLOCK_BEGIN + 1, _LOGIC_OPERATORS_BLOCK_END - 1, opcode)) {
            NOT_IMPLEMENTED_YET("Set invalid logic operator error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_context.logic_op_mode = opcode;
    }


    void color_mask(bool red, bool green, bool blue, bool alpha) noexcept
    {
        gs_context.color_mask.red = red;
        gs_context.color_mask.green = green;
        gs_context.color_mask.blue = blue;
        gs_context.color_mask.alpha = alpha;
    }


    void cull_face(enum_t mode) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_POLYGON_FACES_BLOCK_BEGIN + 1, _POLYGON_FACES_BLOCK_END - 1, mode)) {
            NOT_IMPLEMENTED_YET("Set invalid face culling mode error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_context.face_culling_mode = mode;
    }


    void front_face(enum_t mode) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_FRONT_FACE_ORIENTATIONS_BLOCK_BEGIN + 1, _FRONT_FACE_ORIENTATIONS_BLOCK_END - 1, mode)) {
            NOT_IMPLEMENTED_YET("Set invalid front face orientation mode error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_context.front_face_orientation_mode = mode;
    }


    void polygon_mode(enum_t face, enum_t mode) noexcept
    {
        if (face != AMGL_FRONT_AND_BACK) {
            NOT_IMPLEMENTED_YET("Set invalid face error. Push error message to queue, if debug layer is enable");
            return;
        }

        if (!IN_INTERVAL_INCLUSIVE(_POLYGONE_MODES_BLOCK_BEGIN + 1, _POLYGONE_MODES_BLOCK_END - 1, mode)) {
            NOT_IMPLEMENTED_YET("Set invalid polygon mode error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_context.polygon_mode = mode;
    }


    void depth_func(enum_t func) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_DEPTH_FUNCS_BLOCK_BEGIN + 1, _DEPTH_FUNCS_BLOCK_END - 1, func)) {
            NOT_IMPLEMENTED_YET("Set invalid depth func error. Push error message to queue, if debug layer is enable");
            return;
        }
        
        gs_context.depth_func = func;
    }


    void depth_mask(bool flag) noexcept
    {
        gs_context.state_flags.set(AMGL_DEPTH_WRITEMASK, flag);
    }


    void depth_range(float near, float far) noexcept
    {
        gs_context.depth_range.near = near;
        gs_context.depth_range.far = far;
    }

    
    void enable(enum_t flag) noexcept
    {
        _set_amgl_global_flag(flag, true);
    }


    void disable(enum_t flag) noexcept
    {
        _set_amgl_global_flag(flag, false);
    }


    bool is_enabled(enum_t flag) noexcept
    {
        return gs_context.state_flags.get(flag);
    }


    void scissor(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept
    {
        gs_context.scissor_rect.x = x;
        gs_context.scissor_rect.y = y;
        gs_context.scissor_rect.width = width;
        gs_context.scissor_rect.height = height;
    }


    void viewport(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept
    {
        gs_context.viewport_rect.x = x;
        gs_context.viewport_rect.y = y;
        gs_context.viewport_rect.width = width;
        gs_context.viewport_rect.height = height;
    }


    void get_booleanv(enum_t pname, bool* data) noexcept
    {
        _get_state_variable(pname, 0, data);
    }


    void get_doublev(enum_t pname, double* data) noexcept
    {
        _get_state_variable(pname, 0, data);
    }


    void get_floatv(enum_t pname, float* data) noexcept
    {
        _get_state_variable(pname, 0, data);
    }


    void get_integerv(enum_t pname, int32_t* data) noexcept
    {
        _get_state_variable(pname, 0, data);
    }


    void get_integer64v(enum_t pname, int64_t* data) noexcept
    {
        _get_state_variable(pname, 0, data);
    }


    void get_booleani_v(enum_t target, uint32_t index, bool* data) noexcept
    {
        _get_state_variable(target, index, data);
    }


    void get_integeri_v(enum_t target, uint32_t index, int32_t* data) noexcept
    {
        _get_state_variable(target, index, data);
    }


    void get_floati_v(enum_t target, uint32_t index, float* data) noexcept
    {
        _get_state_variable(target, index, data);
    }


    void get_doublei_v(enum_t target, uint32_t index, double* data) noexcept
    {
        _get_state_variable(target, index, data);
    }


    void get_integer64i_v(enum_t target, uint32_t index, int64_t* data) noexcept
    {
        _get_state_variable(target, index, data);
    }
}