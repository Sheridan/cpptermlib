#include "cbuffer.h"
#include <iostream>

namespace ct
{
namespace io
{

CBuffer::CBuffer(const primitives::CSize &size)
  : m_bufferSize(size)
{
  resize(m_bufferSize);
}

CBuffer::~CBuffer()
{}

void CBuffer::draw()
{
  m_mutex.lock();
  // CPT_OUT << m_buffer.str();
  m_mutex.unlock();
}

void CBuffer::resize(const primitives::CSize &size)
{
  clear();
  m_mutex.lock();
  m_buffer.resize(size.height());
  for(auto &column : m_buffer)
  {
    column.resize(size.width());
  }
  m_mutex.unlock();
}

void CBuffer::clear()
{
  m_mutex.lock();
  m_buffer.clear();
  m_mutex.unlock();
}

}
}
