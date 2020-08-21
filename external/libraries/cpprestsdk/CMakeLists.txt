find_package(cpprestsdk ${cpprestsdk_MINIMUM_REQUIRED} QUIET COMPONENTS ${cpprestsdk_COMPONENTS_REQUIRED})

project(download_cpprestsdk VERSION "1.0.0")

if(cpprestsdk_FOUND)
    message(STATUS "Found cpprestsdk version ${cpprestsdk_MAJOR_VERSION}.${cpprestsdk_MINOR_VERSION}.${cpprestsdk_SUBMINOR_VERSION}")
    add_library(cpprestsdk_external INTERFACE)
else()
    message(STATUS "cpprestsdk ${cpprestsdk_MINIMUM_REQUIRED} could not be located, Building cpprestsdk instead.")
    include(FetchContent)

    FetchContent_Declare(cpprestsdk
            GIT_REPOSITORY https://github.com/microsoft/cpprestsdk.git
            GIT_TAG v2.10.16)

    FetchContent_GetProperties(cpprestsdk)
    if(NOT cpprestsdk_POPULATED)
        FetchContent_Populate(cpprestsdk)
        add_subdirectory(${cpprestsdk_SOURCE_DIR} ${cpprestsdk_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()