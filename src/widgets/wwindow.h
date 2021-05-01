#pragma once
#include "widgets/wobject.h"
#include <string>
#include <vector>

namespace ct
{
namespace widgets
{

class WWidget;
class WWindow : public ct::widgets::WObject
{
public:
  WWindow(const std::string &title);
  virtual ~WWindow();

  const std::string title() const;
  void setTitle(const std::string &title);

  void addWidget(ct::widgets::WWidget *widget);
  void removeWidget(ct::widgets::WWidget *widget);

  void updateWidgets();

private:
  std::string m_title;
  std::vector<ct::widgets::WWidget *> m_widgets;

  virtual void draw();
};

}
}
