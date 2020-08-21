find_package(nlohmann_json ${nlohmann_json_MINIMUM_REQUIRED} QUIET COMPONENTS ${nlohmann_json_COMPONENTS_REQUIRED})

if(nlohmann_json_FOUND)
  message(STATUS "Found nlohmann_json version ${nlohmann_json_MAJOR_VERSION}.${nlohmann_json_MINOR_VERSION}.${nlohmann_json_SUBMINOR_VERSION}")
  add_library(nlohmann_json_external INTERFACE)
else()
  message(STATUS "nlohmann_json ${nlohmann_json_MINIMUM_REQUIRED} could not be located, Building nlohmann_json instead.")
  include(FetchContent)

  FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.7.3)

  FetchContent_GetProperties(json)
  if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()
