cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(darabonba_core LANGUAGES CXX)

# <<< Build targets >>>
# SHARED library
add_library(darabonba_core SHARED "")
target_sources(darabonba_core
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/core.cpp
)

target_compile_definitions(darabonba_core
  PUBLIC
    $<$<BOOL:${UUID_FOUND}>:HAVE_UUID>
)

target_link_libraries(darabonba_core
  PUBLIC
    $<$<BOOL:${UUID_FOUND}>:PkgConfig::UUID>
)

set_property(TARGET darabonba_core PROPERTY POSITION_INDEPENDENT_CODE 1)
set_property(TARGET darabonba_core PROPERTY SOVERSION ${PROJECT_VERSION_MAJOR})
set_property(TARGET darabonba_core PROPERTY OUTPUT_NAME "core")
set_property(TARGET darabonba_core PROPERTY DEBUG_POSTFIX "_d")
set_property(TARGET darabonba_core PROPERTY PUBLIC_HEADER "core.hpp")
set_property(TARGET darabonba_core PROPERTY MACOSX_RPATH ON)
set_property(TARGET darabonba_core PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)

# EXECUTABLES
add_executable(main main.cpp)

target_link_libraries(main
  PUBLIC
    darabonba_core
)

# Prepare RPATH
file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${INSTALL_BINDIR} ${CMAKE_INSTALL_PREFIX})
if(APPLE)
  set(_rpath "@loader_path/${_rel}")
else()
  set(_rpath "\$ORIGIN/${_rel}")
endif()
file(TO_NATIVE_PATH "${_rpath}/${INSTALL_LIBDIR}" core_RPATH)

set_target_properties(main
  PROPERTIES
    MACOSX_RPATH ON
    SKIP_BUILD_RPATH OFF
    BUILD_WITH_INSTALL_RPATH OFF
    INSTALL_RPATH "${core_RPATH}"
    INSTALL_RPATH_USE_LINK_PATH ON
  )

message(STATUS "Project will be installed to `${CMAKE_INSTALL_PREFIX}`")

# <<< Install and export targets >>>
install(FILES ${darabonba_core} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/darabonba/)
install(TARGETS darabonba_core
  ARCHIVE DESTINATION ${INSTALL_LIBDIR} COMPONENT lib
  LIBRARY DESTINATION ${INSTALL_LIBDIR} COMPONENT lib
  RUNTIME DESTINATION ${INSTALL_BINDIR} COMPONENT bin
  PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDEDIR}/darabonba COMPONENT dev)
# message(STATUS "====================================================================================")