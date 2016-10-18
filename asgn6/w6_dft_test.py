# AUTHOR Alex Oleinik alxndr@bu.edu


import unittest
import random as rd
from numpy import array, pi,exp, zeros, fft, shape


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
                #f = xrange(10)
                g = bytearray([1,2])


                # tests

                self.assertRaises(ValueError, DFT,a)
                self.assertRaises(ValueError, DFT,b)
                self.assertRaises(ValueError, DFT,c)
                self.assertRaises(ValueError, DFT,d)
                self.assertRaises(ValueError, DFT,e)
                try:
                    DFT(g)
                except:
                    self.fail("f and g should work")

        def test_DFT_FFT(self):

                # test sequences of length 2 to 20
                for n in range(2,21):
                        #for each length generate and test 10 random sequences of complex numbers
                        for trials in range(10):
                                #generate random sequences of complex numbers
                                a = zeros(n,) * (1+ 1j)
                                b = zeros(n,) * (1+ 1j)
                                for i in range(len(a)):
                                        a[i] = rd.uniform(-1,1) + 1j*rd.uniform(-1,1)
                                        b[i] = rd.uniform(-1,1) + 1j*rd.uniform(-1,1)
                                # run DFT and fft for the same seqeunce and fft for a different sequence
                                dft = DFT(a)
                                ft = fft.fft(a)
                                off = fft.fft(b)
                                #test that each element is almost equal for the same sequence and not almost equal for different sequence
                                for j in range(n):
                                        self.assertAlmostEqual(dft[j],ft[j])
                                        self.assertNotAlmostEqual(dft[j],off[j])
                                        


if __name__ == '__main__':
        unittest.main()
