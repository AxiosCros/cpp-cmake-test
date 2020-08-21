
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(darabonba VERSION "0.1.0")

# <<< General set up >>>
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

option(ENABLE_UNIT_TESTS "Enable unit tests" OFF)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

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

add_library(core SHARED "")

target_sources(core
        PRIVATE
        src/core.cpp
        src/main.cpp
        include/core.hpp)

target_include_directories(core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(core
        PROPERTIES
        POSITION_INDEPENDENT_CODE 1
        SOVERSION ${PROJECT_VERSION_MAJOR}
        OUTPUT_NAME "credential"
        DEBUG_POSTFIX "_d"
        PUBLIC_HEADER "core.hpp"
        MACOSX_RPATH ON
        WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(external/libraries)
# add_subdirectory(external/libraries_dev)
# target_link_libraries(core PRIVATE ordered_map curlpp)
# target_link_libraries(core PRIVATE curlpp)
# message(STATUS "---------------------------------------------------------------------")
# find_library(FIND_CURLPP NAMES curlpp)
# find_library(FIND_GTEST NAMES gtest_main)
# message(STATUS "${FIND_CURLPP}")
# message(STATUS "${FIND_GTEST}")
# include_directories(cmake_build/_deps/_curlpp-src/include)

# message(STATUS "---------------------------------------------------------------------")

if(ENABLE_UNIT_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(external/libraries_dev)
  add_executable(tests
            tests/main.cpp)
  target_link_libraries(tests
            PRIVATE
            core
            curlpp
            gtest_main
            gmock_main
  )
  message(STATUS "---------------------------------------------------------------------")
  find_library(FIND_CURLPP NAMES curlpp)
  message(STATUS "${FIND_CURLPP}")
  message(STATUS "---------------------------------------------------------------------")
  target_include_directories(tests PRIVATE cmake_build/_deps/_curlpp-src/include)
  add_test(NAME google_test
            COMMAND $<TARGET_FILE:tests>)
endif()
