// AUTHOR Alexander_Oleinik alxndr@bu.edu

#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef string BigInt;
typedef vector<double> Poly;


Poly multiply_poly(const Poly &a, const Poly &b)
{
    Poly c (a.size() + b.size() -1, 0);
    for(int i = 0 ; i < a.size() ; i++)
    {
	for(int j = 0 ; j < b.size() ; j++)
        	c[i+j] += a[i]*b[j];
    }
    return c;
}



Poly int_to_poly(const BigInt &a)
{
    Poly c;
    c.resize(a.length());
    int p = 0;
    for(int i=a.length()-1; i>=0 ; i--)
    {
        c[p++] = a[i] - '0';
    }
    return c;
}
BigInt poly_to_int(const Poly &a)
{
    BigInt c;
    c.resize(a.size());
    int p = 0;
    for(int i=a.size()-1; i>=0 ; i--)
    {
        c[p++] = a[i] + '0';
            '0';
    }
    return c;
}

BigInt multiply_int(const BigInt &a, const BigInt &b)
{
    Poly A = int_to_poly(a);
    Poly B = int_to_poly(b);
    Poly C = multiply_poly(A, B);
    int co = 0;
    for(int i = 0; i< C.size() ; i++)
    {
        C[i] += co;
        co = (int)C[i]/10;
        C[i] = (int)C[i] % 10;
    }
    while(co>0)
    {
        C.push_back(co%10);
        co = co/ 10;
    }
    return poly_to_int(C);
}


