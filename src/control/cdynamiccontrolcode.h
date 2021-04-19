#pragma once
// #include "defines/types.h"
#include "control/ccontrolcode.h"
#include <string>

namespace ct
{
namespace control
{

class CDynamicControlCode : public CControlCode<std::string>
{
public:
  CDynamicControlCode(const std::string &code) : CControlCode<std::string>(code) {}
};

}
}
