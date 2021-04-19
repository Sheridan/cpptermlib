#pragma once
#include "defines/types.h"

namespace ct
{
namespace control
{

template<typename T>
class CControlCode
{
public:
  constexpr CControlCode(const T code)
    : m_code(code) {}

  const T operator()() const
  {
    return m_code;
  }
  void apply() const
  {
    std::cout << m_code;
  }

private:
  const T m_code;
};

}
}
