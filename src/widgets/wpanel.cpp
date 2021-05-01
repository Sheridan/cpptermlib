#include "widgets/wpanel.h"

namespace ct
{
namespace widgets
{

WPanel::WPanel(ct::widgets::WWindow *parentWindow)
  : ct::widgets::WWidget(parentWindow)
{}

WPanel::~WPanel()
{}

ct::primitives::CSize WPanel::clientCanvasSize()
{
 return size()->srinked(1);
}


}
}
