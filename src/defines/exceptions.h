#pragma once
#include <stdexcept>
#include <string>
#include "defines/liblog.h"

#define CT_THROW_(_type,_message) CT_LOG_CRY(_message) throw std::_type(_message);
#define CT_ASSERT(_condition,_type,_message) if(_condition) { CT_THROW_(_type, std::string(_message " {" #_condition "}. " "File " __FILE__ " at line " CT_STR(__LINE__) " in method ") + std::string(__func__)); }
