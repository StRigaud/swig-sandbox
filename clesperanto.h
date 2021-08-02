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

Buffer push_3darray(float* array, unsigned int n0, unsigned int n1, unsigned int n2);
Buffer push_2darray(float* array, unsigned int n0, unsigned int n1);
Buffer push_1darray(float* array, unsigned int n0);

Buffer create_3darray(float* array, unsigned int n0, unsigned int n1, unsigned int n2);
Buffer create_2darray(float* array, unsigned int n0, unsigned int n1);
Buffer create_1darray(float* array, unsigned int n0);
Buffer create_ndarray(unsigned int n0=1, unsigned int n1=1, unsigned int n2=1);

};

}

#endif // __clesperanto_h
