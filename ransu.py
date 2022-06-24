import numpy as np
import time
start_time = time.perf_counter()
M = 10 ** 8

print("u=0")
a = np.random.normal(0, 1, M)
print(np.count_nonzero(a > 0) / M)

print("u=-0.1")
a = np.random.normal(-0.1, 1, M)
print(np.count_nonzero(a > 0) / M)

print("u=-0.2")
a = np.random.normal(-0.2, 1, M)
print(np.count_nonzero(a > 0) / M)

end_time = time.perf_counter()
print("end time")
elapsed_time = end_time - start_time
print(elapsed_time)