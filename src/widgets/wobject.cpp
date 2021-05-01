#include "widgets/wobject.h"
#include "control/ccontrolcodes.h"

namespace ct
{
namespace widgets
{
WObject::WObject(const ct::primitives::CCoordinate &topLeft, const ct::primitives::CSize &size)
  : m_visible(true),
    m_updated(false),
    m_topLeft(new ct::primitives::CCoordinate(topLeft)),
    m_topRight(nullptr),
    m_bottomLeft(nullptr),
    m_bottomRight(nullptr),
    m_size(new ct::primitives::CSize(size))
{}

WObject::~WObject()
{
  delete m_topLeft;
  delete m_topRight;
  delete m_bottomLeft;
  delete m_bottomRight;
  delete m_size;
}

const ct::primitives::CSize *WObject::size()
{
  return m_size;
}

const ct::primitives::CCoordinate *WObject::topLeft()
{
  return m_topLeft;
}

const ct::primitives::CCoordinate *WObject::topRight()
{
  if(!m_topRight) { m_topRight = new ct::primitives::CCoordinate(m_topLeft->x() + m_size->width(), m_topLeft->y()); }
  return m_topRight;
}

const ct::primitives::CCoordinate *WObject::bottomLeft()
{
  if(!m_bottomLeft) { m_bottomLeft = new ct::primitives::CCoordinate(m_topLeft->x(), m_topLeft->y() + m_size->height()); }
  return m_bottomLeft;
}

const ct::primitives::CCoordinate *WObject::bottomRight()
{
  if(!m_bottomRight) { m_bottomRight = new ct::primitives::CCoordinate(m_topLeft->x() + m_size->width(), m_topLeft->y() + m_size->height()); }
  return m_bottomRight;
}

void WObject::move(const ct::primitives::CCoordinate &topLeft)
{
  delete m_topLeft    ; m_topLeft     = nullptr;
  delete m_topRight   ; m_topRight    = nullptr;
  delete m_bottomLeft ; m_bottomLeft  = nullptr;
  delete m_bottomRight; m_bottomRight = nullptr;
  m_topLeft = new ct::primitives::CCoordinate(topLeft);
  update();
}

void WObject::resize(const ct::primitives::CSize &size)
{
  delete m_size; m_size = nullptr;
  m_size = new ct::primitives::CSize(size);
  update();
}

void WObject::show()
{
  setVisible(true);
}

void WObject::hide()
{
  setVisible(false);
}

void WObject::setVisible(const bool &visible)
{
  m_visible = visible;
  update();
}

const bool &WObject::visible() const
{
  return m_visible;
}

const bool &WObject::updated() const
{
  return m_updated;
}

void WObject::update()
{
  m_updated = false;
}

void WObject::redraw()
{
  if(!updated() && visible())
  {
    updateBegin();
    draw();
    updateEnd();
  }
}

void WObject::updateBegin()
{
  ct::control::CControlCodes::cursorMove(topLeft()).apply();
}

void WObject::updateEnd()
{
  ct::control::ccodes::reset.apply();
  m_updated = true;
}

}
}
