import numpy as np
import glob
import time

# Open file input (testcase1.txt -> testcase10.txt)
file_paths = sorted(glob.glob("../Testcase/testcase*.txt"), key=lambda x: int(x.split("testcase")[-1].split(".txt")[0]))
print('       PYTHONSORT ALGORITHM')
for file_path in file_paths:
    start_time = time.perf_counter()  # Start timing
    
    with open(file_path, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = np.array([line.strip() for line in data])
    
    sorted_data = np.sort(data)  # Sort (numpy)
    
    end_time = time.perf_counter()  # End timing
    elapsed_time = (end_time - start_time) * 1000
    
    print(f"{file_path}: {elapsed_time:.3f} ms")
