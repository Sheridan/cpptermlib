#include "main.h"
#include "widgets/wwindow.h"

int main(void)
{
  ct::CApplication *app = new ct::CApplication("test");
  CT_LOG_NFO(CT_OPTIONS["logging"].get("level", "debug").asString());

  ct::widgets::WWindow *w = new ct::widgets::WWindow("First windows");
  w->move(ct::primitives::CCoordinate(10, 10));
  w->resize(ct::primitives::CSize(40, 20));
  w->draw();

  w->move(ct::primitives::CCoordinate(40, 40));
  w->resize(ct::primitives::CSize(20, 10));
  w->draw();

  w->move(ct::primitives::CCoordinate(100, 80));
  w->resize(ct::primitives::CSize(20, 30));
  w->draw();

  w->move(ct::primitives::CCoordinate(50, 60));
  w->resize(ct::primitives::CSize(60, 30));
  w->draw();

  w->move(ct::primitives::CCoordinate(60, 10));
  w->draw();

  w->move(ct::primitives::CCoordinate(70, 20));
  w->draw();

  w->move(ct::primitives::CCoordinate(80, 40));
  w->draw();

  delete w;

  delete app;
  return 0;
}
// (ct::tools::logger::CLibraryLogger *)logger
