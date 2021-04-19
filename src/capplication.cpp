#include "capplication.h"
#include "defines/liblog.h"

namespace ct
{

static CApplication *_instance = nullptr;

CApplication::CApplication(const std::string &applicationName)
  : m_applicationName(applicationName)
{
  _instance = this;
  m_currentUser = new cppt::user::CUser();
  m_logger      = new ct::tools::logger::CLogger();
  m_options     = new ct::tools::options::COptions();
  m_logger->applyOptions();
  m_theme       = new ct::tools::options::CTheme();
  m_terminal    = new ct::CTerminal();
}

CApplication::~CApplication()
{
  delete m_terminal;
  delete m_theme;
  delete m_options;
  delete m_logger;
  delete m_currentUser;
}

const std::string &CApplication::applicationName() const
{
  return m_applicationName;
}

CApplication *CApplication::instance()
{
  #ifdef CT_DEBUG
  if(!CApplication::active())
  {
    CT_STDERR_LOG("First create an instance of the CApplication class");
  }
  #endif // CT_DEBUG
  return _instance;
}

bool CApplication::active()
{
  return _instance != nullptr;
}

ct::tools::logger::CLogger *CApplication::logger()
{
  return m_logger;
}

ct::tools::options::COptions &CApplication::options()
{
  return *m_options;
}

ct::tools::options::CTheme &CApplication::theme()
{
  return *m_theme;
}

ct::CTerminal *CApplication::terminal()
{
  return m_terminal;
}

const cppt::user::CUser *CApplication::currentUser() const
{
  return m_currentUser;
}

}
