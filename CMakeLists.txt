cmake_minimum_required(VERSION 3.20)

project(LucyEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(LucyEngine 
    src/main.cpp 
    src/Core/Application.cpp
)

#GLFW connection

target_include_directories(LucyEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/third_party/GLFW/include"
)

target_link_libraries(LucyEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/third_party/GLFW/lib-vc2026/glfw3.lib"
)

#Vulkan connection

find_package(Vulkan REQUIRED)

target_link_libraries(LucyEngine PRIVATE
    Vulkan::Vulkan
)