#ifndef __cle_buffer_h
#define __cle_buffer_h

#include <array>

#include "clic.h"

namespace clic
{

class Buffer
{
    
private:

    cl::Buffer m_OclPointer;
    std::array<int, 3> m_Shape = {{1, 1, 1}};

public:

    Buffer() =default;
    Buffer(cl::Buffer);
    Buffer(cl::Buffer, int[3]);

    cl::Buffer GetOclPointer() const;
    int GetSize() const;
    std::array<int, 3> GetShape() const;
    void GetInfo() const;

};

}

#endif // __cle_buffer_h