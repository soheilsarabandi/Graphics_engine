cmake_minimum_required(VERSION 3.14)
project(openglTuto)


add_executable(Result src/main.cpp src/screen.cpp src/input.cpp src/glad.c)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

target_include_directories(Result PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                           $<INSTALL_INTERFACE:include>)
target_link_libraries(Result PUBLIC glfw OpenGL::GL SDL2 ${CMAKE_DL_LIBS})

