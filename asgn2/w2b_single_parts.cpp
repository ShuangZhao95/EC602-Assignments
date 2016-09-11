// single_parts
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

typedef unsigned long int raw32; 
typedef unsigned long long int raw64; 


struct Single_Parts {
	raw32 fraction : 23;
	raw32 exponent : 11;
	raw32 sign : 1;
};

const raw32 MASK_SIGN = 1UL << 31;
const raw32 MASK_BEXP = 0x8 << 23;
const raw32 MASK_FRAC = 0xffffffffffUL;
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
	raw64 x = *reinterpret_cast<raw32*>(&d);

	sp.sign = (x & MASK_SIGN) >> 31;
	sp.exponent = (x & MASK_BEXP) >> 23;
	sp.fraction = (x & MASK_FRAC);
	return sp;
}

double build(Single_Parts sp)
{
	raw64 c
	return *reinterpret_cast<double*>(&sp);
}

// defiVne Single_Parts, build(), and take_apart() for float
const int EXAMPLES = 5;
int main()
{

	double num_from_build;

	double numbers[EXAMPLES]={1.0/3,2,1e100,5e100,6};
	
	// show the structure of the numbers 
	for (int i=0;i<EXAMPLES;i++)
	{   
		// take apart the numbers, then re-build to test that it works.
		
		Single_Parts dp= take_apart(numbers[i]);
	 	num_from_build = build(dp);

	 	cout << endl;
	    print_sp(dp);
	 	cout << numbers[i] << " " << num_from_build  << endl;
	}

    // example of a weird number, negative zero.
    double neg_zero{-0.0};

    cout << endl; 
    cout << neg_zero << endl;

    print_sp(take_apart(neg_zero));

    return 0;
}
