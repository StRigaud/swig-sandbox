

#ifndef __cleInt_h
#define __cleInt_h

#include "cleLightObject.h"

#include <string>
#include <fstream>

namespace clic
{

class Int : public LightObject
{
private:
    static const LightObject::ObjectType O = LightObject::cleInt;
    static const LightObject::DataType T = LightObject::Int;

    int m_Object;    

public:
    Int(int);

    int GetObject();
    size_t GetSize() const;

};

} // namespace clic

#endif // __cleInt_h
