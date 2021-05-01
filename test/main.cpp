#include "main.h"
#include <csignal>

void signal_handler(int signal)
{
  app->quit();
}

int main(void)
{
  app = new ct::CApplication("test");
  CT_LOG_NFO(CT_OPTIONS["logging"].get("level", "debug").asString());
  std::signal(SIGINT, signal_handler);

  ct::widgets::WWindow *w = new ct::widgets::WWindow("First windows");
  w->move(ct::primitives::CCoordinate(30, 30));
  w->resize(ct::primitives::CSize(20, 20));

  app->run();

  delete app;
  return 0;
}
