
import build.swig.python.pyclesperanto as pycle
import numpy as np

# pure python numpy
arr1d = np.array([1,2,3,4,5,6,7,8,9], dtype=np.float32)
arr2d = np.array([[1,2,3],[4,5,6]], dtype=np.float32)
arr3d = np.array([[[1,2,3],[4,5,6],[7,8,9]],[[10,11,12],[13,14,15],[16,17,18]]], dtype=np.float32)

# C++ side: init

gpu = pycle.cle()

# C++ side: push

print("C++ push array 1d:")
buffer_1d = gpu.push(arr1d)
buffer_1d.GetInfo()

print("C++ push array 2d:")
buffer_2d = gpu.push(arr2d)
buffer_2d.GetInfo()

print("C++ push array 3d:")
buffer_3d = gpu.push(arr3d)
buffer_3d.GetInfo()

print("C++ create array 3d:")
new_buffer_3d = gpu.create(np.array([3,3,3], dtype=np.float32))
new_buffer_3d.GetInfo()

