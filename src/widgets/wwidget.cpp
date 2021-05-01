#include "widgets/wwidget.h"

#include "control/ccontrolcodes.h"
#include "defines/graphics.h"
#include "defines/liblog.h"
#include "layouts/llayout.h"
#include "widgets/wwindow.h"

namespace ct
{
namespace widgets
{

WWidget::WWidget(ct::widgets::WWindow *parentWindow)
  : ct::widgets::WObject(),
    m_parentWindow(parentWindow)
{
  m_parentWindow->addWidget(this);
}

WWidget::~WWidget()
{
  m_parentWindow->removeWidget(this);
}

void WWidget::draw()
{
  // ct::control::CControlCodes::cursorMove(topLeft()).apply();
  // CT_THEME.style("default")->apply();

  // for(ct::type::TCoordinate y = topLeft()->y(); y < bottomLeft()->y(); y++)
  // {
  //   CPT_OUT << CPT_STRING(size()->width(), CT_G_SPACE);
  //   ct::control::CControlCodes::cursorMove(topLeft()->x(), y).apply();
  // }

  // ct::control::ccodes::reset.apply();
}

void WWidget::setLayout(ct::layouts::LLayout *layout)
{
  m_layout = layout;
}



}
}
