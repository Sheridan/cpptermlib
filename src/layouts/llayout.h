#pragma once
#include "primitives/ccoordinate.h"
#include "primitives/csize.h"
#include <vector>

namespace ct
{

namespace widgets
{
class WWidget;
}

namespace layouts
{

class LLayout
{
public:
  LLayout(ct::widgets::WWidget *parent);
  virtual ~LLayout();
  void addWidget(ct::widgets::WWidget *widget);
  void addLayout(ct::layouts::LLayout *layout);

private:
  ct::widgets::WWidget *m_parentWidget;
  std::vector<ct::widgets::WWidget *> m_widgets;
  std::vector<ct::layouts::LLayout *> m_layouts;

};

}
}
