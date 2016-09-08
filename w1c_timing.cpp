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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  tt_wrap_around
 *  Description:  Time to wrap around
 * =====================================================================================
 */
double uint_tt_wrap_around_int_s(int m)
{
    int n = m;
    clock_t start_clock, end_clock;
    start_clock = clock();
    while( ++m != n )
        ;
    end_clock = clock();
    double seconds = (double)(end_clock - start_clock) / CLOCKS_PER_SEC;
    return seconds;
}

double tt_wrap_around_uint_s_ms(unsigned short int m)
{
    int n = m;
    clock_t start_clock, end_clock;
    start_clock = clock();
    while( ++m != n )
        ;
    end_clock = clock();
    double seconds = (double)(end_clock - start_clock);
    return seconds;
}

double tt_wrap_around_uint_l_y(unsigned long int m)
{
    int n = m;
    clock_t start_clock, end_clock;
    start_clock = clock();
    while( ++m != n )
        ;
    end_clock = clock();
    double seconds = (double)(end_clock - start_clock) / (CLOCKS_PER_SEC*
                                                            60*
                                                            60*
                                                            24*
                                                            );
    return seconds;
}

main()
{
    short unsigned int m = 1;
    std::cout << tt_wrap_around(m) << std::endl;
}

