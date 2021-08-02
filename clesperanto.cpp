
#include <iostream>


#include "clesperanto.h"
#include "cleOperations.h"

namespace clic
{

cle::cle()
{
    this->m_gpu = GPU("GTX");
    this->m_gpu.GetSelectedDeviceInfo();
}

Buffer cle::push_3darray(float* array, unsigned int n0, unsigned int n1, unsigned int n2)
{
    cl::Buffer obj = CreateBuffer<float>(n0*n1*n2, this->m_gpu);
    WriteBuffer<float>(obj, array, n0*n1*n2, this->m_gpu);
    unsigned int dims[3] = {n0, n1, n2};
    return Buffer (obj, dims);
}

Buffer cle::push_2darray(float* array, unsigned int n0, unsigned int n1)
{
    cl::Buffer obj = CreateBuffer<float>(n0*n1, this->m_gpu);
    WriteBuffer<float>(obj, array, n0*n1, this->m_gpu);
    unsigned int dims[3] = {1, n0, n1};
    return Buffer (obj, dims);
}

Buffer cle::push_1darray(float* array, unsigned int n0)
{
    cl::Buffer obj = CreateBuffer<float>(n0, this->m_gpu);
    WriteBuffer<float>(obj, array, n0, this->m_gpu);
    unsigned int dims[3] = {1, 1, n0};
    return Buffer (obj, dims);
}



Buffer cle::create_ndarray(unsigned int n0, unsigned int n1, unsigned int n2)
{
    unsigned int dimension[3] = {n0, n1, n2};
    cl::Buffer obj = CreateBuffer<float>(dimension[0]*dimension[1]*dimension[2], this->m_gpu);
    return Buffer (obj, dimension);
}

Buffer cle::create_3darray(float* array, unsigned int n0, unsigned int n1, unsigned int n2)
{
    return this->create_ndarray(n0, n1, n2);
}

Buffer cle::create_2darray(float* array, unsigned int n0, unsigned int n1)
{
    return this->create_ndarray(n0, n1);
}

Buffer cle::create_1darray(float* array, unsigned int n0)
{
    return this->create_ndarray(n0);
}


}
