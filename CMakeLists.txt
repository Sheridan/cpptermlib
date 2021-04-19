project(cpptermlib)
cmake_minimum_required(VERSION 3.9)

option(BUILD_TEST_APP "Build test application" OFF)

include(cmake/CMakeCompiler.cmake)
include(cmake/CMakeDebug.cmake)
include(cmake/CMakeStrings.cmake)

find_package(nlohmann_json 3.1.0 REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(src
                    src/defines
                    src/io
                    src/primitives
                    src/control
                    src/tools
                    src/tools/logger
                    src/tools/options
                    src/widgets
                    )

set(CPPTERMLIB_HEADERS
    src/capplication.h
    src/control/ccontrolcode.h
    src/control/ccontrolcodes.h
    src/control/ccontrolstring.h
    src/cpptermlib.h
    src/cterminal.h
    src/defines/liblog.h
    src/defines/log.h
    src/defines/terminal_codes.h
    src/defines/types.h
    src/io/cbuffer.h
    src/primitives/ccoordinate.h
    src/primitives/csize.h
    src/tools/logger/clogger.h
    src/tools/options/cjson.h
    src/tools/options/coptions.h
    src/tools/options/ctheme.h
    src/widgets/cwidget.h
    src/control/cstaticcontrolcode.h
    src/control/cdynamiccontrolcode.h
    )
set(CPPTERMLIB_SOURCES
    src/capplication.cpp
    src/control/ccontrolcode.cpp
    src/control/ccontrolcodes.cpp
    src/control/ccontrolstring.cpp
    src/cpptermlib.cpp
    src/cterminal.cpp
    src/io/cbuffer.cpp
    src/primitives/ccoordinate.cpp
    src/primitives/csize.cpp
    src/tools/logger/clogger.cpp
    src/tools/options/cjson.cpp
    src/tools/options/coptions.cpp
    src/tools/options/ctheme.cpp
    src/widgets/cwidget.cpp
    src/control/cstaticcontrolcode.cpp
    src/control/cdynamiccontrolcode.cpp
    )

set(CPPTERMLIB_LIBRARYES cpptools
                         logger
                         stdc++fs
                         nlohmann_json::nlohmann_json)

add_library(cppterm SHARED
            ${CPPTERMLIB_HEADERS}
            ${CPPTERMLIB_SOURCES})
target_link_libraries(cppterm PUBLIC ${CPPTERMLIB_LIBRARYES})

if(BUILD_TEST_APP)
  add_executable(test test/main.h test/main.cpp)
  target_link_libraries(test cppterm ${CPPTERMLIB_LIBRARYES})
endif(BUILD_TEST_APP)
