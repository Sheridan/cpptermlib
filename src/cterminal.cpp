#include "cterminal.h"
#include "terminal_codes.h"
#include "control/ccontrolcodes.h"
#include "defines/liblog.h"

#include <sys/ioctl.h>
#include <string.h>
#include <stdexcept>
#include <iostream>

namespace ct
{

CTerminal::CTerminal()
{
  update();
}

CTerminal::~CTerminal()
{}

const ct::primitives::CSize &CTerminal::size() const
{
  return m_terminalSize;
}

void CTerminal::clear() const
{
  ct::control::ccodes::clear.apply();
}

void CTerminal::update()
{
  mineTerminalSize();
  clear();
}

void CTerminal::moveCursor(const ct::primitives::CCoordinate &coordinate)
{

}

void CTerminal::mineTerminalSize()
{
  struct winsize ws;
  if(ioctl(1, TIOCGWINSZ, &ws))
  {
    CT_LOG_CRY("Can not get terminal size");
  }
  m_terminalSize = ct::primitives::CSize(ws.ws_col, ws.ws_row);
  CT_LOG_DBG("Terminal resized to " << m_terminalSize);
}

}