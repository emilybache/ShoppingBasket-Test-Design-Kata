cmake_minimum_required(VERSION 3.16)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(ShoppingBasket VERSION 1.0
        DESCRIPTION "ShoppingBasket kata solution for learning about test design."
        LANGUAGES CXX)
# uncomment these lines to enable coverage measurements using gcov
#set(CMAKE_CXX_FLAGS "--coverage")

enable_testing()
add_subdirectory(src)
add_subdirectory(test-doctest)
add_subdirectory(test-gtest)

