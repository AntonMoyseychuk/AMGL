#pragma once

#define RETURN_IF_FALSE(expr) if (!(expr)) { return; }
#define RETURN_IF_NULLPTR(ptr) RETURN_IF_FALSE(ptr != nullptr)

#define IN_INTERVAL_INCLUSIVE(begin, end, value) (value >= begin && value <= end)

#define IS_DEFAULT_ID(id) ((id) == 0)

#if defined(_DEBUG) || defined(DEBUG) || !defined(NDEBUG)
    #include <cstdio>
    #include "debugbreak/debugbreak.h"
    
    #define AM_ASSERT_MSG(expr, ...) \
        { \
            if(!(expr)) { \
                printf_s(__FILE__ " (%d): ", __LINE__); \
                printf_s(__VA_ARGS__); \
                debug_break(); \
            } \
        }
    #define AM_ASSERT(expr) AM_ASSERT_MSG(expr, "")
    
    #define NOT_IMPLEMENTED_YET(feature_desc) AM_ASSERT_MSG(false, "Not implemented yet: %s\n", feature_desc)

#else
    #define AM_ASSERT_MSG(expr, ...)
    #define AM_ASSERT(expr)
#endif