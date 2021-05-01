#pragma once
#include "defines/types.h"
#include "primitives/ccoordinate.h"
#include "primitives/csize.h"
#include "tools/terminal/ccolorscount.h"

namespace ct
{
namespace tools
{
namespace terminal
{

class CTerminal
{
public:
  CTerminal();
  virtual ~CTerminal();
  const ct::primitives::CSize &size() const;
  void clear() const;
  void update();

  ct::tools::terminal::CColorsCount *colorsCount();


private:
  ct::primitives::CSize m_terminalSize;
  ct::tools::terminal::CColorsCount *m_terminalColors;

  void mineTerminalSize();
};

}
}
}
