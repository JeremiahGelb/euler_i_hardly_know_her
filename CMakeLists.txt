cmake_minimum_required(VERSION 3.31.6)
project(DependenCPlusPlus CXX)
SET(CMAKE_CXX_STANDARD 26)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(problems)
add_executable(run_euler main.cpp)
target_link_libraries(run_euler euler)