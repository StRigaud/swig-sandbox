#ifndef __clesperanto_h
#define __clesperanto_h

#include "clic.h"

#include "cleBuffer.h"
#include "cleGPU.h"

namespace clic
{

class cle
{

private: 

    GPU m_gpu;

public:

cle();
~cle()=default;

Buffer push_3darray(float* arr, unsigned int d0, unsigned int d1, unsigned int d2);
Buffer push_2darray(float* arr, unsigned int d0, unsigned int d1);
Buffer push_1darray(float* arr, unsigned int d0);

Buffer create_3darray(float* arr, unsigned int d0, unsigned int d1, unsigned int d2);
Buffer create_2darray(float* arr, unsigned int d0, unsigned int d1);
Buffer create_1darray(float* arr, unsigned int d0);
Buffer create_ndarray(unsigned int d0=1, unsigned int d1=1, unsigned int d2=1);

void pull_3darray(Buffer buffer, float* out_arr, unsigned int d0, unsigned int d1, unsigned int d2);
void pull_2darray(Buffer buffer, float* out_arr, unsigned int d0, unsigned int d1);
void pull_1darray(Buffer buffer, float* out_arr, unsigned int d0);

// Buffer create_from_shape(unsigned int shape[3]);

};

}

#endif // __clesperanto_h
