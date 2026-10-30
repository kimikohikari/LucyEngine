cmake_minimum_required(VERSION 3.20)

project(LucyEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(LucyEngine 
    src/main.cpp 
    src/Core/Application.cpp
)