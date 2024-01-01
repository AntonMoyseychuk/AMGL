#pragma once
#include "amgl/amgl.hpp"

namespace amgl
{
    class id_storage
    {
    public:
        id_t generate_id() noexcept;
        void free_id(id_t id) noexcept;

        bool is_busy(id_t id) const noexcept;
        bool is_full() const noexcept;

    private:
        static constexpr uint64_t STORAGE_SIZE = static_cast<uint64_t>(std::numeric_limits<id_t>::max()) + 1;

    public:
        static constexpr uint64_t MAX_UNIQUE_IDS = STORAGE_SIZE;

    private:
        std::bitset<STORAGE_SIZE> m_busy_ids = {1};
        id_t m_curr_id = 1;
    };
}