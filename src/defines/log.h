#pragma once
#include <string>
#include <stdexcept>
#include <capplication.h>
#include <tools/logger/clogger.h>

#define CT_STR_HELPER(x) #x
#define CT_STR(x) CT_STR_HELPER(x)

#define CT_LOG(_who,_priority,_what) if(ct::CApplication::active()) { CT_LOGGER->_who(ll::priority::_priority) << _what << ll::endl; }
#define CT_LOG_LINE(_caption) std::string(std::string(_caption " in file " __FILE__ " at line " CT_STR(__LINE__) " in method ") + std::string(__func__))

#define CT_STDOUT_LOG(_message) std::cout << "! " << _message << std::endl;
#define CT_STDERR_LOG(_message) std::cerr << "! " << _message << std::endl; throw std::runtime_error(_message);

#ifdef CT_DEBUG
#define CT_NOT_ALL_ENUMS_THROW default: { CT_LOG_CRY(CT_LOG_LINE("Missed some enum members")); } break;
#else  // CT_DEBUG
#define CT_NOT_ALL_ENUMS_THROW
#endif // CT_DEBUG
