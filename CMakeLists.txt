
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(darabonba VERSION "0.1.0")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
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

if(ENABLE_UNIT_TESTS)
  add_subdirectory(tests)
endif()

# set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)

# include(ExternalProject)

# ExternalProject_Add(${PROJECT_NAME}_core
#   SOURCE_DIR
#     ${CMAKE_CURRENT_LIST_DIR}/core
#   CMAKE_ARGS
#     -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
#     -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
#     -DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS}
#     -DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
#   CMAKE_CACHE_ARGS
#     -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
#   BUILD_ALWAYS
#     1
#   INSTALL_COMMAND
#     ""
# )
