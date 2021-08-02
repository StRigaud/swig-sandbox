
import build.swig.python.pyclesperanto as pycle
import numpy as np

# python: numpy array generation, must be float32 for c++ float compatibility
arr1d = np.array([1,2,3,4,5,6,7,8,9], dtype=np.float32)
arr2d = np.array([[1,2,3],[4,5,6]], dtype=np.float32)
arr3d = np.array([[[1,2,3],[4,5,6],[7,8,9]],[[10,11,12],[13,14,15],[16,17,18]]], dtype=np.float32)

# C++: initialisation of GPU
cle = pycle.cle()

# C++: push numpy array in buffer

print("C++ push array 1d:")
buffer_1d = cle.push(arr1d)
buffer_1d.GetInfo()

print("C++ push array 2d:")
buffer_2d = cle.push(arr2d)
buffer_2d.GetInfo()

print("C++ push array 3d:")
buffer_3d = cle.push(arr3d)
buffer_3d.GetInfo()

# C++: create buffer from size/type input

print("C++ create array 3d:")
new_buffer_3d = cle.create(np.array([3,3,3], dtype=np.float32))
new_buffer_3d.GetInfo()

