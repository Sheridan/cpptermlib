#pragma once
#include "widgets/wwidget.h"

namespace ct
{
namespace widgets
{

class WPanel : public ct::widgets::WWidget
{
public:
  WPanel(ct::widgets::WWidget *m_parent = nullptr);
  WPanel(const ct::primitives::CCoordinate &topLeft, const ct::primitives::CSize &size, ct::widgets::WWidget *m_parent = nullptr);
  virtual ~WPanel();

  virtual ct::primitives::CSize clientCanvasSize();
};

}
}
