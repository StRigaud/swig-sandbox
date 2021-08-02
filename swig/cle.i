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
%apply (float* IN_ARRAY1, int DIM1) {(float* array, unsigned int n0)};
%apply (float* IN_ARRAY2, int DIM1, int DIM2) {(float* array, unsigned int n0, unsigned int n1)};
%apply (float* IN_ARRAY3, int DIM1, int DIM2, int DIM3) {(float* array, unsigned int n0, unsigned int n1, unsigned int n2)};

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
    if len(array.shape) == 3:
        return self.create_3darray(array)
    elif len(array.shape) == 2:
        return self.create_2darray(array)
    else:
        return self.create_1darray(array)

cle.push = push        
cle.create = create        
%}