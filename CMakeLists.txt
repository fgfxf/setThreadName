cmake_minimum_required(VERSION 3.10.0)
project(setThreadName VERSION 0.1.0 LANGUAGES C CXX)

add_executable(setThreadName
main.cpp
SetThreadName.cpp
)
target_link_libraries(setThreadName
PUBLIC  pthread
)