# AUTHOR test jbc@bu.edu
# AUTHOR jbc jbc@bu.edu
# AUTHOR brower brower@bu.edu
import unittest

authors=['test@bu.edu','jbc@bu.edu','brower@bu.edu']

class PolynomialTestCase(unittest.TestCase):
    def test_sparse(self):
        j = Polynomial();
        k = Polynomial([0]);
        self.assertEqual(j, k);

        j = Polynomial([1,2]);
        k = Polynomial([2]);
        j = j-Polynomial([1,0]);
        self.assertEqual(j, k);

    def test_addition(self):
        j = Polynomial([1,3,4]);
        k = Polynomial();
        k[2]=1;
        k[3]=1;
        self.assertEqual(Polynomial([1,2,3,4]), j+k);
    def test_subtraction(self):
        j = Polynomial([1,3,4]);
        k = Polynomial([4]);
        k[1]=3;
        k[2]=1;
        self.assertEqual(Polynomial(), j-k);

    def test_addition_w_zero(self):
        self.assertEqual(Polynomial([1,2,3,4]), Polynomial([1,2,3,4])+Polynomial());

    def test_constructor(self):
        j=Polynomial([5,4,3,2,1])
        self.assertEqual(j[0], 1);
        self.assertEqual(j[1], 2);
        self.assertEqual(j[2], 3);
        self.assertEqual(j[3], 4);
        self.assertEqual(j[4], 5);
        self.assertEqual(j[5], 0);


