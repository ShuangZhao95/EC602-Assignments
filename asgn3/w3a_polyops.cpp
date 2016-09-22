// AUTHOR Alexander_Oleinik alxndr@bu.edu
#include <vector>
#include <iostream>
using namespace std;
typedef vector<double> Poly;

Poly add_poly(const Poly &a, const Poly &b)
{
    Poly c;
    c = a.size() < b.size() ? a : b;
    const Poly *l = a.size() >= b.size() ? &a : &b;
    c.resize( l->size() );
    for(int i = 0 ; i < l.size() ; i++)
    {
        c[i] += l->at(i);
    }
    return c;
}

Poly multiply_poly(const Poly &a, const Poly &b)
{
    Poly c (a.size() + b.size()-1, 0);
    for(int i = 0 ; i < a.size() ; i++)
    {
	for(int j = 0 ; j < b.size() ; j++)
        	c[i+j] += a[i]*b[j];
    }
    return c;
}

void print_vector(const Poly &v)
{
    std::cout << "{ ";
    for(int i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "} ";
}

