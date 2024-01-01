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
            mask_t flags = make_mask(AMGL_DITHER) | make_mask(AMGL_MULTISAMPLE);
        };

        using state_flags_t = flags_t<_GLOBAL_STATE_VARS_BLOCK_END - _GLOBAL_STATE_VARS_BLOCK_BEGIN - 1, _GLOBAL_STATE_VARS_BLOCK_BEGIN + 1>;

    public:
        debugproc debug_callback = {};
        void* debug_user_param = nullptr;

        color_t blend_color;
        color_mask_t color_mask;

        rect_t viewport_rect;
        rect_t scissor_rect;

        id_t vao = 0;
        id_t vbo = 0;
        id_t ebo = 0;
        id_t copy_write_buffer = 0;
        id_t copy_read_buffer = 0;
        id_t shader_storage_buffer = 0;
        id_t uniform_buffer = 0;

        enum_t blend_equation_rgb = AMGL_FUNC_ADD;
        enum_t blend_equation_alpha = AMGL_FUNC_ADD;

        enum_t blend_src_rgb = AMGL_ONE;
        enum_t blend_src_alpha = AMGL_ONE;
        enum_t blend_dst_rgb = AMGL_ZERO;
        enum_t blend_dst_alpha = AMGL_ZERO;

        enum_t logic_operator = AMGL_COPY;

        enum_t face_culling_mode = AMGL_BACK;
        enum_t front_face_orientation_mode = AMGL_CCW;

        enum_t polygon_mode = AMGL_FILL;

        depth_range_t depth_range;
        enum_t depth_func = AMGL_LESS;
        bool depth_writing_enabled = true;

        enum_t last_error = AMGL_NO_ERROR;

        state_flags_t state_flags;
    };
};