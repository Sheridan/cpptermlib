#include "tools/options/cjson.h"
#include "defines/liblog.h"

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

nlohmann::json::reference CJson::operator[](const std::string &name)
{
  return m_json[name];
}

#define CT_PUSH_PATH_TO_QUEUE(_path) result.push(_path + "/" + suffix)
std::queue<std::string> CJson::optionsFilesList(const std::string &suffix)
{
  std::queue<std::string> result;
  #ifdef CT_DEBUG
  CT_PUSH_PATH_TO_QUEUE(std::string(CT_PROJECT_PATH) + "/configuration");
  #endif
  CT_PUSH_PATH_TO_QUEUE(CT_APP->currentUser()->home() + "/.config/" + CT_APP->applicationName());
  CT_PUSH_PATH_TO_QUEUE(std::string("/etc/")                        + CT_APP->applicationName());
  CT_PUSH_PATH_TO_QUEUE(std::string("/usr/share/")                  + CT_APP->applicationName());
  return result;
}

void CJson::appendFile(const std::string &filename)
{
  if(cppt::fs::file_exists(filename))
  {
    std::ifstream jsonFile(filename);
    if(m_json.empty())
    {
      m_json = nlohmann::json::parse(jsonFile);
      return;
    }
    nlohmann::json patch = nlohmann::json::parse(jsonFile);
    m_json.merge_patch(patch);
    return;
  }
  CT_LOG_WRN("File " << filename << " does not exist");
}

}
}
}
