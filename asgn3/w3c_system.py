# AUTHOR Alexander_Oleinik alxndr@bu.edu
import numpy as np

x = np.array(input().split(), dtype=float);
h = np.array(input().split(), dtype=float);
print(*np.convolve(x, h))


