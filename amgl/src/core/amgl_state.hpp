#pragma once

#include "amgl/amgl.hpp"

#include <glm/glm.hpp>

namespace amgl
{
    struct amgl_state
    {
        id_t vao = 0;
        id_t vbo = 0;
        id_t ebo = 0;
        id_t copy_write_buffer = 0;
        id_t copy_read_buffer = 0;
        id_t shader_storage_buffer = 0;
        id_t uniform_buffer = 0;

        debugproc debug_callback = {};
        void* debug_user_param = nullptr;
    };

    amgl_state& get_amgl_global_state() noexcept;
};