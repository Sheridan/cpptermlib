#include "layouts/llayout.h"
#include "widgets/wwidget.h"

namespace ct
{
namespace layouts
{
LLayout::LLayout(ct::widgets::WWidget *parent)
  : m_parentWidget(parent)
{
  m_parentWidget->setLayout(this);
}

LLayout::~LLayout()
{}

void LLayout::addWidget(ct::widgets::WWidget *widget)
{
  m_widgets.push_back(widget);
}

void LLayout::addLayout(ct::layouts::LLayout *layout)
{
  m_layouts.push_back(layout);
}

}
}
