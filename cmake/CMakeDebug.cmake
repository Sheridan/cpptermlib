
option(VERBOSE_BUILD "Verbose build project" OFF)

if(VERBOSE_BUILD)
  set(CMAKE_VERBOSE_MAKEFILE ON)
endif(VERBOSE_BUILD)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Build with debug info" )
  set(closure_extra_keys --formatting=PRETTY_PRINT)
  add_definitions(-DCT_DEBUG)
  add_definitions(-DCT_PROJECT_PATH="${PROJECT_SOURCE_DIR}")
  add_definitions(-g)
  set(BUILD_TEST_APP ON)
  if(CMS_USE_GCC)
    #ADD_DEFINITIONS( -ftest-coverage )
    add_definitions(-fprofile-arcs)
    set(GLOBAL_LINK_LIBS gcov)
  ENDIF(CMS_USE_GCC)
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DCT_PROJECT_PATH="")
  if(UNIX)
    add_definitions(-O2)
  endif(UNIX)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

if(UNIX)
  add_definitions(-Wall)
endif(UNIX)