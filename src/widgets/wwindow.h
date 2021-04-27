#pragma once
#include <string>
#include "widgets/wwidget.h"


namespace ct
{
namespace widgets
{

class WWindow : public ct::widgets::WWidget
{
public:
  WWindow(const std::string &title);
  virtual ~WWindow();
  const std::string title() const;
  void setTitle(const std::string &title);
  virtual void draw();

private:
  std::string m_title;
};

}
}
