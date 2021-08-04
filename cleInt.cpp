


#include "cleInt.h"

#include <string>

namespace clic
{

Int::Int(int obj)
{
    m_Object = obj;
}

int Int::GetObject()
{
    return m_Object;
}

size_t Int::GetSize() const
{
    return 1;
}

} // namespace clic

