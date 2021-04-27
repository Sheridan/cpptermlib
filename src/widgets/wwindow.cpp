#include "widgets/wwindow.h"
#include "capplication.h"
#include "defines/liblog.h"
#include "control/ccontrolcodes.h"
#include "defines/graphics.h"
#include <cppt/string.h>
#include <math.h>

namespace ct
{
namespace widgets
{
WWindow::WWindow(const std::string &title)
  : ct::widgets::WWidget(),
    m_title(title)
{
  CT_COMPOSER->addWindow(this);
}

WWindow::~WWindow()
{
  CT_COMPOSER->removeWindow(this);
}

const std::string WWindow::title() const
{
  return m_title;
}

void WWindow::setTitle(const std::string &title)
{
  m_title = title;
}

void WWindow::draw()
{
  size_t titleHalfLength = floor(m_title.length()/2);
  bool titleIsOdd = m_title.length() % 2;
  ct::control::CControlCodes::cursorMove(topLeft()).apply();
  CT_THEME.style("window_border")->apply();

  CPT_OUT
      << CT_G_BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT
      << cppt::string::repeat(CT_G_BOX_DRAWINGS_HEAVY_HORIZONTAL, ceil(size()->width() / 2) - titleHalfLength - 2) << CT_G_BOX_DRAWINGS_VERTICAL_LIGHT_AND_LEFT_HEAVY;
  CT_THEME.style("window_title")->apply();
  CPT_OUT << m_title;
  CT_THEME.style("window_border")->apply();
  CPT_OUT
      << CT_G_BOX_DRAWINGS_VERTICAL_LIGHT_AND_RIGHT_HEAVY << cppt::string::repeat(CT_G_BOX_DRAWINGS_HEAVY_HORIZONTAL, floor(size()->width() / 2) - titleHalfLength - 2 - titleIsOdd)
      << CT_G_BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT;
  ct::control::CControlCodes::cursorMove(topLeft()->x(), topLeft()->y()+1).apply();

  for(ct::type::TCoordinate y = topLeft()->y()+1; y < bottomLeft()->y()+1; y++)
  {
    CPT_OUT << CT_G_BOX_DRAWINGS_HEAVY_VERTICAL << cppt::string::repeat(CT_G_SPACE, size()->width()-2) << CT_G_BOX_DRAWINGS_HEAVY_VERTICAL;
    ct::control::CControlCodes::cursorMove(topLeft()->x(), y).apply();
  }
  CPT_OUT << CT_G_BOX_DRAWINGS_HEAVY_UP_AND_RIGHT << cppt::string::repeat(CT_G_BOX_DRAWINGS_HEAVY_HORIZONTAL, size()->width()-2) << CT_G_BOX_DRAWINGS_HEAVY_UP_AND_LEFT;

  ct::control::ccodes::reset.apply();
}


}
}

// ┏━━━━━━┥First window┝━━━━━━┓
// ┃                                     a┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
