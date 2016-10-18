# AUTHOR test jbc@bu.edu
# AUTHOR jbc jbc@bu.edu
# AUTHOR brower brower@bu.edu

import unittest
import sys
authors=['alxndr@bu.edu']
class PolynomialTestCase(unittest.TestCase):
    def test_sparse(self):
        j = Polynomial([]);
        k = Polynomial([0]);
        self.assertEqual(j, k);

        j = Polynomial([1,2]);
        k = Polynomial([2]);
        j = j-Polynomial([1,0]);
        self.assertEqual(j, k);
    
    def test_addition(self):
        j = Polynomial([1,3,4]);
        k = Polynomial([]);
        k[2]=1;
        k[3]=1;
        self.assertEqual(Polynomial([1,2,3,4]), j+k);
        self.assertEqual(j+k, k+j);
    def test_subtraction(self):
        j = Polynomial([1,3,4]);
        k = Polynomial([1,3,4]);
        j[-2]=-2
        k[-2]=-7
        l = Polynomial([]);
        l[-2]=5
        self.assertEqual(l, j-k);
    def test_sub(self):

        a = Polynomial([5,1,2])
        b = Polynomial([3,4])
        c = Polynomial([5,4,6])
        self.assertEqual((c-b),a)
        self.assertNotEqual((a-c),b)
        self.assertNotEqual((a-c),c-a)
        self.assertIsInstance(a-b, Polynomial)
        
    def test_addition_w_zero(self):
        self.assertEqual(Polynomial([1,2,3,4]), Polynomial([1,2,3,4])+Polynomial([]));

    def test_constructor(self):
        j=Polynomial([5,4,3,2,1])
        self.assertEqual(j[0], 1);
        self.assertEqual(j[1], 2);
        self.assertEqual(j[2], 3);
        self.assertEqual(j[3], 4);
        self.assertEqual(j[4], 5);
        self.assertEqual(j[5], 0); 

    def test_multiplication(self):
        j = Polynomial([1,2,3])
        k = Polynomial([])
        self.assertEqual(j*k, Polynomial([]));
        j = Polynomial([1,2,3])
        k = Polynomial([1,2])
        self.assertEqual(j*k, Polynomial([1,4,7,6]));
        self.assertEqual(j*k, k*j);
        self.assertIsInstance(j*k, Polynomial);
        p=Polynomial([1])
    
    def test_equality(self):
        j = Polynomial([1,2,3])
        k = Polynomial([1,2,3])
        self.assertEqual(j, k);
        j = Polynomial([1,2,3])
        k = Polynomial([1,2,3,4])
        self.assertNotEqual(j, k);
        j = Polynomial([1,2,3,4])
        k = Polynomial([1,2,3])
        self.assertNotEqual(j, k);
        j = Polynomial([1,2,3])
        k = Polynomial([1,2,3])
        k[-1]=5;
        self.assertNotEqual(j, k);

    def test_eval(self):
        j = Polynomial([1,2,3,0])
        j[-1]=4
        self.assertEqual(j.eval(1), 10);
        self.assertEqual(j.eval(2), 4*(2)**(-1) + 3*2+2*4+1*8);
    
    def test_deriv(self):
        j = Polynomial([1,2,3,2])
        j[-1]=4
        k = Polynomial([3,4,3]);
        k[-2]=-4;
        self.assertEqual(j.deriv(), k);
        self.assertIsInstance(j.deriv(), Polynomial);
        self.assertEqual(j.deriv().eval(1), 6);
    
    def test_set(self):
        j = Polynomial([1,2,3,0])
        k = Polynomial([1,2,0,0])
        j[1]=0;
        self.assertEqual(j, k);
    def test_sparse_zeros(self):
        n = 10000
        p = Polynomial([0]*n)
        q = Polynomial()

        p_size =sum(sys.getsizeof(getattr(p,x)) for x in vars(p))
        q_size =sum(sys.getsizeof(getattr(q,x)) for x in vars(q))        
        factor_increase = p_size/q_size
        self.assertEqual(p,q)
        self.assertLess(factor_increase,10,msg='Implementation not sparse, init with {} zeros'.format(n))

if __name__ == '__main__':
        unittest.main()
