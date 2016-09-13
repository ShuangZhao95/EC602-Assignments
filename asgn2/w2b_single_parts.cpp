// single_parts
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

#define EXAMPLES 5

typedef unsigned long int raw32; 
typedef unsigned long long int raw64; 


struct Single_Parts {
	raw32 fraction : 23;
	raw32 exponent : 8;
	raw32 sign : 1;
};

const raw64 MASK_SIGN = 1UL << 63;
const raw64 MASK_BEXP = 0x07ffULL << 52;
const raw64 MASK_FRAC = 0xfffffffffffffULL;
// print out the parts of the structure Single_Parts
void print_sp(Single_Parts sp) 
{ 
  if (sp.sign==1)
		 cout << "negative"  << endl;
  else 
  		cout << "positive" << endl;

 cout << hex  
      << setfill('0') 
      << "expo: " << sp.exponent << endl
      << "frac: " << sp.fraction << endl
      << dec;
}

Single_Parts take_apart(double d)
{
	Single_Parts sp;
	raw64 x = *reinterpret_cast<raw64*>(&d);
        std::cout << std::bitset<64>(x) <<  std::endl;
	sp.sign = (x & MASK_SIGN) >> 63;
//        std::cout <<  std::bitset<1>(sp.sign) <<  std::endl;
	sp.exponent = (x & MASK_BEXP) >> 52 + 3 ;
//        std::cout <<  std::bitset<8>(sp.exponent) <<  std::endl;
	sp.fraction = (x & MASK_FRAC) >> 52 - 23;
//        std::cout <<  std::bitset<23>(sp.fraction) <<  std::endl;
	return sp;
}

double build(Single_Parts sp)
{
	raw64 c = 0;
        c = ( (raw64)sp.sign << 63) +
            ( (raw64)sp.exponent << 52+3) +
            ((raw64)sp.fraction << 52 -23 );
        std::cout << std::bitset<64>(c) <<  std::endl;

	return *reinterpret_cast<double*>(&c);
}

// defiVne Single_Parts, build(), and take_apart() for float
int main()
{

	double num_from_build;

	double numbers[EXAMPLES]={1.0/3,2,1.3e10,3e11,6};
	
	// show the structure of the numbers 
	for (int i=0;i<EXAMPLES;i++)
	{   
		// take apart the numbers, then re-build to test that it works.
		
		Single_Parts s = take_apart(numbers[i]);
	 	num_from_build = build(s);

	 	cout << endl;
	    print_sp(s);
	 	cout << numbers[i] << " " << num_from_build  << endl;
	}

    // example of a weird number, negative zero.
    double neg_zero{-0.0};

    cout << endl; 
    cout << neg_zero << endl;

    print_sp(take_apart(neg_zero));

    return 0;
}
