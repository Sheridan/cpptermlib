#include "tools/options/coptions.h"

namespace ct
{
namespace tools
{
namespace options
{

COptions::COptions() : ct::tools::options::CJson(ct::tools::options::CJson::optionsFilesList("configuration.json"))
{

}

COptions::~COptions()
{

}
}
}
}
