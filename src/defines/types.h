#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace ct
{
namespace type
{

// Sizes
using TSize       = unsigned short;
using TSizeCount  = unsigned int;

// Coordinates
using TCoordinate = unsigned short;

// Strings
#ifdef CT_WCHAR
#define CPT_STRING        std::wstring
#define CPT_CHAR          wchar_t
#define CPT_STRINGSTREAM  std::wostringstream
#define CPT_OUT           std::wcout
#define CPT_STR(_s)       L##_s
#else
#define CPT_STRING        std::string
#define CPT_CHAR          char
#define CPT_STRINGSTREAM  std::ostringstream
#define CPT_OUT           std::cout
#define CPT_STR(_s)       _s
#endif

using TTerminalCode  = unsigned short;

}
}
