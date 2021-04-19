#pragma once
#include <mutex>
#include <vector>
#include <defines/types.h>
#include <primitives/csize.h>

namespace ct
{
namespace io
{

class CBuffer
{
public:
  CBuffer(const primitives::CSize &size);
  virtual ~CBuffer();
  void draw();
  void resize(const primitives::CSize &size);

private:
  void clear();
  std::vector<std::vector<CPT_CHAR>> m_buffer;
  primitives::CSize                  m_bufferSize;
  std::mutex                         m_mutex;
};

}
}
