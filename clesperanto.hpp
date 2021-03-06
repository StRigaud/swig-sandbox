#ifndef __clesperanto_h
#define __clesperanto_h

#include "clic.hpp"

#include "cleDataType.hpp"
#include "cleGPU.hpp"

#include "cleAddImageAndScalarKernel.hpp"

namespace clic
{

class cle
{

private: 

    GPU m_gpu;

public:

    cle();
    ~cle()=default;

    Buffer push_3darray(float* arr, int d0, int d1, int d2);
    Buffer push_2darray(float* arr, int d0, int d1);
    Buffer push_1darray(float* arr, int d0);

    Buffer create_3darray(float* arr, int d0, int d1, int d2);
    Buffer create_2darray(float* arr, int d0, int d1);
    Buffer create_1darray(float* arr, int d0);
    Buffer create_ndarray(int d0=1, int d1=1, int d2=1);

    void pull_3darray(Buffer buffer, float* inplace_arr, int d0, int d1, int d2);
    void pull_2darray(Buffer buffer, float* inplace_arr, int d0, int d1);
    void pull_1darray(Buffer buffer, float* inplace_arr, int d0);

    // void pull_3darray_r(Buffer buffer, float** out_arr, int* d0, int* d1, int* d2);
    // void pull_2darray_r(Buffer buffer, float** out_arr, int* d0, int* d1);
    // void pull_1darray_r(Buffer buffer, float** out_arr, int* d0);

    void add_image_and_scalar(Buffer src, Buffer dst, float scalar);

};

}

#endif // __clesperanto_h
