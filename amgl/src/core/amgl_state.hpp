#pragma once

#include "amgl/amgl.hpp"

namespace amgl
{
    class amgl_state
    {
    public:
        static amgl_state& instance() noexcept
        {
            static amgl_state state;
            return state;
        }

        amgl_state(const amgl_state& state) = delete;
        amgl_state& operator=(const amgl_state& state) = delete;

    private:
        amgl_state() = default;

    private:
        struct depth_range_t
        {
            float near = 0.0f;
            float far = 1.0f;
        };

        struct color_mask_t
        {
            bool red = true;
            bool green = true;
            bool blue = true;
            bool alpha = true;
        };

        struct rect_t
        {
            int32_t x = 0;
            int32_t y = 0;
            uint32_t width = 0u;
            uint32_t height = 0u;
        };

        struct color_t
        {
            float red = 0.0f;
            float green = 0.0f;
            float blue = 0.0f;
            float alpha = 0.0f;
        };

        struct binded_buffers_t
        {
            id_t vao = 0;   // binded vertex array object
            id_t vbo = 0;   // binded vertex buffer object
            id_t ebo = 0;   // binded element buffer object
            id_t cwbo = 0;  // copy write buffer object
            id_t crbo = 0;  // copy read buffer object
            id_t ssbo = 0;  // shader storage buffer object
            id_t ubo = 0;   // uniform buffer object
        };

        template <size_t flags_count, size_t first>
        class flags_t
        {
            static_assert(flags_count > 0, "");

            using mask_t = std::bitset<flags_count>;

        public:
            void set(enum_t flag, bool value) noexcept
            {
                flags.set(get_bit_number(flag), value);
            }

            bool get(enum_t flag) const noexcept
            {
                return flags.test(get_bit_number(flag));
            }

        private:
            static inline constexpr size_t get_bit_number(enum_t flag) noexcept
            { 
                AM_ASSERT_MSG(flag < first + flags_count, "Invalid flag value");
                return flag - first;
            }

            static inline constexpr mask_t make_mask(enum_t flag) noexcept
            { 
                return static_cast<size_t>(1) << get_bit_number(flag);
            }
        
        private: 
            mask_t flags = make_mask(AMGL_DITHER) | make_mask(AMGL_MULTISAMPLE) | make_mask(AMGL_DEPTH_WRITEMASK);
        };

        using state_flags_t = flags_t<_GLOBAL_STATE_FLAGS_BLOCK_END - _GLOBAL_STATE_FLAGS_BLOCK_BEGIN - 1, _GLOBAL_STATE_FLAGS_BLOCK_BEGIN + 1>;

    public:
        static constexpr int32_t MAX_FRAGMENT_TEXTURE_UNITS             = _TEXTURE_UNITS_BLOCK_END - _TEXTURE_UNITS_BLOCK_BEGIN - 1;
        static constexpr int32_t MAX_VERTEX_TEXTURE_UNITS               = _TEXTURE_UNITS_BLOCK_END - _TEXTURE_UNITS_BLOCK_BEGIN - 1;
        static constexpr int32_t CLIP_DISTANCES_COUNT                   = AMGL_COLOR_LOGIC_OP - AMGL_CLIP_DISTANCE0;
        static constexpr int32_t MAX_SHADER_STORAGE_BUFFER_BINDINGS     = 8;

    public:
        enum_t active_texture_unit = AMGL_TEXTURE0;

        color_t blend_color;

        enum_t blend_equation_rgb = AMGL_FUNC_ADD;
        enum_t blend_equation_alpha = AMGL_FUNC_ADD;

        enum_t blend_src_rgb = AMGL_ONE;
        enum_t blend_src_alpha = AMGL_ONE;
        enum_t blend_dst_rgb = AMGL_ZERO;
        enum_t blend_dst_alpha = AMGL_ZERO;

        binded_buffers_t binded_buffers;

        color_t clear_color;
        color_mask_t color_mask;

        debugproc debug_callback = {};
        void* debug_user_param = nullptr;

        depth_range_t depth_range;
        float depth_clear_value = 1.0f;
        enum_t depth_func = AMGL_LESS;

        enum_t face_culling_mode = AMGL_BACK;
        enum_t front_face_orientation_mode = AMGL_CCW;

        float line_width = 1.0f;

        enum_t logic_op_mode = AMGL_COPY;
        
        enum_t last_error = AMGL_NO_ERROR;

        enum_t polygon_mode = AMGL_FILL;
        
        float point_size = 1.0f;

        rect_t scissor_rect;

        id_t shader_program = 0;

        state_flags_t state_flags;

        rect_t viewport_rect;
    };
};