#include "tools/terminal/ccolorscount.h"
#include "defines/liblog.h"

namespace ct
{
namespace tools
{
namespace terminal
{

CColorsCount::CColorsCount() :
  m_colorsCount(EColorsCount::cc4bit)
{
  refresh();
}

CColorsCount::~CColorsCount()
{}

void CColorsCount::refresh()
{
  m_colorsCount = EColorsCount::cc24bit;
  CT_LOG_DBG("Terminal supported colors: " << asString());
}

const EColorsCount& CColorsCount::count() const
{
  return m_colorsCount;
}

const std::string CColorsCount::asString() const
{
  switch(m_colorsCount)
  {
    case EColorsCount::cc4bit : return "16"       ; break;
    case EColorsCount::cc8bit : return "256"      ; break;
    case EColorsCount::cc24bit: return "truecolor"; break;
      CT_NOT_ALL_ENUMS_THROW;
  }
  return "";
}



}
}
}
