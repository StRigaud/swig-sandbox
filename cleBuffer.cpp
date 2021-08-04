
#include "cleBuffer.h"
#include <iostream>

namespace clic
{

Buffer::Buffer(cl::Buffer ptr)
{
    this->m_OclPointer = ptr; 	
}

Buffer::Buffer(cl::Buffer ptr, int shape[3]) : Buffer(ptr)
{
    for (size_t i = 0; i < 3; i++)
    {
        this->m_Shape[i] = shape[i];
    }   
}

cl::Buffer Buffer::GetOclPointer() const
{
    return m_OclPointer;
}

int Buffer::GetSize() const
{
    return m_Shape[0]*m_Shape[1]*m_Shape[2];
}

int Buffer::GetDimensions() const
{
    int dim = 1;
    if (this->m_Shape[2] > 1)
        dim = 3;
    else if (this->m_Shape[1] > 1)
        dim = 2;
    return dim;
}

int Buffer::GetDim0() const
{
    return this->m_Shape[0];
}

int Buffer::GetDim1() const
{
    return this->m_Shape[1];
}

int Buffer::GetDim2() const
{
    return this->m_Shape[2];
}

std::array<int, 3> Buffer::GetShape() const
{
    return m_Shape;
}

void Buffer::GetInfo() const
{
    std::cout << "Buffer<Float>(" << std::to_string(this->m_Shape[0])+"," << std::to_string(this->m_Shape[1])+"," << std::to_string(this->m_Shape[2]) << ")" << std::endl;
}


}