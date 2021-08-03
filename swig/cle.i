%module pyclesperanto

// Add necessary symbols to generated header
%{
#define SWIG_FILE_WITH_INIT
#include "clic.h"
#include "clesperanto.h"
#include "cleBuffer.h"
#include "cleGPU.h"
#include "cleOperations.h"
%}

%include "numpy.i"

%init %{
import_array();
%}

// push
%apply (float* IN_ARRAY1, int DIM1) {(float* arr, unsigned int d0)};
%apply (float* IN_ARRAY2, int DIM1, int DIM2) {(float* arr, unsigned int d0, unsigned int d1)};
%apply (float* IN_ARRAY3, int DIM1, int DIM2, int DIM3) {(float* arr, unsigned int d0, unsigned int d1, unsigned int d2)};

%apply (float* INPLACE_ARRAY1, int DIM1) {(float* out_arr, unsigned int d0)};
%apply (float* INPLACE_ARRAY2, int DIM1, int DIM2) {(float* out_arr, unsigned int d0, unsigned int d1)};
%apply (float* INPLACE_ARRAY3, int DIM1, int DIM2, int DIM3) {(float* out_arr, unsigned int d0, unsigned int d1, unsigned int d2)};


// Process symbols in header
%include "clic.h"
%include "cleBuffer.h"
%include "clesperanto.h"

%pythoncode %{
def push (self, array):
    if len(array.shape) == 3:
        return self.push_3darray(array)
    elif len(array.shape) == 2:
        return self.push_2darray(array)
    else:
        return self.push_1darray(array)

def create (self, array):
    if type(array).__module__ == 'numpy':
        return self.create_from_array(array)
    else:
        return self.create_from_list(array)

def create_from_array (self, array):
    if len(array.shape) == 3:
        return self.create_3darray(array)
    elif len(array.shape) == 2:
        return self.create_2darray(array)
    else:
        return self.create_1darray(array)

def create_from_list (self, list):
    if len(list) == 3:
        return self.create_ndarray(list[0], list[1], list[2])
    elif len(list) == 2:
        return self.create_ndarray(list[0], list[1])
    else:
        return self.create_ndarray(list[0])

cle.push = push        
cle.create = create 
cle.create_from_array = create_from_array 
cle.create_from_list = create_from_list        
%}