cmake_minimum_required(VERSION 3.15)
project(Lec18-Functors)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(SOURCE_FILES print_it.cpp)
add_executable(PrintIt ${SOURCE_FILES})

set(SOURCE_FILES count_sum.cpp)
add_executable(CountAndSum ${SOURCE_FILES})

set(SOURCE_FILES functor_all_night.cpp)
add_executable(FunctorAllNight ${SOURCE_FILES})
