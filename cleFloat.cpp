


#include "cleFloat.h"

#include <string>

namespace clic
{

Float::Float(float obj)
{
    m_Object = obj;
}

float Float::GetObject()
{
    return m_Object;
}

size_t Float::GetSize() const
{
    return 1;
}

std::string Float::GetObjectType() const
{
    return this->ObjectTypeToString(O);
}

std::string Float::GetDataType() const
{
    return this->DataTypeToString(T);
}

} // namespace clic

