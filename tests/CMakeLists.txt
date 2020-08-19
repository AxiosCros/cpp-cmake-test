cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(darabonba_core LANGUAGES CXX)

set(GOOGLE_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Download and unpack googletest at configure time
include(../extend/DownloadProject.cmake)

download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_executable(cpp_test "")

add_library(darabonba_core ../core/core.cpp ../core/core.hpp)

target_sources(cpp_test PRIVATE test.cpp)
target_link_libraries(cpp_test
  PRIVATE
    darabonba_core
    gtest_main
)

enable_testing()

add_test(
  NAME google_test
  COMMAND $<TARGET_FILE:cpp_test>
)
