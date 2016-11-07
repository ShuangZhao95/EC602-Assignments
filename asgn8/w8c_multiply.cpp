// AUTHOR alejandro aaparici@bu.edu
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


typedef std::vector<std::vector<int> > intmatrix;
typedef  std::vector<std::vector<double> > doublematrix;
enum mult_mode {SQUARE, GENERAL};

#define ERR_ARGS 1
#define ERR_READ 2
#define ERR_SHAPE 3
#define ERR_WRITE 4

intmatrix matrix_multiply(const intmatrix &m1, const intmatrix &m2)
{
    intmatrix m3(m1.size(), std::vector<int>(m2[0].size()));
    for (int i=0;i<m1.size();i++)
        for (int j=0;j<m2[0].size();j++)
            for (int k=0;k<m1[0].size();k++)
                m3[i][j] += m1[i][k] * m2[k][j];
    return m3;
}

doublematrix matrix_multiply(const doublematrix &m1, const doublematrix &m2)
{
    doublematrix m3(m1.size(), std::vector<double>(m2[0].size()));
    for (int i=0;i<m1.size();i++)
        for (int j=0;j<m2[0].size();j++)
            for (int k=0;k<m1[0].size();k++)
                m3[i][j] += m1[i][k] * m2[k][j];
    return m3;
}


intmatrix iread_matrix_from_file(std::string& fn, int& m, int& n)
{
    std::ifstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn.c_str());
    if(!file) throw ERR_READ;
    intmatrix ma(m, std::vector<int>(n));
    int count = 0;
    int i =0;
    while(file >> i)
    {
        if(count < m*n)ma[count/n][count%n] = i;
        else throw ERR_SHAPE;
        count++;
    }
    file.close();
    if(count != m*n) throw ERR_SHAPE;
    return ma;
}
doublematrix dread_matrix_from_file(std::string& fn, int& m, int& n)
{
    std::ifstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn.c_str());
    if(!file) throw ERR_READ;
    doublematrix ma(m, std::vector<double>(n));
    int count = 0;
    double i =0;
    while(file >> i)
    {
        if(count < m*n)ma[count/n][count%n] = i;
        else throw ERR_SHAPE;
        count++;
    }
    file.close();
    if(count != m*n) throw ERR_SHAPE;
    return ma;
}

template<typename T> int write_matrix_to_file(const char* fn, T m)
{
    std::ofstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn);
    if(!file) throw ERR_WRITE;
    for (int i=0;i<m.size();i++)
    {
        for (int j=0;j<m[0].size();j++)
            file << m[i][j] << " ";
        file << std::endl;    
    }
    file.close();
}

int main(int argc, char const *argv[])
{
    enum mult_mode mode;
    bool dtype;
    std::string file1, file2, file3;
    int L, M, N;
    if(argc == 6)
    {
        if(std::string(argv[1]) == "double") dtype = true;
        else if(std::string(argv[1]) == "int") dtype = false;
        else return ERR_ARGS;

        N =         atoi(argv[2]);
        M =         N;
        L =         N;
        file1 =     argv[3];
        file2 =     argv[4];
        file3 =     argv[5];
    }
    else if(argc == 8)
    {
        if(std::string(argv[1]) == "double") dtype = true;
        else if(std::string(argv[1]) == "int") dtype = false;
        else return ERR_ARGS;
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
    if( L < 1 || M < 1 || N < 1 ) return ERR_ARGS;
    if(dtype)
    {
        doublematrix m1, m2;
        try {
            m1 = dread_matrix_from_file(file1, M, N); 
            m2 = dread_matrix_from_file(file2, N, L); 
        } 
        catch (int e)
        {
            if(e == ERR_READ) return ERR_READ;
            return ERR_SHAPE;
        }
        doublematrix m3 = matrix_multiply(m1, m2);
        try
        {
            write_matrix_to_file(file3.c_str(), m3);
        }
        catch (int e)
        {
            return ERR_WRITE;
        }
    }
    else
    {
        intmatrix m1, m2;
        try {
            m1 = iread_matrix_from_file(file1, M, N); 
            m2 = iread_matrix_from_file(file2, N, L); 
        } 
        catch (int e)
        {
            if(e == ERR_READ) return ERR_READ;
            return ERR_SHAPE;
        }
        intmatrix m3 = matrix_multiply(m1, m2);
        try
        {
            write_matrix_to_file(file3.c_str(), m3);
        }
        catch (int e)
        {
            return ERR_WRITE;
        }
    }
    return 0;
}


