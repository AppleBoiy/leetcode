cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(q1 q1/sol.cc
        q1/main.cc
)

add_executable(q2 q2/sol.cc)
add_executable(q2c q2/sol_time_limit.c)
add_executable(q2chash q2/sol_time_limit_hash.c)

add_executable(q3 q3/sol.cc)