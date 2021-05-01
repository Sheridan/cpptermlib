#pragma once
#include "widgets/wwidget.h"

namespace ct
{
namespace widgets
{

class WPanel : public ct::widgets::WWidget
{
public:
  WPanel(ct::widgets::WWindow *parentWindow = nullptr);
  virtual ~WPanel();

  virtual ct::primitives::CSize clientCanvasSize();
};

}
}
