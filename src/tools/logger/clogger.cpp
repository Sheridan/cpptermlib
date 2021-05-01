#include "clogger.h"

#include "capplication.h"
#include "defines/liblog.h"

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
  setPath(CT_OPTIONS["logging"].get("path", CT_APP->currentUser()->home()).asString());
  std::string logLevel = CT_OPTIONS["logging"].get("level", "debug").asString();
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
