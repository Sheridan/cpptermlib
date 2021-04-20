#include "widgets/wpanel.h"

namespace ct
{
namespace widgets
{

WPanel::WPanel(ct::widgets::WWidget *m_parent)
  : ct::widgets::WWidget(m_parent)
{}

WPanel::WPanel(const ct::primitives::CCoordinate &topLeft, const ct::primitives::CSize &size, ct::widgets::WWidget *m_parent)
  : ct::widgets::WWidget(topLeft, size, m_parent)
{}

WPanel::~WPanel()
{}

ct::primitives::CSize WPanel::clientCanvasSize()
{
 return size()->srinked(1);
}


}
}
