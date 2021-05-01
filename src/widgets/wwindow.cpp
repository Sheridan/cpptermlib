#include "widgets/wwindow.h"

#include "capplication.h"
#include "control/ccontrolcodes.h"
#include "defines/graphics.h"
#include "defines/liblog.h"
#include "widgets/wwidget.h"
#include <algorithm>
#include <cppt/string.h>
#include <math.h>

namespace ct
{
namespace widgets
{
WWindow::WWindow(const std::string &title)
  : ct::widgets::WObject(),
    m_title(title)
{
  CT_COMPOSER->addWindow(this);
}

WWindow::~WWindow()
{
  CT_COMPOSER->removeWindow(this);
  for(ct::widgets::WWidget *widget : m_widgets)
  {
    delete widget;
    widget = nullptr;
  }
}

const std::string WWindow::title() const
{
  return m_title;
}

void WWindow::setTitle(const std::string &title)
{
  m_title = title;
  update();
}

void WWindow::draw()
{
  size_t titleHalfLength = floor(m_title.length()/2);
  bool titleIsOdd = m_title.length() % 2;
  // CT_THEME.style("window_border")->apply();
  CPT_OUT
      << CT_THEME.style("window_border")->code()
      << CT_G_BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT
      << cppt::string::repeat(CT_G_BOX_DRAWINGS_HEAVY_HORIZONTAL, ceil(size()->width() / 2) - titleHalfLength - 2) << CT_G_BOX_DRAWINGS_VERTICAL_LIGHT_AND_LEFT_HEAVY
      << CT_THEME.style("window_title")->code()
      << m_title
      << CT_THEME.style("window_border")->code()
      << CT_G_BOX_DRAWINGS_VERTICAL_LIGHT_AND_RIGHT_HEAVY << cppt::string::repeat(CT_G_BOX_DRAWINGS_HEAVY_HORIZONTAL, floor(size()->width() / 2) - titleHalfLength - 2 - titleIsOdd)
      << CT_G_BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT;
  for(ct::type::TCoordinate y = topLeft()->y()+1; y < bottomLeft()->y(); y++)
  {
    CPT_OUT
      << ct::control::CControlCodes::cursorMove(topLeft()->x(), y).code()
      << CT_THEME.style("window_border")->code()
      << CT_G_BOX_DRAWINGS_HEAVY_VERTICAL << cppt::string::repeat(CT_G_SPACE, size()->width()-2) << CT_G_BOX_DRAWINGS_HEAVY_VERTICAL;
  }
  CPT_OUT
    << ct::control::CControlCodes::cursorMove(topLeft()->x(), bottomLeft()->y()).code()
    << CT_THEME.style("window_border")->code()
    << CT_G_BOX_DRAWINGS_HEAVY_UP_AND_RIGHT << cppt::string::repeat(CT_G_BOX_DRAWINGS_HEAVY_HORIZONTAL, size()->width()-2) << CT_G_BOX_DRAWINGS_HEAVY_UP_AND_LEFT;
}

void WWindow::addWidget(ct::widgets::WWidget *widget)
{
  m_widgets.push_back(widget);
}

void WWindow::removeWidget(ct::widgets::WWidget *widget)
{
  m_widgets.erase(std::remove(m_widgets.begin(), m_widgets.end(), widget), m_widgets.end());
}

void WWindow::updateWidgets()
{
  redraw();
  for(ct::widgets::WWidget *widget : m_widgets)
  {
    widget->redraw();
  }
}


}
}
