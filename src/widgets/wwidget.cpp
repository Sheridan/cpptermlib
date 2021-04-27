#include "widgets/wwidget.h"
#include "control/ccontrolcodes.h"
#include "defines/liblog.h"
#include "defines/graphics.h"
#include "layouts/llayout.h"

namespace ct
{
namespace widgets
{

WWidget::WWidget(const ct::primitives::CCoordinate &topLeft, const ct::primitives::CSize &size, ct::widgets::WWidget *m_parent)
  : m_topLeft(new ct::primitives::CCoordinate(topLeft)),
    m_topRight(nullptr),
    m_bottomLeft(nullptr),
    m_bottomRight(nullptr),
    m_size(new ct::primitives::CSize(size)),
    m_parentWidget(m_parent)
{}


WWidget::WWidget(ct::widgets::WWidget *m_parent)
  : m_topLeft(nullptr),
    m_topRight(nullptr),
    m_bottomLeft(nullptr),
    m_bottomRight(nullptr),
    m_size(nullptr),
    m_parentWidget(m_parent)
{}

WWidget::~WWidget()
{
  delete m_topLeft;
  delete m_topRight;
  delete m_bottomLeft;
  delete m_bottomRight;
  delete m_size;
}

const ct::primitives::CSize *WWidget::size()
{
  return m_size;
}

const ct::primitives::CCoordinate *WWidget::topLeft()
{
  return m_topLeft;
}

const ct::primitives::CCoordinate *WWidget::topRight()
{
  if(!m_topRight)
  {
    m_topRight = new ct::primitives::CCoordinate(m_topLeft->x() + m_size->width(), m_topLeft->y());
  }
  return m_topRight;
}

const ct::primitives::CCoordinate *WWidget::bottomLeft()
{
  if(!m_bottomLeft)
  {
    m_bottomLeft = new ct::primitives::CCoordinate(m_topLeft->x(), m_topLeft->y() + m_size->height());
  }
  return m_bottomLeft;
}

const ct::primitives::CCoordinate *WWidget::bottomRight()
{
  if(!m_bottomRight)
  {
    m_bottomRight = new ct::primitives::CCoordinate(m_topLeft->x() + m_size->width(), m_topLeft->y() + m_size->height());
  }
  return m_bottomRight;
}

void WWidget::move(const ct::primitives::CCoordinate &topLeft)
{
  delete m_topLeft    ; m_topLeft     = nullptr;
  delete m_topRight   ; m_topRight    = nullptr;
  delete m_bottomLeft ; m_bottomLeft  = nullptr;
  delete m_bottomRight; m_bottomRight = nullptr;
  m_topLeft = new ct::primitives::CCoordinate(topLeft);
  // TODO: update
}

void WWidget::resize(const ct::primitives::CSize &size)
{
  delete m_size; m_size = nullptr;
  m_size = new ct::primitives::CSize(size);
  // TODO: update
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

ct::primitives::CSize WWidget::clientCanvasSize()
{
  return *m_size;
}

void WWidget::show()
{
  setVisible(true);
}

void WWidget::hide()
{
  setVisible(false);
}

void WWidget::setVisible(const bool &visible)
{
  m_visible = visible;
  draw();
}

const bool& WWidget::visible() const
{
  return m_visible;
}



}
}
