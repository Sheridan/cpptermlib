#include "cterminal.h"

#include "control/ccontrolcodes.h"
#include "defines/liblog.h"
#include "terminal_codes.h"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sys/ioctl.h>

namespace ct
{
namespace tools
{
namespace terminal
{
CTerminal::CTerminal()
  : m_terminalColors(nullptr)
{
  m_terminalColors = new ct::tools::terminal::CColorsCount();
  update();
}

CTerminal::~CTerminal()
{
  delete m_terminalColors;
}

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
  CT_COMPOSER->resize(size());
}

ct::tools::terminal::CColorsCount* CTerminal::colorsCount()
{
  return m_terminalColors;
}

void CTerminal::mineTerminalSize()
{
  //TODO: SIGWINCH when termsize changed
  struct winsize ws;
  if(ioctl(1, TIOCGWINSZ, &ws))
  {
    CT_LOG_CRY("Can not get terminal size");
  }
  m_terminalSize = ct::primitives::CSize(ws.ws_col, ws.ws_row);
  CT_LOG_DBG("Terminal resized to " << m_terminalSize);
}

}
}
}
