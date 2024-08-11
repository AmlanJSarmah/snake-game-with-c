cmake_minimum_required(VERSION 3.22.1)
project(Snake-Game)

find_package(Curses REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/headers)
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})