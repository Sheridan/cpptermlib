#pragma once
#include <defines/types.h>

namespace ct
{
namespace primitives
{

class CSize
{
public:
  CSize(const ct::type::TSize &width = 0, const ct::type::TSize &height = 0);
  CSize(const CSize &value);
  virtual ~CSize();

  const ct::type::TSize      width()  const;
  const ct::type::TSize      height() const;
  const ct::type::TSizeCount count()  const;

  void srink(const ct::type::TSize &delta);
  void grow (const ct::type::TSize &delta);

  CSize srinked(const ct::type::TSize &delta) const;
  CSize growed (const ct::type::TSize &delta) const;

private:
  ct::type::TSize m_width;
  ct::type::TSize m_height;

};

}
}
