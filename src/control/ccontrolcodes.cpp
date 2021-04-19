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

const CDynamicControlCode CControlCodes::font(const ct::type::TTerminalCode &foreground,
                                              const ct::type::TTerminalCode &background,
                                              const bool &bold,
                                              const bool &italic,
                                              const bool &underline,
                                              const bool &strikethrough)
{
  std::string result = CT_COLOR_FOREGROUND(foreground) + CT_COLOR_BACKGROUND(background);
  if(bold)          { result += CT_BOLD;          }
  if(italic)        { result += CT_ITALIC;        }
  if(underline)     { result += CT_UNDERLINE;     }
  if(strikethrough) { result += CT_STRIKETHROUGH; }
  return CDynamicControlCode(result);
}

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
