import pyclesperanto_prototype as cle
import numpy as np
import time

start_timestart_time = time.time()

image = np.zeros((512,512,100), dtype=np.float32)
valid = np.ones((512,512,100), dtype=np.float32) * 500

start_time = time.time()

exetime = time.time()
cle.select_device()
exetime = (time.time() - exetime)
print("\tinit    : %s seconds ---" % (exetime))

exetime = time.time()
input = cle.push(image)
exetime = (time.time() - exetime)
print("\tpush    : %s seconds ---" % (exetime))
exetime = time.time()
output = cle.create(image.shape)
exetime = (time.time() - exetime)
print("\tcreate  : %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(input, output, 100)
exetime = (time.time() - exetime)
print("\tkernel 0: %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(output, input, 100)
exetime = (time.time() - exetime)
print("\tkernel 1: %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(input, output, 100)
exetime = (time.time() - exetime)
print("\tkernel 2: %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(output, input, 100)
exetime = (time.time() - exetime)
print("\tkernel 3: %s seconds ---" % (exetime))

exetime = time.time()
cle.add_image_and_scalar(input, output, 100)
exetime = (time.time() - exetime)
print("\tkernel 4: %s seconds ---" % (exetime))

exetime = time.time()
result = cle.pull(output)
print("\tpull    : %s seconds ---" % (time.time() - start_time))

print("diff output vs valid = ", np.sum((result-valid).flatten()))
print("final --- %s seconds ---" % (time.time() - start_timestart_time))
