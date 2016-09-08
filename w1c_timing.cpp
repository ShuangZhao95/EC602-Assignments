/*
 * =====================================================================================
 *
 *       Filename:  w1c_timing.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/06/2016 09:17:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Oleinik (ax), alxndr@bu.edu
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <climits>


main()
{
    // Times to wrap around in ms
    double wrap_around_uint_s, wrap_around_uint, wrap_around_uint_l;
    clock_t start_clock, end_clock;
    
    short unsigned int ushort=0;
    unsigned int uint=0;
    long unsigned int ulong=0;

    // For short unsigned int
    start_clock = clock();
    while( ++ushort != 0 )
        ;
    end_clock = clock();
    wrap_around_uint_s = (double)(end_clock - start_clock);
    std::cout   << "short unsigned int time (microseconds): "
                << wrap_around_uint_s
                << std::endl;
    // For unsigned int
    start_clock = clock();
    while( ++uint != 0 )
        ;
    end_clock = clock();
    wrap_around_uint = (double)(end_clock - start_clock);
    std::cout   << "unsigned int time (seconds):  " 
                << wrap_around_uint/CLOCKS_PER_SEC
                << std::endl;
    
    // For long unsigned int
    wrap_around_uint_l = wrap_around_uint*ULONG_MAX/UINT_MAX;
    std::cout << "unsigned int time (years):  " 
              << wrap_around_uint_l/(   CLOCKS_PER_SEC
                                        *3600
                                        *24
                                        *365)
                << std::endl;
}

