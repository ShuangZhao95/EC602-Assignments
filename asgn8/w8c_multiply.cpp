/*
 * =====================================================================================
 *
 *       Filename:  w8c_multiply.cpp
 *
 *    Description:  Reads in two matrices from two text files, and outputs the 
 *    result in a third text file.
 *
 *        Version:  1.0
 *        Created:  10/31/2016 07:38:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Oleinik (ax), alxndr@bu.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


typedef std::vector<std::vector<int> > intmatrix;
typedef  std::vector<std::vector<double> > doublematrix;
enum mult_mode {SQUARE, GENERAL};
enum error_code {ERR_ARGS, ERR_READ, ERR_SHAPE, ERR_WRITE};

template<typename T> T matrix_multiply(const T &m1, const T &m2)
{
    T m3(m1.size() m2[0].size();
    for (int i=0;i<m1.size();i++)
        for (int j=0;j<m1[0].size();j++)
            for (int k=0;k<m2[0].size();k++)
                m3[i][j] += m1[i][k] * m2[k][j];

    return m3;
}

template<typename T> T read_matrix_from_file(std::string& fn, int& w)
{
    std::ifstream thisfile; // note: this is an IFSTREAM, "I" stands for INPUT
    T m;
    int count = 0;
    while(thisfile >> m[count/w][count%w])
        count ++;
    thisfile.close();

    return m;
}

doublematrix read_matrix_from_file(std::string& fn, int& w)
{
    std::ifstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn);
    doublematrix m(w, std::vector<double>(w));
    int count = 0;
    while(file >> m[count/w][count%w])
        count ++;
    file.close();

    return m;
}

template<typename T> void write_matrix_to_file(const char* fn, T m)
{
    std::ofstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn);
    for (typename T::iterator it1 = m.begin() ; it1 < m.end(); it1++)
    {
        for ( typename T::iterator::iterator it2 = it1.begin() ; it2 < it1.end(); it2++)
            file << it2;
        file << std::endl;
    }

    return m;
}

int main(int argc, char const *argv[])
{
    enum mult_mode mode;
    bool dtype;
    std::string file1, file2, file3;
    int L, M, N;
    dtype = std::string(argv[1]) == "double" ? true : false;
    if(argc == 6)
    {
        mode =      SQUARE;
        N =         atoi(argv[2]);
        M =         N;
        file1 =     argv[3];
        file2 =     argv[4];
        file3 =     argv[5];
    }
    else if(argc == 8)
    {
        mode =      GENERAL;
        M =         atoi(argv[2]);
        N =         atoi(argv[3]);
        L =         atoi(argv[4]);
        file1 =     argv[5];
        file2 =     argv[6];
        file3 =     argv[7];
    }
    else 
    {
        return ERR_ARGS;
    }
    if(dtype)
    {
        doublematrix m1 = read_matrix_from_file(file1, M); 
        doublematrix m2 = read_matrix_from_file(file2, N); 
        doublematrix m3 = matrix_multiply(m1, m2);
    }

}


