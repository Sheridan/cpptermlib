#pragma once
#include <string>
#include <queue>
#include <nlohmann/json.hpp>

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
  nlohmann::json::reference operator[](const std::string &name);

protected:
  static std::queue<std::string> optionsFilesList(const std::string &suffix);

private:
  nlohmann::json m_json;
  void appendFile(const std::string &filename);
};
}
}
}
