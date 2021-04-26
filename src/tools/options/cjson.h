#pragma once
#include <string>
#include <queue>
#include <json/value.h>

namespace ct
{
namespace tools
{
namespace options
{
class CJson
{
public:
  CJson(std::queue<std::string> files);
  virtual ~CJson();
  Json::Value &operator[](const std::string &name);

protected:
  static std::queue<std::string> optionsFilesList(const std::string &suffix);
  Json::Value &at(const std::string &name);

private:
  Json::Value m_root;
  void appendFile(const std::string &filename);
};
}
}
}
