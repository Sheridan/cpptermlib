#pragma once
#include "defines/log.h"

#define CT_LIBLOG(_priority,_what) CT_LOG(liblog,_priority,_what)

#define CT_LOG_DBG(_what) { CT_LIBLOG(debug   , _what); }
#define CT_LOG_NFO(_what) { CT_LIBLOG(info    , _what); }
#define CT_LOG_WRN(_what) { CT_LIBLOG(warning , _what); }
#define CT_LOG_ERR(_what) { CT_LIBLOG(error   , _what); }
#define CT_LOG_CRY(_what) { CT_LIBLOG(critical, _what); }
