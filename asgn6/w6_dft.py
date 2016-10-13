from numpy import zeros,exp,array,pi
def DFT(x):
    '''Discrete Fourier Transform'''
    j = 1j;
    try:
        N = len(x)
        X = array(zeros(N), dtype=complex);
        for k in range(N):
            for l in range(N):
                X[k] += x[l]*exp(-j*2*pi*k*l/N)
    except TypeError:
        raise ValueError
    return X
