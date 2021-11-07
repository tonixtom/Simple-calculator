cmake_minimum_required(VERSION 3.17)
project(tom_calc)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_BUILD_TYPE Debug)


set(Srcs
        main.cpp
        calculate.cpp polynomial.cpp conversion.cpp stack.cpp)

set(Hdrs

        calculate.h polynomial.h conversion.h stack.h)

add_executable(${PROJECT_NAME} ${Srcs} ${Hdrs})
