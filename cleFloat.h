

#ifndef __cleFloat_h
#define __cleFloat_h

#include "cleLightObject.h"

#include <string>
#include <fstream>

namespace clic
{

class Float : public LightObject
{
private:
    static const LightObject::ObjectType O = ObjectType::cleFloat;
    static const LightObject::DataType T = DataType::Float;

    float m_Object;    

public:
    Float(float);

    float GetObject();
    size_t GetSize() const;

    std::string GetObjectType() const;
    std::string GetDataType() const;

};

} // namespace clic

#endif // __cleScalar_h
