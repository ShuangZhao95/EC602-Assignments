#!/usr/bin/env python

import sys
import numpy as np

def main():
    print("argc is",len(sys.argv))
    for i,token in enumerate(sys.argv):
        print('argv of',i,'is',token)

    dtype = sys.argv[1]
    if(len(sys.argv) == 6):
        mode = "SQUARE"
        M = sys.argv[2]
        N = M
        file1 = sys.argv[3]
        file2 = sys.argv[4]
        file3 = sys.argv[5]
    elif(len(sys.sys.argv) == 8):
        mode = "GENERAL"
        N = sys.argv[2]
        M = sys.argv[3]
        L = sys.argv[4]
        file1 = sys.argv[5]
        file2 = sys.argv[6]
        file3 = sys.argv[7]
    m1 = np.loadtxt(file1)
    m2 = np.loadtxt(file2)
    print(m1)
    print(m2)
    print(np.mat(m1)*np.mat(m2))
    np.savetxt(file3, np.mat(m1)*np.mat(m2), delimiter=" ")

if __name__ == "__main__":
        main()
