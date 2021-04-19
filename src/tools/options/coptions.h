#pragma once
#include "tools/options/cjson.h"

namespace ct
{
namespace tools
{
namespace options
{

class COptions : public ct::tools::options::CJson
{
public:
  COptions();
  virtual ~COptions();
};

}
}
}
