#include "clogger.h"
#include "defines/liblog.h"
#include "capplication.h"

namespace ct
{
namespace tools
{
namespace logger
{
CLogger::CLogger()
  : ll::CLogger<CLogger>("",
                         CT_APP->applicationName() + ".log",
                         LL_DEFAULT_DATETIME_FORMAT,
                         false,
                         true)
{}

CLogger::~CLogger()
{}

#define CT_IFLOGLEVEL(_lltype) \
  (logLevel == #_lltype) { setMaxPriority(ll::priority::_lltype.priority()); }

void CLogger::applyOptions()
{
  setPath(CT_OPTIONS["logging"].value("path", CT_APP->currentUser()->home()));
  std::string logLevel = CT_OPTIONS["logging"].value("level", "debug");
  if CT_IFLOGLEVEL(debug)
    else if CT_IFLOGLEVEL(info)
      else if CT_IFLOGLEVEL(warning)
        else if CT_IFLOGLEVEL(error)
          else if CT_IFLOGLEVEL(critical);
  setOutToFile(true);
  setOutToConsole(false);
}

CLogger& CLogger::liblog(const ll::CLogPriority &priority)
{
  start(priority);
  write("[lib] ");
  return *this;
}

}
}
}
