#include "..\include\RAM_BASE.h"

RAM_BASE::RAM_BASE()
{}

RAM_BASE::RAM_BASE(const uint64 &a_typeAddr)
{
    m_format = a_typeAddr;
}//ctor

RAM_BASE::~RAM_BASE()
{}
