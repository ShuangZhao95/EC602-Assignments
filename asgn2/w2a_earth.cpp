#include <stdlib.h>
#include <math.h>
#include <iostream>


double avo = 6.0221409 * pow(10,23);
//From http://quake.mit.edu/hilstgroup/CoreMantle/EarthCompo.pdf and wikipedia

enum Elements {
    oxygen,
    magnesium,
    silicon,
    iron,
    aluminum,
    calcium,
    nickel,
    hydrogen,
    sulfur,
    chromium,
    sodium,   
    carbon   
};
int ppm[] = 
{
    297000,  //oxygen
    154000, //magnesium
    161000, //silicon
    319000, //iron
    15900,  //aluminum
    17100,  //calcium
    18220,  //nickel
    260,    //hydrogen
    6350,   //sulfur
    4700,   //chromium
    1800,   //sodium
    730     //carbon   
};

int atomic_mass[] = 
{
    15.999,  //oxygen
    24.305, //magnesium
    28.085, //silicon
    55.845, //iron
    26.981,  //aluminum
    40.078,  //calcium
    58.693,  //nickel
    1.00794,    //hydrogen
    32.065,   //sulfur
    51.996,   //chromium
    22.989,   //sodium
    12.010     //carbon
};
int atomic_num[] = 
{
    8,  //oxygen
    12, //magnesium
    14, //silicon
    26, //iron
    13,  //aluminum
    20,  //calcium
    28,  //nickel
    1,    //hydrogen
    16,   //sulfur
    24,   //chromium
    11,   //sodium
    6     //carbon
};

double e_mass = 5.972 * pow(10, 24); 


main()
{
    double num_elec = 0;
    for(int i = 0 ; i < 12 ; i++)
    {
        num_elec =
            e_mass *
            pow(10,6)*
            ( avo / atomic_mass[i] ) *
            atomic_num[i];
    }
    std::cout << num_elec << std::endl;
}

