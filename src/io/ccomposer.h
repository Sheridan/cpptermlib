#pragma once
#include <vector>
#include "widgets/wwindow.h"

namespace ct
{
namespace io
{

class CComposer : public ct::widgets::WWidget
{
public:
  CComposer();
  virtual ~CComposer();
  void addWindow(ct::widgets::WWindow *window);
  void removeWindow(ct::widgets::WWindow *window);

private:
  std::vector<ct::widgets::WWindow *> m_windows;
};

}
}
