#pragma once
#include "defines/types.h"

namespace ct
{
namespace primitives
{


class CCoordinate
{
public:
  CCoordinate(const ct::type::TCoordinate &x = 0, const ct::type::TCoordinate &y = 0);
  CCoordinate(const CCoordinate &value);
  virtual ~CCoordinate();

  const ct::type::TCoordinate x() const;
  const ct::type::TCoordinate y() const;

private:
  ct::type::TCoordinate m_x;
  ct::type::TCoordinate m_y;

};

}
}
