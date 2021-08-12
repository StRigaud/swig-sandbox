import pyclesperanto_prototype as cle
import numpy as np
import time

image = np.ones((512,512,100), dtype=np.float32)
valid = np.ones((512,512,100), dtype=np.float32) * 101

start_time = time.time()


# C++: initialisation of GPU
cle.select_device()

input = cle.push(image)
output = cle.create(image.shape)

exetime = time.time()
cle.add_image_and_scalar(input, output, 100)
exetime = (time.time() - exetime)
print("--- %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(output, input, 100)
exetime = (time.time() - exetime)
print("--- %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(input, output, 100)
exetime = (time.time() - exetime)
print("--- %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(output, input, 100)
exetime = (time.time() - exetime)
print("--- %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(input, output, 100)
exetime = (time.time() - exetime)
print("--- %s seconds ---" % (exetime))

result = cle.pull(output)
print("--- %s seconds ---" % (time.time() - start_time))
