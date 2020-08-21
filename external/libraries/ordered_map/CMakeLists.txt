find_package(ordered-map ${ordered-map_MINIMUM_REQUIRED} QUIET COMPONENTS ${ordered-map_COMPONENTS_REQUIRED})

if(ordered-map_FOUND)
  message(STATUS "Found ordered-map version ${ordered-map_MAJOR_VERSION}.${ordered-map_MINOR_VERSION}.${ordered-map_SUBMINOR_VERSION}")
  add_library(ordered-map_external INTERFACE)
else()
  message(STATUS "ordered-map ${ordered-map_MINIMUM_REQUIRED} could not be located, Building ordered-map instead.")
  include(FetchContent)

  FetchContent_Declare(map
    GIT_REPOSITORY https://github.com/Tessil/ordered-map.git
    GIT_TAG v1.0.0)
  
  FetchContent_GetProperties(map)
  if(NOT map_POPULATED)
    FetchContent_Populate(map)
    add_subdirectory(${map_SOURCE_DIR} ${map_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()