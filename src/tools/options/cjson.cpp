#include "tools/options/cjson.h"
#include "defines/liblog.h"
#include <json/json.h>
#include <cppt/fs.h>

namespace ct
{
namespace tools
{
namespace options
{

CJson::CJson(std::queue<std::string> files)
{
  while(files.size())
  {
    appendFile(files.front());
    files.pop();
  }
}

CJson::~CJson()
{}

Json::Value &CJson::operator[](const std::string &name)
{
  return m_root[name];
}

#define CT_PUSH_PATH_TO_QUEUE(_path) result.push(_path + "/" + suffix)
std::queue<std::string> CJson::optionsFilesList(const std::string &suffix)
{
  std::queue<std::string> result;
  CT_PUSH_PATH_TO_QUEUE(std::string("/usr/share/")                  + CT_APP->applicationName());
  CT_PUSH_PATH_TO_QUEUE(std::string("/etc/")                        + CT_APP->applicationName());
  CT_PUSH_PATH_TO_QUEUE(CT_APP->currentUser()->home() + "/.config/" + CT_APP->applicationName());
  #ifdef CT_DEBUG
  CT_PUSH_PATH_TO_QUEUE(std::string(CT_PROJECT_PATH) + "/configuration");
  #endif
  return result;
}

void CJson::appendFile(const std::string &filename)
{
  if(cppt::fs::file_exists(filename))
  {
    std::ifstream jsonFile(filename, std::ifstream::binary);
    jsonFile >> m_root;
    return;
  }
  CT_LOG_WRN("File " << filename << " does not exist");
}

}
}
}
