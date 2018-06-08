#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H

#include <iostream>
#include <fstream>
using namespace std;

class Matrix
{
public:
    Matrix (int x = 3, int y = 3);
    Matrix (Matrix &);
    ~Matrix();
    int Get_Width() ;
    int Get_Length();
    int ** Get_Array();
    void transpose();

    Matrix & operator = (const Matrix & );
    Matrix & operator *=(const int & );
    Matrix & operator +=(const Matrix &);
    Matrix & operator -=(const Matrix & );
    Matrix operator +(const Matrix & );
    Matrix operator -(const Matrix & );
    Matrix operator -();
    Matrix operator *(const Matrix & );
    Matrix & operator++();
    Matrix & operator++(int);


private:
    int width, length;
    int ** array;
};

ifstream & operator >> (ifstream &, Matrix &);
ofstream & operator << (ofstream &, Matrix &);
#endif //LAB2_HEADER_H
