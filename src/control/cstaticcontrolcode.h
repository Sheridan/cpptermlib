#pragma once
#include "control/ccontrolcode.h"

namespace ct
{
namespace control
{

class CStaticControlCode : public CControlCode<const char *>
{
public:
  constexpr CStaticControlCode(const char *code) : CControlCode<const char *>(code) {}
};

}
}
