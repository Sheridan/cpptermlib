
option(USE_WSTRING "Build with wide strings" OFF)

if(USE_WSTRING)
  message(STATUS "Build with wide strings" )
  add_definitions( -DCT_WCHAR )
else(USE_WSTRING)
  message(STATUS "Build with standart strings" )
endif(USE_WSTRING)
