#pragma once
#include "capplication.h"
#include "defines/log.h"

#define CT_APPLOG(_priority,_what) CT_LOG(log,_priority,_what)

#define CT_LOG_DBG(_what) { CT_APPLOG(debug   , _what); }
#define CT_LOG_NFO(_what) { CT_APPLOG(info    , _what); }
#define CT_LOG_WRN(_what) { CT_APPLOG(warning , _what); }
#define CT_LOG_ERR(_what) { CT_APPLOG(error   , _what); }
#define CT_LOG_CRY(_what) { CT_APPLOG(critical, _what); throw std::runtime_error(_what); }
