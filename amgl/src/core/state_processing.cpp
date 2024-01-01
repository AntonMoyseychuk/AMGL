#include "pch.hpp"

#include "amgl_state.hpp"


namespace amgl
{   
    static amgl_state& gs_state = amgl_state::instance();


    static void _set_amgl_global_flag(enum_t flag, bool value) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_GLOBAL_STATE_VARS_BLOCK_BEGIN + 1, _GLOBAL_STATE_VARS_BLOCK_END - 1, flag)) {
            NOT_IMPLEMENTED_YET("Set invalid flag error. Push error message to queue, if debug layer is enable");
            return;
        }
        
        gs_state.state_flags.set(flag, value);
    }


    void blend_color(float red, float green, float blue, float alpha) noexcept
    {
        gs_state.blend_color.red = glm::clamp(red, 0.0f, 1.0f);
        gs_state.blend_color.green = glm::clamp(green, 0.0f, 1.0f);
        gs_state.blend_color.blue = glm::clamp(blue, 0.0f, 1.0f);
        gs_state.blend_color.alpha = glm::clamp(alpha, 0.0f, 1.0f);
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

        gs_state.blend_equation_rgb = mode_rgb;
        gs_state.blend_equation_alpha = mode_alpha;
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

        gs_state.blend_src_rgb = src_rgb;
        gs_state.blend_src_alpha = src_alpha;
        gs_state.blend_dst_rgb = dst_rgb;
        gs_state.blend_dst_alpha = dst_alpha;
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

        gs_state.logic_operator = opcode;
    }


    void color_mask(bool red, bool green, bool blue, bool alpha) noexcept
    {
        gs_state.color_mask.red = red;
        gs_state.color_mask.green = green;
        gs_state.color_mask.blue = blue;
        gs_state.color_mask.alpha = alpha;
    }


    void cull_face(enum_t mode) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_POLYGON_FACES_BLOCK_BEGIN + 1, _POLYGON_FACES_BLOCK_END - 1, mode)) {
            NOT_IMPLEMENTED_YET("Set invalid face culling mode error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_state.face_culling_mode = mode;
    }


    void front_face(enum_t mode) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_FRONT_FACE_ORIENTATIONS_BLOCK_BEGIN + 1, _FRONT_FACE_ORIENTATIONS_BLOCK_END - 1, mode)) {
            NOT_IMPLEMENTED_YET("Set invalid front face orientation mode error. Push error message to queue, if debug layer is enable");
            return;
        }

        gs_state.front_face_orientation_mode = mode;
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

        gs_state.polygon_mode = mode;
    }


    void depth_func(enum_t func) noexcept
    {
        if (!IN_INTERVAL_INCLUSIVE(_DEPTH_FUNCS_BLOCK_BEGIN + 1, _DEPTH_FUNCS_BLOCK_END - 1, func)) {
            NOT_IMPLEMENTED_YET("Set invalid depth func error. Push error message to queue, if debug layer is enable");
            return;
        }
        
        gs_state.depth_func = func;
    }


    void depth_mask(bool flag) noexcept
    {
        gs_state.depth_writing_enabled = flag;
    }


    void depth_range(float near, float far) noexcept
    {
        gs_state.depth_range.near = near;
        gs_state.depth_range.far = far;
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
        return gs_state.state_flags.get(flag);
    }


    void get_booleanv(enum_t pname, bool* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_booleanv(enum_t pname, bool* data) noexcept");
    }


    void get_doublev(enum_t pname, double* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_doublev(enum_t pname, double* data) noexcept");
    }


    void get_floatv(enum_t pname, float* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_floatv(enum_t pname, float* data) noexcept");
    }


    void get_integerv(enum_t pname, int32_t* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_integerv(enum_t pname, int32_t* data) noexcept");
    }


    void get_integer64v(enum_t pname, int64_t* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_integer64v(enum_t pname, int64_t* data) noexcept");
    }


    void get_booleani_v(enum_t target, uint32_t index, bool* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_booleani_v(enum_t target, uint32_t index, bool* data) noexcept");
    }


    void get_integeri_v(enum_t target, uint32_t index, int32_t* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_integeri_v(enum_t target, uint32_t index, int32_t* data) noexcept");
    }


    void get_floati_v(enum_t target, uint32_t index, float* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_floati_v(enum_t target, uint32_t index, float* data) noexcept");
    }


    void get_doublei_v(enum_t target, uint32_t index, double* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_doublei_v(enum_t target, uint32_t index, double* data) noexcept");
    }


    void get_integer64i_v(enum_t target, uint32_t index, int64_t* data) noexcept
    {
        NOT_IMPLEMENTED_YET("void get_integer64i_v(enum_t target, uint32_t index, int64_t* data) noexcept");
    }


    void scissor(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept
    {
        gs_state.scissor_rect.x = x;
        gs_state.scissor_rect.y = y;
        gs_state.scissor_rect.width = width;
        gs_state.scissor_rect.height = height;
    }


    void viewport(int32_t x, int32_t y, uint32_t width, uint32_t height) noexcept
    {
        gs_state.viewport_rect.x = x;
        gs_state.viewport_rect.y = y;
        gs_state.viewport_rect.width = width;
        gs_state.viewport_rect.height = height;
    }
}