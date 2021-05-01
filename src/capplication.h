#pragma once

#include "cppt/user.h"
#include "io/ccomposer.h"
#include "tools/logger/clogger.h"
#include "tools/options/coptions.h"
#include "tools/options/ctheme.h"
#include "tools/terminal/cterminal.h"
#include <string>

namespace ct
{

class CApplication
{
public:
  CApplication(const std::string &applicationName);
  virtual ~CApplication();
  const std::string &applicationName() const;
  static CApplication *instance();
  static bool active();

  void run();
  void quit();
  void updateUi();

  ct::tools::logger::CLogger     *logger();
  ct::tools::options::COptions   &options();
  ct::tools::options::CTheme     &theme();
  ct::io::CComposer              *composer();
  ct::tools::terminal::CTerminal *terminal();
  const cppt::user::CUser        *currentUser() const;

private:
  bool                            m_active;
  std::string                     m_applicationName;
  ct::tools::logger::CLogger     *m_logger;
  ct::tools::options::COptions   *m_options;
  ct::tools::options::CTheme     *m_theme;
  ct::io::CComposer              *m_composer;
  ct::tools::terminal::CTerminal *m_terminal;
  cppt::user::CUser              *m_currentUser;
};

#define CT_APP      ct::CApplication::instance()
#define CT_OPTIONS  CT_APP->options()
#define CT_THEME    CT_APP->theme()
#define CT_TERMINAL CT_APP->terminal()
#define CT_COMPOSER CT_APP->composer()
#define CT_LOGGER   CT_APP->logger()

}
