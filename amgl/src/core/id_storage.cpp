#include "pch.hpp"

#include "id_storage.hpp"

namespace amgl
{
    id_t id_storage::generate_id() noexcept
    {
        const id_t id = m_curr_id++;
        if (id != 0) {
            m_busy_ids.set(id, true);
        } else {
            NOT_IMPLEMENTED_YET("If m_curr_id is equal 0, than there was id overflow (need to make id reusable)");
        }

        return id;
    }

    void id_storage::free_id(id_t id) noexcept
    {
        if (id == 0) {
            return;
        }

        m_busy_ids.set(id, false);
    }

    bool id_storage::is_busy(id_t id) const noexcept
    {
        return m_busy_ids[id];
    }

    bool id_storage::is_full() const noexcept
    {
        return m_busy_ids.all();
    }
}