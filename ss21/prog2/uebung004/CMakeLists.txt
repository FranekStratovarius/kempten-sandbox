project(uebung)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall")

find_package(glfw3 3.3 REQUIRED)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)
file(GLOB SOURCES_CXX src/cpp/*.cpp)

add_executable(uebung src/cpp/main.cpp src/c/glad.c ${SOURCES_CXX})
target_link_libraries(uebung glfw ${CMAKE_DL_LIBS})
