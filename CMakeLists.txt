cmake_minimum_required(VERSION 3.18)

project(test_case_client CXX)

set (CMAKE_CXX_STANDARD 20)

if (NOT TARGET ph_network)
	add_subdirectory (dependencies/ph_network)
endif ()

find_package (Boost 1.75 REQUIRED)


add_subdirectory(src)