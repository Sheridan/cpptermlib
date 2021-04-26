#pragma once
#include <map>
#include "tools/options/cjson.h"
#include "control/cdynamiccontrolcode.h"

namespace ct
{
namespace tools
{
namespace options
{

class CTheme : public ct::tools::options::CJson
{
public:
  CTheme();
  virtual ~CTheme();
  ct::control::CDynamicControlCode *style(const std::string &name);

private:
    const Json::Value &color(const std::string &name);
    const Json::Value &value(const std::string &styleName, const std::string &valueName);

    std::map<std::string, ct::control::CDynamicControlCode *> m_styleCache;
};

}
}
}
