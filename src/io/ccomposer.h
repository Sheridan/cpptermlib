#pragma once
#include "widgets/wobject.h"
#include "widgets/wwindow.h"
#include <vector>

namespace ct
{
namespace io
{

class CComposer : public ct::widgets::WObject
{
public:
  CComposer();
  virtual ~CComposer();
  void addWindow(ct::widgets::WWindow *window);
  void removeWindow(ct::widgets::WWindow *window);


  void updateWindows();

private:
  std::vector<ct::widgets::WWindow *> m_windows;
  void draw();
};

}
}
