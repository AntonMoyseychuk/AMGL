#pragma once
#include "amgl/amgl.hpp"

namespace amgl
{
    class buffer_mng
    {
    public:
        static buffer_mng& instance() noexcept;
        
        id_t generate_buffer() const noexcept;
        void free_buffer(id_t buffer) const noexcept;

        void bind_buffer(enum_t target, id_t buffer) const noexcept;
        void bind_buffer_base(enum_t target, uint32_t index, id_t buffer) noexcept;

        void allocate_named_memory(id_t buffer, uint64_t size, const void* data, enum_t usage /* unused yet */) const noexcept;
        void allocate_memory(enum_t target, uint64_t size, const void* data, enum_t usage /* unused yet */) const noexcept;
        void deallocate_named_memory(id_t buffer) const noexcept;

        void copy_buffer_sub_data(enum_t read_target, enum_t write_target, uint64_t read_offset, uint64_t write_offset, uint64_t size) noexcept;
        void copy_named_buffer_sub_data(id_t read_buffer, id_t write_buffer, uint64_t read_offset, uint64_t write_offset, uint64_t size) noexcept;

        void get_buffer_sub_data(enum_t target, uint64_t offset, uint64_t size, void* data) noexcept;
        void get_named_buffer_sub_data(id_t buffer, uint64_t offset, uint64_t size, void* data) noexcept;

        void sub_data(enum_t target, uint64_t offset, uint64_t size, const void* data) noexcept;
        void named_sub_data(id_t buffer, uint64_t offset, uint64_t size, const void* data) noexcept;

        bool is_buffer(id_t buffer) const noexcept;

        void* map_named_buffer(id_t buffer, enum_t access /* unused yet */) const noexcept;
        void* map_buffer(enum_t target, enum_t access /* unused yet */) const noexcept;

        id_t generate_vertex_array() const noexcept;
        void free_vertex_array(id_t array) const noexcept;

        void bind_vertex_array(id_t array) const noexcept;

        buffer_mng(const buffer_mng&) = delete;
        buffer_mng& operator=(const buffer_mng&) = delete;

    private:
        buffer_mng() = default;
        ~buffer_mng() = default;
    };
}