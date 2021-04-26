#pragma once
#include "primitives/ccoordinate.h"
#include "primitives/csize.h"

namespace ct
{

namespace layouts
{
class LLayout;
}

namespace widgets
{
class WWidget
{
public:
  WWidget(ct::widgets::WWidget *m_parent = nullptr);
  WWidget(const ct::primitives::CCoordinate &topLeft, const ct::primitives::CSize &size, ct::widgets::WWidget *m_parent = nullptr);
  virtual ~WWidget();

  const ct::primitives::CSize       *size();
  const ct::primitives::CCoordinate *topLeft();
  const ct::primitives::CCoordinate *topRight();
  const ct::primitives::CCoordinate *bottomLeft();
  const ct::primitives::CCoordinate *bottomRight();
  void move(const ct::primitives::CCoordinate &topLeft);
  void resize(const ct::primitives::CSize &size);
  void draw();

  void setLayout(ct::layouts::LLayout *layout);
  virtual ct::primitives::CSize clientCanvasSize();

  void show();
  void hide();
  void setVisible(const bool &visible = true);
  const bool &visible() const;

private:
  void checkParent();

  bool m_visible;

  ct::primitives::CCoordinate *m_topLeft;
  ct::primitives::CCoordinate *m_topRight;
  ct::primitives::CCoordinate *m_bottomLeft;
  ct::primitives::CCoordinate *m_bottomRight;
  ct::primitives::CSize       *m_size;

  ct::widgets::WWidget *m_parentWidget;
  ct::layouts::LLayout *m_layout;
};
}
}
