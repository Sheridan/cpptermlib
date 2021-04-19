#include "tools/options/ctheme.h"

namespace ct
{
namespace tools
{
namespace options
{
CTheme::CTheme() : ct::tools::options::CJson(ct::tools::options::CJson::optionsFilesList("themes/default.json"))
{

}

CTheme::~CTheme()
{

}
}
}
}
