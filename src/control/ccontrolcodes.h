#pragma once
#include "control/ccontrolcode.h"
#include "control/cdynamiccontrolcode.h"
#include "control/cstaticcontrolcode.h"
#include "defines/terminal_codes.h"
#include "primitives/ccoordinate.h"

namespace ct
{
namespace control
{
class CControlCodes
{
public:
  CControlCodes();
  virtual ~CControlCodes();
  static const CDynamicControlCode cursorMove(const ct::primitives::CCoordinate *position);
  static const CDynamicControlCode cursorMove(const ct::type::TCoordinate &x, const ct::type::TCoordinate &y);
};

namespace ccodes
{
constexpr CStaticControlCode none("");
constexpr CStaticControlCode esc(CT_ESC);
constexpr CStaticControlCode clear(CT_CLEAR_SCREEN);
constexpr CStaticControlCode reset(CT_RESET);

constexpr CStaticControlCode cursorHide(CT_CURSOR_HIDE);
constexpr CStaticControlCode cursorShow(CT_CURSOR_SHOW);
constexpr CStaticControlCode cursorSave(CT_CURSOR_SAVE);
constexpr CStaticControlCode cursorLoad(CT_CURSOR_LOAD);

}
}
}
