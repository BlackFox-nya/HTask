cmake_minimum_required(VERSION 3.10.0)
project(lab8 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lab8 data_io.cpp main.cpp processing.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
