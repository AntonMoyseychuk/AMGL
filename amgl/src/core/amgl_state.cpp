#include "pch.hpp"

#include "amgl_state.hpp"


namespace amgl
{   
    static amgl_state gs_state;

    amgl_state &get_amgl_global_state() noexcept
    {
        return gs_state;
    }
}