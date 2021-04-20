#include "csize.h"
#include "defines/exceptions.h"

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

void CSize::srink(const ct::type::TSize &delta)
{
  CT_ASSERT(m_width  - delta <= 0, out_of_range, "Width is less or equal zero");
  CT_ASSERT(m_height - delta <= 0, out_of_range, "Height is less or equal zero");
  m_width  -= delta;
  m_height -= delta;
}

void CSize::grow(const ct::type::TSize &delta)
{
  m_width  += delta;
  m_height += delta;
}

CSize CSize::srinked(const ct::type::TSize &delta) const
{
  CT_ASSERT(m_width  - delta <= 0, out_of_range, "Width is less or equal zero");
  CT_ASSERT(m_height - delta <= 0, out_of_range, "Height is less or equal zero");
  return CSize(m_width - delta, m_height - delta);
}

CSize CSize::growed(const ct::type::TSize &delta) const
{
  return CSize(m_width + delta, m_height + delta);
}


}
}
