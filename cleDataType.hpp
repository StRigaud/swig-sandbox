#ifndef __datatype_hpp
#define __datatype_hpp

#include "clic.hpp"
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <array>

#define REGISTER_PARSE_TYPE(X) template <> const char* TypeParseTraits<X>::name = #X

namespace clic
{

template<typename T>
struct TypeParseTraits { static const char* name; };




class LightObject
{
public: 
    LightObject() =default;
    virtual ~LightObject() = default;

    virtual const char* GetDataType() const =0;
    virtual bool IsDataType(const char*) const =0;    
    virtual const char* GetObjectType() const =0;
    virtual bool IsObjectType(const char*) const =0;
};

template<class T>
class Scalar : public LightObject
{
private:
    T m_Object;

public: 

    Scalar() =default;
    Scalar(T _d) : m_Object(_d) {}
    ~Scalar() =default;

    T GetObject() const { return this->m_Object; }

    const char* GetDataType() const { return TypeParseTraits<T>::name; }

    bool IsDataType(const char* str) const
    {
        size_t size = sizeof(str)/sizeof(char);
        return strncmp(TypeParseTraits<T>::name, str, size) == 0;
    }

    const char* GetObjectType() const { return "scalar"; }   

    bool IsObjectType(const char* str) const
    {
        size_t size = sizeof(str)/sizeof(char);
        return strncmp("scalar", str, size) == 0;
    }
    
};


class Buffer : public LightObject
{
public: 

    enum DataType { FLOAT, DOUBLE, INT, UINT, CHAR, UCHAR };

    Buffer() =default;
    Buffer(cl::Buffer, DataType =FLOAT);
    Buffer(cl::Buffer, std::array<int,3>, DataType =FLOAT);
    Buffer(cl::Buffer, int[3], DataType =FLOAT);
    ~Buffer() =default;

    cl::Buffer GetObject() const;
    
    int GetWidth() const;
    int GetHeight() const;
    int GetDepth() const;
    int GetDimension() const;
    int GetSize() const;
    std::array<int,3> GetShape() const;

    const char* GetDataType() const;
    bool IsDataType(const char*) const;
    const char* GetObjectType() const;
    bool IsObjectType(const char*) const;

private:
    cl::Buffer m_Object;
    std::array<int,3> m_Shape = {1, 1, 1};
    int m_Dimension = 1;
    DataType m_Type = Buffer::FLOAT;
};

}

#endif //__datatype_hpp