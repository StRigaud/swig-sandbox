%module pyclesperanto

// Add necessary symbols to generated header
%{
#define SWIG_FILE_WITH_INIT
#include "clic.h"
#include "clesperanto.h"
#include "cleBuffer.h"
#include "cleGPU.h"
#include "cleOperations.h"
#include "cleLightObject.h"
#include "cleInt.h"
#include "cleFloat.h"
#include "cleKernel.h"
%}

%include "numpy.i"

%init %{
import_array();
%}

// push
%apply (float* IN_ARRAY1, int DIM1) {(float* arr, int d0)};
%apply (float* IN_ARRAY2, int DIM1, int DIM2) {(float* arr, int d0, int d1)};
%apply (float* IN_ARRAY3, int DIM1, int DIM2, int DIM3) {(float* arr, int d0, int d1, int d2)};

%apply (float* INPLACE_ARRAY1, int DIM1) {(float* inplace_arr, int d0)};
%apply (float* INPLACE_ARRAY2, int DIM1, int DIM2) {(float* inplace_arr, int d0, int d1)};
%apply (float* INPLACE_ARRAY3, int DIM1, int DIM2, int DIM3) {(float* inplace_arr, int d0, int d1, int d2)};

%apply (float** ARGOUTVIEW_ARRAY1, int* DIM1) {(float** out_arr, int* d0)};
%apply (float** ARGOUTVIEW_ARRAY2, int* DIM1, int* DIM2) {(float** out_arr, int* d0, int* d1)};
%apply (float** ARGOUTVIEW_ARRAY3, int* DIM1, int* DIM2, int* DIM3) {(float** out_arr, int* d0, int* d1, int* d2)};


// Process symbols in header
%include "clic.h"
%include "cleBuffer.h"
%include "clesperanto.h"



%pythoncode %{
import numpy as np

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

def pull (self, Buffer, array=None, type=np.float32):
    if array is None:
        array = np.empty((Buffer.GetDim0(), Buffer.GetDim1(), Buffer.GetDim2()), dtype=type)
    if len(array.shape) == 3:
        self.pull_3darray(Buffer, array)
    elif len(array.shape) == 2:
        self.pull_2darray(Buffer, array)
    else:
        self.pull_1darray(Buffer, array)
    return array
    
cle.push = push        
cle.create = create 
cle.pull = pull
cle.create_from_array = create_from_array 
cle.create_from_list = create_from_list        
%}