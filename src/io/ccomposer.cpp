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

void CComposer::addWindow(ct::widgets::WWindow *window)
{
  m_windows.push_back(window);
}

void CComposer::removeWindow(ct::widgets::WWindow *window)
{
  m_windows.erase(std::remove(m_windows.begin(), m_windows.end(), window), m_windows.end());
}


}
}
