cmake_minimum_required(VERSION 3.18)

project(Analog_Clock)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/sdl2-cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR}/Clock)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Clock)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Clock ${SDL2_LIBRARY} -static-libstdc++ -static-libgcc -mwindows)