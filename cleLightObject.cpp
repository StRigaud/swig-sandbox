
#include "cleLightObject.h"

namespace clic
{

std::string LightObject::ObjectTypeToString(const ObjectType o) const
{
    switch (o)
    {
        case cleBuffer:  return "cleBuffer";
        case cleFloat:   return "cleFloat";
        case cleInt:     return "cleInt";
        default:         return "Unknown";
    }
}

std::string LightObject::DataTypeToString(const DataType t) const
{
    switch (t)
    {
        case Float:  return "float";
        case Char:   return "char";
        case UChar:  return "uchar";
        case Int:    return "int";
        case UInt:   return "uint";
        case Short:  return "short";
        case UShort: return "ushort";
        default:     return "unknown";
    }
}


typename LightObject::DataType LightObject::StringToDataType(const std::string t) const
{
    if(t == "float")       return DataType::Float;
    else if(t == "char")   return DataType::Char;
    else if(t == "uchar")  return DataType::UChar;
    else if(t == "int")    return DataType::Int;
    else if(t == "uint")   return DataType::UInt;
    else if(t == "short")  return DataType::Short;
    else if(t == "ushort") return DataType::UShort;
    else                   return DataType::Float;  
}


std::string LightObject::GetObjectType() const
{
    return this->ObjectTypeToString(O);
}

std::string LightObject::GetDataType() const
{
    return this->DataTypeToString(T);
}

bool LightObject::IsObjectType(LightObject::ObjectType str) const
{
    return this->O == str;
}

bool LightObject::IsDataType(LightObject::DataType str) const
{
    return this->T == str;
}


} // namespace clic

