#ifndef __cleLightObject_h
#define __cleLightObject_h

#include "clic.h"

#include <string>
#include <fstream>

namespace clic
{
    
class LightObject
{   


public:
    enum ObjectType {cleBuffer, cleFloat, cleInt}; 
    enum DataType {Float, Char, UChar, Int, UInt, Short, UShort};

    LightObject() = default;
    virtual ~LightObject() = default;

    virtual std::string GetObjectType() const;
    virtual std::string GetDataType() const;
    bool IsObjectType(ObjectType) const;
    bool IsDataType(DataType) const;

protected:    
    std::string ObjectTypeToString(const ObjectType) const;
    std::string DataTypeToString(const DataType) const;
    DataType StringToDataType(const std::string) const;

private:
    ObjectType O;
    DataType T;
};

} // namespace clic

#endif // __cleLightObject_h