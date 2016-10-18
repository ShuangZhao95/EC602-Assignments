import unittest
import random as rd
from numpy import array, pi,exp, zeros, fft, shape
from w6_dft import DFT


class DFTTestCase(unittest.TestCase):

    def test_type(self):
        self.assertTrue(type(array((1,))) == type(DFT([1])))
        self.assertFalse(type([]) == type(DFT([1])))
    
    def test_shape(self):
        x = (1,2,2,3j+2,-1.0)
        a = DFT(x)
        b = zeros(len(x),)
        self.assertEqual(shape(a),shape(b))


    def test_ValueError(self):
        
        #should Raise Error
        a = ["1","1"]
        b = -1
        c = [1,2,3,"nope"]
        d = "nope"
        e = ("a", "b")

        # tests

        self.assertRaises(ValueError, DFT,a)
        self.assertRaises(ValueError, DFT,b)
        self.assertRaises(ValueError, DFT,c)
        self.assertRaises(ValueError, DFT,d)
        self.assertRaises(ValueError, DFT,e)




    def test_DFT_FFT(self):

        
        for n in range(2,21):
            for trials in range(10):
                a = zeros(n,) + 1 * rd.uniform(-1,1) + 1j*rd.uniform(-1,1)
                b = zeros(n,) + 1 * rd.uniform(-1,1) + 1j*rd.uniform(-1,1)
                l = DFT(a)
                m = fft.fft(a)
                for j in range(n):
                    self.assertAlmostEqual(l[j],m[j])
                    # self.assertNotAlmostEqual(DFT(a)[j],fft.fft(b)[j])
                    # self.assertNotAlmostEqual(DFT(b)[j],fft.fft(a)[j])



if __name__ == '__main__':
    unittest.main() 
