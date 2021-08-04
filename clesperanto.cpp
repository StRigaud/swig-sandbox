
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

Buffer cle::push_3darray(float* arr, int d0, int d1, int d2)
{
    cl::Buffer obj = CreateBuffer<float>(d0*d1*d2, this->m_gpu);
    WriteBuffer<float>(obj, arr, d0*d1*d2, this->m_gpu);
    int dims[3] = {d0, d1, d2};
    return Buffer (obj, dims);
}

Buffer cle::push_2darray(float* arr, int d0, int d1)
{
    cl::Buffer obj = CreateBuffer<float>(d0*d1, this->m_gpu);
    WriteBuffer<float>(obj, arr, d0*d1, this->m_gpu);
    int dims[3] = {1, d0, d1};
    return Buffer (obj, dims);
}

Buffer cle::push_1darray(float* arr, int d0)
{
    cl::Buffer obj = CreateBuffer<float>(d0, this->m_gpu);
    WriteBuffer<float>(obj, arr, d0, this->m_gpu);
    int dims[3] = {1, 1, d0};
    return Buffer (obj, dims);
}

Buffer cle::create_ndarray(int d0, int d1, int d2)
{
    int dimension[3] = {d0, d1, d2};
    cl::Buffer obj = CreateBuffer<float>(dimension[0]*dimension[1]*dimension[2], this->m_gpu);
    return Buffer (obj, dimension);
}

Buffer cle::create_3darray(float* arr, int d0, int d1, int d2)
{
    return this->create_ndarray(d0, d1, d2);
}

Buffer cle::create_2darray(float* arr, int d0, int d1)
{
    return this->create_ndarray(d0, d1);
}

Buffer cle::create_1darray(float* arr, int d0)
{
    return this->create_ndarray(d0);
}


void cle::pull_3darray(Buffer buffer, float* inplace_arr, int d0, int d1, int d2)
{
    ReadBuffer<float>(buffer.GetOclPointer(), inplace_arr, buffer.GetSize(), this->m_gpu);
}

void cle::pull_2darray(Buffer buffer, float* inplace_arr, int d0, int d1)
{
    ReadBuffer<float>(buffer.GetOclPointer(), inplace_arr, buffer.GetSize(), this->m_gpu);
}

void cle::pull_1darray(Buffer buffer, float* inplace_arr, int d0)
{
    ReadBuffer<float>(buffer.GetOclPointer(), inplace_arr, buffer.GetSize(), this->m_gpu);
}

void cle::pull_1darray_r(Buffer buffer, float** out_arr, int* d0)
{
    float* my_array = (float *)malloc(buffer.GetSize()*sizeof(float));
    ReadBuffer<float>(buffer.GetOclPointer(), my_array, buffer.GetSize(), this->m_gpu);
    *out_arr = my_array;
    *d0 = buffer.GetShape()[2];
}

void cle::pull_2darray_r(Buffer buffer, float** out_arr, int* d0, int* d1)
{
    float* my_array = (float *)malloc(buffer.GetSize()*sizeof(float));
    ReadBuffer<float>(buffer.GetOclPointer(), my_array, buffer.GetSize(), this->m_gpu);
    *out_arr = my_array;
    *d0 = buffer.GetShape()[1];
    *d1 = buffer.GetShape()[2];
}

void cle::pull_3darray_r(Buffer buffer, float** out_arr, int* d0, int* d1, int* d2)
{
    float* my_array = (float *)malloc(buffer.GetSize()*sizeof(float));
    ReadBuffer<float>(buffer.GetOclPointer(), my_array, buffer.GetSize(), this->m_gpu);
    *out_arr = my_array;
    *d0 = buffer.GetShape()[0];
    *d1 = buffer.GetShape()[1];
    *d2 = buffer.GetShape()[2];
}

} // namespace
