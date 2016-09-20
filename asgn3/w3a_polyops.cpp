#include <vector>
#include <iostream>
using namespace std;
typedef vector<double> Poly;

Poly add_poly(const Poly &a, const Poly &b)
{
    Poly c;
    c = a.size() < b.size() ? a : b;
    const Poly *l = a.size() >= b.size() ? &a : &b;
    c.resize( c.size() );
    for(int i = 0 ; i < l->size() ; i++)
    {
        c[i] += l->at(i);
    }
    return c;
}

Poly multiply_poly(const Poly &a, const Poly &b)
{
    Poly c (a.size() + b.size(), 0);
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

main()
{
    Poly a {1, 3, 5, 6};
    Poly b {1, 2, 3, 4, 5};
    Poly c = add_poly(a, b);
    Poly d = multiply_poly(a, b);
    print_vector(a);
    std::cout << " + ";
    print_vector(b);
    std::cout << " = ";
    print_vector(c);
    std::cout << std::endl;
    print_vector(a);
    std::cout << " . ";
    print_vector(b);
    std::cout << " = ";
    print_vector(d);
    std::cout << std::endl;
}
