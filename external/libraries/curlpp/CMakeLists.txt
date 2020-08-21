find_package(curlpp ${curlpp_MINIMUM_REQUIRED} QUIET COMPONENTS ${curlpp_COMPONENTS_REQUIRED})

if(curlpp_FOUND)
  message(STATUS "Found curlpp version ${curlpp_MAJOR_VERSION}.${curlpp_MINOR_VERSION}.${curlpp_SUBMINOR_VERSION}")
  add_library(curlpp_external INTERFACE)
else()
  message(STATUS "curlpp ${curlpp_MINIMUM_REQUIRED} could not be located, Building curlpp instead.")
  include(FetchContent)

  FetchContent_Declare(
    _curlpp
    GIT_REPOSITORY https://github.com/jpbarrette/curlpp.git
    GIT_TAG v0.8.1)
  
  FetchContent_GetProperties(_curlpp)
  if(NOT _curlpp_POPULATED)
    FetchContent_Populate(_curlpp)
    message(STATUS "Added curlpp source : ${_curlpp_SOURCE_DIR}")
    message(STATUS "Added curlpp binary : ${_curlpp_BINARY_DIR}")
    add_subdirectory(
      ${_curlpp_SOURCE_DIR} 
      ${_curlpp_BINARY_DIR}
    )
    # include_directories(${_curlpp_SOURCE_DIR}/include)
    set(CURL_SOURCE_DIR ${_curlpp_SOURCE_DIR}/include)
  endif()
endif()
