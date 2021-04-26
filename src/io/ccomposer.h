#pragma once
#include <vector>
#include "widgets/wwidget.h"

namespace ct
{
namespace io
{

class CComposer : public ct::widgets::WWidget
{
public:
  CComposer();
  virtual ~CComposer();
  void addWidget(ct::widgets::WWidget *widget);
  void removeWidget(ct::widgets::WWidget *widget);

private:
  std::vector<ct::widgets::WWidget *> m_widgets;
};

}
}
