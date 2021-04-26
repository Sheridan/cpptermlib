#include "io/ccomposer.h"
#include <algorithm>

namespace ct
{
namespace io
{

CComposer::CComposer() : ct::widgets::WWidget(this)
{}

CComposer::~CComposer()
{}

void CComposer::addWidget(ct::widgets::WWidget *widget)
{
  m_widgets.push_back(widget);
}

void CComposer::removeWidget(ct::widgets::WWidget *widget)
{
  m_widgets.erase(std::remove(m_widgets.begin(), m_widgets.end(), widget), m_widgets.end());
}


}
}
