


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

} // namespace clic

