cmake_minimum_required(VERSION 3.9)
project(FlappyButt)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(include)

link_directories(lib)

add_executable(FlappyButt main.cpp GameManager.cpp GameManager.h)

target_link_libraries(FlappyButt
        ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
        libglfw3.a
        glew32.lib
        )