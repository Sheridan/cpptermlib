#include "main.h"
#include "widgets/cwidget.h"

int main(void)
{
  ct::CApplication *app = new ct::CApplication("test");
  // app->terminal()->clear();
  CT_LOG_DBG(CT_OPTIONS["logging"].value("test", "test123"));

  ct::widgets::WWidget *w = new ct::widgets::WWidget(ct::primitives::CCoordinate(10, 10), ct::primitives::CSize(10, 10));
  w->draw();
  w->move(ct::primitives::CCoordinate(120, 20));
  w->resize(ct::primitives::CSize(10, 30));
  w->draw();
  w->move(ct::primitives::CCoordinate(50, 60));
  w->resize(ct::primitives::CSize(40, 20));
  w->draw();
  delete w;

  delete app;
  return 0;
}
// (ct::tools::logger::CLibraryLogger *)logger
