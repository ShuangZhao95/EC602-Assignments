// single_parts
#include <iostream>
#include <iomanip>

using namespace std;

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

// define Single_Parts, build(), and take_apart() for float

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