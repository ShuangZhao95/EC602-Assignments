#!/usr/bin/python

def factorial(i):
    if i==1 :
        return 1
    else :
        return i*factorial(i-1)

def num_digits(i):
    d=0
    while (abs(i)>0):
        i = i/10
        d=d+1
    return d
def num_bytes(i):
    b=0
    while ( abs(i) >0):
        i = i/256
        b=b+1
    return b

x = input()
y = input()
f=factorial(x)-factorial(y)
print(f)
print(num_digits(f))
print(num_bytes(f))

