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
  void moveCursor(const ct::primitives::CCoordinate &coordinate);

private:
  ct::primitives::CSize m_terminalSize;

  void mineTerminalSize();
};

}
