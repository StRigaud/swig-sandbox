
import build.swig.python.pyclesperanto as pycle
import numpy as np

# python: numpy array generation, must be float32 for c++ float compatibility
arr1d = np.array([1,2,3,4,5,6,7,8,9], dtype=np.float32)
arr2d = np.array([[1,2,3],[4,5,6]], dtype=np.float32)
arr3d = np.array([[[1,2,3],[4,5,6],[7,8,9]],[[10,11,12],[13,14,15],[16,17,18]]], dtype=np.float32)

print("1d shape:",arr1d.shape)
print("2d shape:",arr2d.shape)
print("3d shape:",arr3d.shape)

print("---------------------------------")

# C++: initialisation of GPU
cle = pycle.cle()

print("---------------------------------")

# C++: push array in buffer
print("C++ push array 3d:")
buffer_3d = cle.push(arr3d)
buffer_3d.GetInfo()

print("C++ push array 2d:")
buffer_2d = cle.push(arr2d)
buffer_2d.GetInfo()

print("C++ push array 1d:")
buffer_1d = cle.push(arr1d)
buffer_1d.GetInfo()

# C++: create buffer from shape or array

print("---------------------------------")

print("C++ create array 3d from list:")
buffer_3d_from_list = cle.create(arr3d.shape)
buffer_3d_from_list.GetInfo()

print("C++ create array 2d from list:")
buffer_2d_from_list = cle.create(arr2d.shape)
buffer_2d_from_list.GetInfo()

print("C++ create array 1d from list:")
buffer_1d_from_list = cle.create(arr1d.shape)
buffer_1d_from_list.GetInfo()

print("---------------------------------")

print("C++ create array 3d from array:")
buffer_3d_from_array = cle.create(arr3d)
buffer_3d_from_array.GetInfo()

print("C++ create array 2d from array:")
buffer_3d_from_array = cle.create(arr2d)
buffer_3d_from_array.GetInfo()

print("C++ create array 1d from array:")
buffer_3d_from_array = cle.create(arr1d)
buffer_3d_from_array.GetInfo()

# C++: pull buffer into array

print("---------------------------------")

print("Pull C++ 3d buffer into inplace array:")
array3d_pull_from_buffer = np.zeros_like(arr3d)
cle.pull(buffer_3d, array3d_pull_from_buffer)
print(array3d_pull_from_buffer)

print("Pull C++ 2d buffer into inplace array:")
array2d_pull_from_buffer = np.zeros_like(arr2d)
cle.pull(buffer_2d, array2d_pull_from_buffer)
print(array2d_pull_from_buffer)

print("Pull C++ 1d buffer into inplace array:")
array1d_pull_from_buffer = np.zeros_like(arr1d)
cle.pull(buffer_1d, array1d_pull_from_buffer)
print(array1d_pull_from_buffer)

print("---------------------------------")

print("Pull C++ 1d buffer into new array:")
array1d_pull_from_buffer = cle.pull(buffer_1d)
print(array1d_pull_from_buffer)

print("Pull C++ 2d buffer into new array:")
array2d_pull_from_buffer = cle.pull(buffer_2d)
print(array2d_pull_from_buffer)

print("Pull C++ 3d buffer into new array:")
array3d_pull_from_buffer = cle.pull(buffer_3d)
print(array3d_pull_from_buffer)

# Test executing a kernel
print("---------------------------------")

image = np.array([[[1,2,3],[4,5,6],[7,8,9]],[[10,11,12],[13,14,15],[16,17,18]]], dtype=np.float32)

input = cle.push(image)
output = cle.create(image)

cle.add_image_and_scalar(input, output, 100)

result = cle.pull(output)

print(result)
