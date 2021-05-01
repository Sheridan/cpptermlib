#pragma once
#include "loggerlib/loggerlib.h"
#include "primitives/csize.h"
#include "primitives/ccoordinate.h"

namespace ct
{
namespace tools
{
namespace logger
{

class CLogger : public ll::CLogger<CLogger>
{
public:
  CLogger();
  virtual ~CLogger();

  void applyOptions();
  CLogger &liblog(const ll::CLogPriority &priority = ll::priority::info);

  friend CLogger &operator<<(CLogger &logger, const ct::primitives::CSize &value)
  {
    logger.write(ll::CLogString() << "(" << value.width() << "," << value.height() << ")");
    return logger;
  }
  friend CLogger &operator<<(CLogger &logger, const ct::primitives::CCoordinate &value)
  {
    logger.write(ll::CLogString() << "(" << value.x() << "," << value.y() << ")");
    return logger;
  }
};

}
}
}
