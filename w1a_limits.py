#!/usr/bin/python
Table = "{:<6} {:<22} {:<22} {:<22}"
print(Table.format('Bytes','Largest Unsigned Int','Minimum Signed Int','Maximum Signed Int'))
bitlengths = [1,2,4,8]
for b in bitlengths:
    print(Table.format(b, 256**b-1, -1*256**b/2, 1*256**b/2-1))


