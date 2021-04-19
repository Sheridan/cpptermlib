#include "csize.h"

namespace ct
{
namespace primitives
{

CSize::CSize(const ct::type::TSize &width, const ct::type::TSize &height)
  : m_width(width),
    m_height(height)
{}

CSize::CSize(const CSize &value)
  : m_width(value.width()),
    m_height(value.height())
{}

CSize::~CSize()
{}

const ct::type::TSize CSize::width() const
{
  return m_width;
}

const ct::type::TSize CSize::height() const
{
  return m_height;
}

const ct::type::TSizeCount CSize::count() const
{
  return m_width * m_height;
}


}
}
