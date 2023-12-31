#pragma once

#define RETURN_IF_FALSE(expr) if (!(expr)) { return; }
#define RETURN_IF_NULLPTR(ptr) RETURN_IF_FALSE(ptr != nullptr)

#define IN_INTERVAL_INCLUSIVE(begin, end, value) (value >= begin && value <= end)

using byte_buffer = std::vector<uint8_t>;