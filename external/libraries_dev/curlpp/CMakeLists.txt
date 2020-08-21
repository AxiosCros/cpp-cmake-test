find_package(curlpp ${curlpp_MINIMUM_REQUIRED} QUIET COMPONENTS ${curlpp_COMPONENTS_REQUIRED})

if(curlpp_FOUND)
  message(STATUS "Found curlpp version ${curlpp_MAJOR_VERSION}.${curlpp_MINOR_VERSION}.${curlpp_SUBMINOR_VERSION}")
  add_library(curlpp_external INTERFACE)
else()
  message(STATUS "curlpp ${curlpp_MINIMUM_REQUIRED} could not be located, Building curlpp instead.")
  include(FetchContent)

  FetchContent_Declare(curlpp_git
    GIT_REPOSITORY https://github.com/jpbarrette/curlpp.git
    GIT_TAG v0.8.1)
  
  FetchContent_GetProperties(curlpp_git)
  if(NOT curlpp_git_POPULATED)
    FetchContent_Populate(curlpp_git)
    message(STATUS "Added curlpp source&binary ${curlpp_git_SOURCE_DIR} ${curlpp_git_BINARY_DIR}")
    add_subdirectory(${curlpp_git_SOURCE_DIR} ${curlpp_git_BINARY_DIR})
  endif()
endif()
