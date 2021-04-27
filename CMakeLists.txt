project(cpptermlib)
cmake_minimum_required(VERSION 3.9)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

option(BUILD_TEST_APP "Build test application" OFF)

include(cmake/CMakeCompiler.cmake)
include(cmake/CMakeDebug.cmake)
include(cmake/CMakeStrings.cmake)

find_package(JSONCPP REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(${JSONCPP_INCLUDE_DIR}
                    src
                    src/control
                    src/defines
                    src/io
                    src/layouts
                    src/primitives
                    src/tools
                    src/tools/logger
                    src/tools/options
                    src/tools/terminal
                    src/widgets
                    )

set(CPPTERMLIB_HEADERS
    src/capplication.h
    src/control/ccontrolcode.h
    src/control/ccontrolcodes.h
    src/control/cdynamiccontrolcode.h
    src/control/cstaticcontrolcode.h
    src/cpptermlib.h
    src/defines/exceptions.h
    src/defines/graphics.h
    src/defines/liblog.h
    src/defines/log.h
    src/defines/terminal_codes.h
    src/defines/types.h
    src/io/ccomposer.h
    src/layouts/llayout.h
    src/primitives/ccoordinate.h
    src/primitives/csize.h
    src/tools/logger/clogger.h
    src/tools/options/cjson.h
    src/tools/options/coptions.h
    src/tools/options/ctheme.h
    src/tools/terminal/ccolorscount.h
    src/tools/terminal/cterminal.h
    src/widgets/wpanel.h
    src/widgets/wwidget.h
    src/widgets/wwindow.h
    )

set(CPPTERMLIB_SOURCES
    src/capplication.cpp
    src/control/ccontrolcode.cpp
    src/control/ccontrolcodes.cpp
    src/control/cdynamiccontrolcode.cpp
    src/control/cstaticcontrolcode.cpp
    src/cpptermlib.cpp
    src/io/ccomposer.cpp
    src/layouts/llayout.cpp
    src/primitives/ccoordinate.cpp
    src/primitives/csize.cpp
    src/tools/logger/clogger.cpp
    src/tools/options/cjson.cpp
    src/tools/options/coptions.cpp
    src/tools/options/ctheme.cpp
    src/tools/terminal/ccolorscount.cpp
    src/tools/terminal/cterminal.cpp
    src/widgets/wpanel.cpp
    src/widgets/wwidget.cpp
    src/widgets/wwindow.cpp
    )

set(CPPTERMLIB_LIBRARYES cpptools
                         logger
                         stdc++fs
                         ${JSONCPP_LIBRARIES})

add_library(cppterm SHARED
            ${CPPTERMLIB_HEADERS}
            ${CPPTERMLIB_SOURCES})
target_link_libraries(cppterm PUBLIC ${CPPTERMLIB_LIBRARYES})

if(BUILD_TEST_APP)
  add_executable(test test/main.h test/main.cpp)
  target_link_libraries(test cppterm ${CPPTERMLIB_LIBRARYES})
endif(BUILD_TEST_APP)
