// AUTHOR alexander oleinik alxndr@bu.edu
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


typedef std::vector<std::vector<int> > intmatrix;
typedef  std::vector<std::vector<double> > doublematrix;
enum mult_mode {SQUARE, GENERAL};
enum error_code {ERR_ARGS, ERR_READ, ERR_SHAPE, ERR_WRITE};

int matrix_multiply(const intmatrix &m1, const intmatrix &m2, intmatrix* m3)
{
    m3->resize(m1.size(), std::vector<int>(m2[0].size()));
    for (int i=0;i<m1.size();i++)
        for (int j=0;j<m2[0].size();j++)
            for (int k=0;k<m1[0].size();k++)
                m3[i][j] += m1[i][k] * m2[k][j];
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


int iread_matrix_from_file(std::string& fn, int& m, int& n, intmatrix* ma)
{
    std::ifstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn.c_str());
    if(!file) return -1;
    ma->resize(m, std::vector<int>(n));
    int count = 0;
    while(file >> ma[count/n][count%n])
        count ++;
    file.close();

}
doublematrix dread_matrix_from_file(std::string& fn, int& m, int& n)
{
    std::ifstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn.c_str());
    doublematrix ma(m, std::vector<double>(n));
    int count = 0;
    while(file >> ma[count/n][count%n])
        count ++;
    file.close();

    return ma;
}

template<typename T> int write_matrix_to_file(const char* fn, T m)
{
    std::ofstream file; // note: this is an IFSTREAM, "I" stands for INPUT
    file.open(fn);
    if(!file) return -1;
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
    dtype = std::string(argv[1]) == "double" ? true : false;
    if(argc == 6)
    {
        N =         atoi(argv[2]);
        M =         N;
        L =         N;
        file1 =     argv[3];
        file2 =     argv[4];
        file3 =     argv[5];
    }
    else if(argc == 8)
    {
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
        doublematrix m1 = dread_matrix_from_file(file1, M, N); 
        doublematrix m2 = dread_matrix_from_file(file2, N, L); 
        doublematrix m3 = matrix_multiply(m1, m2);
        write_matrix_to_file(file3.c_str(), m3);
    }
    else
    {
        intmatrix m1, m2 , m3;
        if(!iread_matrix_from_file(file1, M, N, &m1)) return 2;
        if(!iread_matrix_from_file(file2, N, L, &m2)) return 2;
        matrix_multiply(m1, m2, &m3);
        write_matrix_to_file(file3.c_str(), m3);
    }
    return 0;
}


