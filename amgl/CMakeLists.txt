project(amgl)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/amthreadpool)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/glm)

file(GLOB_RECURSE AMGL_SRC CONFIGURE_DEPENDS 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} STATIC ${AMGL_SRC})

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE amthreadpool glm)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/pch.hpp)