
import build.swig.python.pyclesperanto as pycle
import numpy as np

# python: numpy array generation, must be float32 for c++ float compatibility
arr1d = np.array([1,2,3,4,5,6,7,8,9], dtype=np.float32)
arr2d = np.array([[1,2,3],[4,5,6]], dtype=np.float32)
arr3d = np.array([[[1,2,3],[4,5,6],[7,8,9]],[[10,11,12],[13,14,15],[16,17,18]]], dtype=np.float32)

print("---------------------------------")

# C++: initialisation of GPU
cle = pycle.cle()

print("---------------------------------")

# C++: push array in buffer

print("C++ push array 1d:")
buffer_1d = cle.push(arr1d)
buffer_1d.GetInfo()

print("C++ push array 2d:")
buffer_2d = cle.push(arr2d)
buffer_2d.GetInfo()

print("C++ push array 3d:")
buffer_3d = cle.push(arr3d)
buffer_3d.GetInfo()

# C++: create buffer from shape or array

print("---------------------------------")

print("C++ create array 3d from list:")
new_buffer_3d = cle.create([1,2,3])
new_buffer_3d.GetInfo()

print("C++ create array 2d from list:")
new_buffer_2d = cle.create([2,3])
new_buffer_2d.GetInfo()

print("C++ create array 1d from list:")
new_buffer_1d = cle.create([3])
new_buffer_1d.GetInfo()

print("---------------------------------")

print("C++ create array 3d from array:")
copy_buffer_3d = cle.create(arr3d)
copy_buffer_3d.GetInfo()

print("C++ create array 2d from array:")
copy_buffer_3d = cle.create(arr2d)
copy_buffer_3d.GetInfo()

print("C++ create array 1d from array:")
copy_buffer_3d = cle.create(arr1d)
copy_buffer_3d.GetInfo()

# C++: pull buffer into array

print("---------------------------------")
