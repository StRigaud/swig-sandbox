#ifndef __cle_buffer_h
#define __cle_buffer_h

#include <array>

// #include "clic.h"
#include "cleLightObject.h"

namespace clic
{

class Buffer : public LightObject
{
    
private:
    static const LightObject::ObjectType O = ObjectType::cleBuffer;
    DataType T = LightObject::Float;
    
    cl::Buffer m_OclPointer;
    std::array<int, 3> m_Shape = {{1, 1, 1}};

public:

    Buffer() =default;
    Buffer(cl::Buffer);
    Buffer(cl::Buffer, int[3]);

    cl::Buffer GetOclPointer() const;
    int GetSize() const;
    int GetDimensions() const;
    std::array<int, 3> GetShape() const;
    int GetDim0() const;
    int GetDim1() const;
    int GetDim2() const;
    void GetInfo() const;

};

}

#endif // __cle_buffer_h