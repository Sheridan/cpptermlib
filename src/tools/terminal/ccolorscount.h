#pragma once
#include <string>

namespace ct
{
namespace tools
{
namespace terminal
{

enum class EColorsCount
{
  cc4bit,
  cc8bit,
  cc24bit
};

class CColorsCount
{
public:
  CColorsCount();
  virtual ~CColorsCount();
  void refresh();

  const EColorsCount &count() const;
  const std::string asString() const;

private:
  EColorsCount m_colorsCount;
};

}
}
}
