#pragma once
#include "primitives/ccoordinate.h"
#include "primitives/csize.h"

namespace ct
{
namespace widgets
{
class WWidget
{
public:
  WWidget();
  WWidget(const ct::primitives::CCoordinate &topLeft, const ct::primitives::CSize &size);
  virtual ~WWidget();

  const ct::primitives::CSize       *size();
  const ct::primitives::CCoordinate *topLeft();
  const ct::primitives::CCoordinate *topRight();
  const ct::primitives::CCoordinate *bottomLeft();
  const ct::primitives::CCoordinate *bottomRight();
  void move(const ct::primitives::CCoordinate &topLeft);
  void resize(const ct::primitives::CSize &size);
  void draw();

private:
  ct::primitives::CCoordinate *m_topLeft;
  ct::primitives::CCoordinate *m_topRight;
  ct::primitives::CCoordinate *m_bottomLeft;
  ct::primitives::CCoordinate *m_bottomRight;
  ct::primitives::CSize       *m_size;
};
}
}
