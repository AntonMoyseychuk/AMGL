#pragma once

#include "amgl/amgl.hpp"

namespace amgl
{
    struct amgl_state
    {
        id_t get_buffer_binded_to_target(enum_t target) const noexcept;
        void bind_buffer_to_target(enum_t target, id_t buffer) noexcept;

        id_t vao = 0;
        id_t vbo = 0;
        id_t ebo = 0;
        id_t copy_write_buffer = 0;
        id_t copy_read_buffer = 0;
        id_t shader_storage_buffer = 0;
        id_t uniform_buffer = 0;
    };

    amgl_state& get_amgl_global_state() noexcept;
};