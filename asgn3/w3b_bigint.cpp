#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef string BigInt;
typedef vector<double> Poly;


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


/*BigInt multiply_int(const BigInt &a, const BigInt &b)
{
    int carryin=0;
    const BigInt *l = a.length() > b.length() ? &a : &b;
    const BigInt *s = a.length() > b.length() ? &b : &a;
    BigInt c;
    for(int i=s->length()-1; i > 0; i--)
    {
        for(int j=l->length()-1; j > 0; j--)
        {
            int n;
            n = carryin + ((int)l->at(i)-'0') * ((int)l->at(i) - '0');
            c.insert(0, 1, '0'+ n%10);
            std::cout << "c[i] is    " << c[0] <<std::endl;
            carryin = n/10;
            std::cout << "carryin is " << carryin <<std::endl;
        }
    }
    while(carryin!=0)
    {
        c.insert(0, 1, '0' + carryin%10);
        carryin = carryin/10;
    }
    return c;
}*/

Poly int_to_poly(const BigInt &a)
{
    Poly c;
    c.resize(a.length());
    int p = 0;
    for(int i=a.length()-1; i>0 ; i--)
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
    for(int i=a.size()-1; i>0 ; i--)
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
        co = C[i]/10;
        C[i] = (int)C[i] % 10;
    }
    while(co>0)
    {
        C.push_back(co%10);
        co = co/ 10;
    }
    return poly_to_int(C);
}

void print_int(const BigInt &a)
{
    for(int i=0; i <= a.length(); i++)
    {
        std::cout << (int)a[i] << " ";
    }
}

int main()
{
    BigInt a = "123456";
    BigInt b = "123456";
    BigInt c = multiply_int(a,b);
    print_int(c);
    std::cout << c << std::endl;
}
