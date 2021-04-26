#include "ccontrolcodes.h"
#include "defines/liblog.h"

namespace ct
{
namespace control
{

CControlCodes::CControlCodes()
{}

CControlCodes::~CControlCodes()
{}

const CDynamicControlCode CControlCodes::cursorMove(const ct::primitives::CCoordinate *position)
{
  return cursorMove(position->x(), position->y());
}

const CDynamicControlCode CControlCodes::cursorMove(const ct::type::TCoordinate &x, const ct::type::TCoordinate &y)
{
  return CDynamicControlCode(CT_CURSOR_MOVE(x, y));
}

}
}
