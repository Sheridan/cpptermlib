#pragma once
#include "widgets/wobject.h"

namespace ct
{
namespace layouts { class LLayout; }
namespace widgets
{
class WWindow;
class WWidget : public ct::widgets::WObject
{

  friend class WWindow;

public:
  WWidget(ct::widgets::WWindow *parentWindow = nullptr);
  virtual ~WWidget();

  virtual void draw();

  void setLayout(ct::layouts::LLayout *layout);


private:
  ct::widgets::WWindow *m_parentWindow;
  ct::layouts::LLayout *m_layout;
};
}
}
