#!/usr/bin/env python3.5
# AUTHOR James  jcliff@bu.edu
# AUTHOR Jingwei jyz5257@bu.edu
# AUTHOR Alexander alxndr@bu.edu
# AUTHOR Alejandro aaparici@bu.edu

import sys
import re
from PIL import Image
from skimage.io import imread
import numpy as np
import glob
from bitarray import bitarray
import pprint
import re

def tob(a):
    s = ""
    for x in a:
        if(x):
            s += "1"
        else:
            s += "0"
    return s
def revb(a):
    s = ""
    for x in range(0, len(a),3):
        s += a[::-1][x+2]
        s += a[::-1][x+1]
        s += a[::-1][x]
    return s

def main():
    data = dict()
    for n in glob.glob("*.png"):
        ima = imread(n)
        v = np.where( (ima < (255, 255, 255)))
        h = np.where( (np.rot90(ima,3) < (255, 255, 255)))

        t = v[0][0] 
        b = v[0][-1]
        l = h[0][0]
        r = h[0][-1]
       #print(t)
       #print(b)
       #print(l)
       #print(r)

        #print(str(ima)+"\n\n")
       #print(ima[t:b,l:r,:])
       #print("-------------------")
       #print(np.transpose(ima[t:b+1,l:r+1,:],(1,0,2)))

        hsig = np.zeros(3*(r-l+1), dtype=bool)
        vsig = np.zeros(3*(b-t+1), dtype=bool)
        for row in ima[t:b+1,l:r+1,:]==255:
           #print(row.flatten())
           #print("-------------------")
            hsig=np.bitwise_xor(hsig, row.flatten())
        for col in np.transpose(ima[t:b+1,l:r+1,:],(1,0,2))==255:
           #print(col)
           #print("-------------------")
            vsig=np.bitwise_xor(vsig, col.flatten())

        hsig = tob(hsig)
        vsig = tob(vsig)
        rhsig = revb(hsig)
        rvsig = revb(vsig)
        #print(hsig)
        #print(rhsig)
        #print(vsig)
        #print(rvsig)
        data.setdefault(frozenset([hsig,vsig,rhsig,rvsig]), []).append(n)
#    #print.#print(data,  width=1)

    for dkey in data:
        data[dkey] = sorted(data[dkey], key=lambda x: int(re.findall(r'\d+', x)[0]))
    for dkey in sorted(data, key = lambda x: int(re.findall(r'\d+', data[x][0])[0])):
        print(" ".join(data[dkey]))

if __name__ == "__main__":
    main()
