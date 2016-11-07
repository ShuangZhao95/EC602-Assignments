import subprocess
import os
import sys
import numpy as np



dtype = sys.argv[1]
nlist = eval(sys.argv[2])
ntrials = int(sys.argv[3])
print(sys.argv)

subprocess.run(["g++","-std=c++14","w8c_multiply.cpp","-O0","-o","w8c_multiply_0"],stdout=subprocess.PIPE)
subprocess.run(["g++","-std=c++14","w8c_multiply.cpp","-O1","-o","w8c_multiply_1"],stdout=subprocess.PIPE)
subprocess.run(["g++","-std=c++14","w8c_multiply.cpp","-O2","-o","w8c_multiply_2"],stdout=subprocess.PIPE)

for j in nlist:
    for i in range(0, ntrials):
    np.savetxt("randmatrix", np.random.randint(100, size=(int(j), int(j) )), fmt ='%d') 
        t1 = subprocess.run(["time", "./w8p_multiply", dtype, str(j), "randmatrix", "randmatrix", "outfile"],stdout=subprocess.PIPE)
        subprocess.run(["./w8c_multiply_0", dtype, str(j), "randmatrix", "randmatrix", "outfile"],stdout=subprocess.PIPE)
        subprocess.run(["./w8c_multiply_1", dtype, str(j), "randmatrix", "randmatrix", "outfile"],stdout=subprocess.PIPE)
        subprocess.run(["./w8c_multiply_2", dtype, str(j), "randmatrix", "randmatrix", "outfile"],stdout=subprocess.PIPE)
        
