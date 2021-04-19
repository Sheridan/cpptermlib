#include "ccoordinate.h"

namespace ct
{
namespace primitives
{

CCoordinate::CCoordinate(const ct::type::TCoordinate &x, const ct::type::TCoordinate &y)
  : m_x(x),
    m_y(y)
{}

CCoordinate::CCoordinate(const CCoordinate &value)
  : m_x(value.x()),
    m_y(value.y())
{}

CCoordinate::~CCoordinate()
{}

const ct::type::TCoordinate CCoordinate::x() const
{
  return m_x;
}

const ct::type::TCoordinate CCoordinate::y() const
{
  return m_y;
}

}
}
