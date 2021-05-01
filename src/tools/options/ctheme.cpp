#include "tools/options/ctheme.h"

#include "capplication.h"
#include "defines/liblog.h"
#include "defines/terminal_codes.h"
#include "defines/types.h"

namespace ct
{
namespace tools
{
namespace options
{
CTheme::CTheme() : ct::tools::options::CJson(ct::tools::options::CJson::optionsFilesList("themes/default.json"))
{}

CTheme::~CTheme()
{
  for(auto &s : m_styleCache)
  {
    delete s.second;
  }
  m_styleCache.clear();
}

ct::control::CDynamicControlCode *CTheme::style(const std::string &name)
{
  std::string result;

  if(m_styleCache.count(name) == 0)
  {
    switch(CT_TERMINAL->colorsCount()->count())
    {
      case ct::tools::terminal::EColorsCount::cc4bit :
      case ct::tools::terminal::EColorsCount::cc8bit :
      {
        result += CT_IDX_COLOR_FOREGROUND(color(value(name, "foreground").asString()).asString());
        result += CT_IDX_COLOR_BACKGROUND(color(value(name, "background").asString()).asString());
      } break;
      case ct::tools::terminal::EColorsCount::cc24bit:
      {
        Json::Value fg = color(value(name, "foreground").asString());
        Json::Value bg = color(value(name, "background").asString());
        result += CT_24B_COLOR_FOREGROUND(fg[0].asString(), fg[1].asString(), fg[2].asString());
        result += CT_24B_COLOR_BACKGROUND(bg[0].asString(), bg[1].asString(), bg[2].asString());
      } break;
      CT_NOT_ALL_ENUMS_THROW;
    }

    if(value(name, "bold").asBool())          { result += CT_BOLD;          }
    if(value(name, "italic").asBool())        { result += CT_ITALIC;        }
    if(value(name, "underline").asBool())     { result += CT_UNDERLINE;     }
    if(value(name, "strikethrough").asBool()) { result += CT_STRIKETHROUGH; }

    m_styleCache[name] = new ct::control::CDynamicControlCode(result);
  }
  return m_styleCache[name];
}

const Json::Value &CTheme::color(const std::string &name)
{
  if(!at("colors")      .isMember(name))                                   { CT_LOG_CRY("Can not find 'colors." << name <<                                                  "' in themes configuration"); }
  if(!at("colors")[name].isMember(CT_TERMINAL->colorsCount()->asString())) { CT_LOG_CRY("Can not find 'colors." << name << "." << CT_TERMINAL->colorsCount()->asString() << "' in themes configuration"); }
  return at("colors")[name][CT_TERMINAL->colorsCount()->asString()];
}

const Json::Value &CTheme::value(const std::string &styleName, const std::string &valueName)
{
  if(!at("theme").isMember(styleName)) { CT_LOG_CRY("Can not find 'theme." << styleName << "' in themes configuration"); }
  if(!at("theme")[styleName].isMember(valueName))
  {
    if(!at("theme")[styleName].isMember("parent")) { CT_LOG_CRY("Can not find 'theme." << styleName << "." << valueName << "' in themes configuration"); }

    CT_LOG_NFO("Continue searching '" << valueName << "' in 'themes." << styleName << ".parent' style");
    return value(at("theme")[styleName]["parent"].asString(), valueName);
  }
  return at("theme")[styleName][valueName];
}

}
}
}
