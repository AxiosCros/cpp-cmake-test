
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cmake-study VERSION "0.1.0")

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

if(CMAKE_CXX_COMPILER_LOADED)
	message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
	message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
    list(APPEND flags "-Wextra" "-Wpedantic")
endif()

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_library(message-objs
	OBJECT
		src/message.hpp
		src/message.cpp
)

set_target_properties(message-objs
	PROPERTIES
		POSITION_INDEPENDENT_CODE 1
)

add_library(message-shared
	SHARED
		$<TARGET_OBJECTS:message-objs>
)

add_library(message-static
	STATIC
		$<TARGET_OBJECTS:message-objs>
)

add_executable(main src/main.cpp)

# add message library to main exec binary
target_link_libraries(main message-static)