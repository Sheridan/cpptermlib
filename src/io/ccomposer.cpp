#include "io/ccomposer.h"
#include "capplication.h"
#include "control/ccontrolcodes.h"
#include "defines/graphics.h"
#include "defines/liblog.h"
#include <algorithm>
#include <cppt/string.h>

namespace ct
{
namespace io
{

CComposer::CComposer() : ct::widgets::WObject(ct::primitives::CCoordinate(), ct::primitives::CSize())
{}

CComposer::~CComposer()
{
  for(ct::widgets::WWindow *window : m_windows)
  {
    delete window;
    window = nullptr;
  }
}

void CComposer::addWindow(ct::widgets::WWindow *window)
{
  m_windows.push_back(window);
  update();
}

void CComposer::removeWindow(ct::widgets::WWindow *window)
{
  m_windows.erase(std::remove(m_windows.begin(), m_windows.end(), window), m_windows.end());
  update();
}

void CComposer::draw()
{
  CT_THEME.style("background")->apply();
  for(ct::type::TCoordinate y = topLeft()->y(); y <= bottomLeft()->y(); y++)
  {
    CPT_OUT
      << ct::control::CControlCodes::cursorMove(topLeft()->x(), y).code()
      << cppt::string::repeat(CT_G_SPACE, size()->width());
  }
}

void CComposer::updateWindows()
{
  redraw();
  for(ct::widgets::WWindow *window : m_windows)
  {
    window->updateWidgets();
  }
  CPT_OUT << std::flush;
}


}
}
