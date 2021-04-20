#pragma once
#include "primitives/csize.h"
#include "defines/types.h"
#include "primitives/ccoordinate.h"

namespace ct
{

class CTerminal
{
public:
  CTerminal();
  virtual ~CTerminal();
  const ct::primitives::CSize &size() const;
  void clear() const;
  void update();

private:
  ct::primitives::CSize m_terminalSize;
  unsigned int m_terminalColors;

  void mineTerminalSize();
  void mineTerminalColors();
};

}
