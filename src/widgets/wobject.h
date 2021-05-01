#pragma once
#include "primitives/ccoordinate.h"
#include "primitives/csize.h"

namespace ct
{
namespace widgets
{

class WObject
{
public:
  WObject(const ct::primitives::CCoordinate &topLeft = ct::primitives::CCoordinate(),
          const ct::primitives::CSize &size = ct::primitives::CSize());
  virtual ~WObject();

  const ct::primitives::CSize       *size();
  const ct::primitives::CCoordinate *topLeft();
  const ct::primitives::CCoordinate *topRight();
  const ct::primitives::CCoordinate *bottomLeft();
  const ct::primitives::CCoordinate *bottomRight();

  void move(const ct::primitives::CCoordinate &topLeft);
  void resize(const ct::primitives::CSize &size);

  void show();
  void hide();
  void setVisible(const bool &visible = true);
  const bool &visible() const;

protected:
  const bool &updated() const;
  void update();
  virtual void draw() = 0;
  void redraw();

private:
  bool m_visible;
  bool m_updated;

  ct::primitives::CCoordinate *m_topLeft;
  ct::primitives::CCoordinate *m_topRight;
  ct::primitives::CCoordinate *m_bottomLeft;
  ct::primitives::CCoordinate *m_bottomRight;
  ct::primitives::CSize       *m_size;

  void updateBegin();
  void updateEnd();

};

}
}
