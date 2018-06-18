#include "lab1.h"

Matrix :: Matrix (int x, int y) : width(x), length(y)
{
    array = new int * [width];

    for (int i = 0; i < width; i++)
        array[i] = new int [length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = 0;
}

Matrix :: Matrix ( Matrix & matrix) : width (matrix.width), length(matrix.length)
{
    array = new int * [width];

    for (int i = 0; i < width; i++)
        array[i] = new int [length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = matrix.array[i][j];
}

Matrix :: ~Matrix()
{
    for (int i = 0; i < width; i++)
        delete [] array[i];

    delete [] array;
}

int Matrix :: Get_Width()
{
    return width;
}

int Matrix :: Get_Length()
{
    return length;
}

int ** Matrix :: Get_Array()
{
    return array;
}

void Matrix :: transpose()
{
    int ** tmp;

    tmp = new int *[length];
    for (int i = 0; i < length; i++)
        tmp[i] = new int [width];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            tmp[j][i]=array[i][j];

    for (int i = 0; i < width; i++)
        delete [] array[i];
    delete array;

    width += length;
    length = width - length;
    width -= length;

    array = tmp;
}

Matrix & Matrix  :: operator = (Matrix const & matrix1)
{
    width = matrix1.width;
    length = matrix1.length;

    for (int i = 0; i < width; i++)
        delete [] array[i];

    delete [] array;

    array = new int * [width];

    for (int i = 0; i < width; i++)
        array[i] = new int [length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = matrix1.array[i][j];
    return *this;
}

Matrix &  Matrix :: operator *=(const int & num)
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            this->array[i][j] *= num;
    return *this;
}
Matrix & Matrix :: operator +=(const Matrix & matrix1)
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            this->array[i][j] += matrix1.array[i][j];
    return *this;
}
Matrix & Matrix :: operator -=(const Matrix & matrix1)
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            this->array[i][j] -= matrix1.array[i][j];
    return *this;
}

Matrix Matrix :: operator +(const Matrix & matrix1)
{
    Matrix tmp;
    tmp.width = matrix1.width;
    tmp.length = matrix1.length;

    tmp.array = new int * [width];

    for (int i = 0; i < width; i++)
        tmp.array[i] = new int [length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            tmp.array[i][j] = this->array[i][j] + matrix1.array[i][j];
    return tmp;
}

Matrix Matrix :: operator -(const Matrix & matrix1)
{
    Matrix tmp;
    tmp.width = matrix1.width;
    tmp.length = matrix1.length;

    tmp.array = new int * [width];

    for (int i = 0; i < width; i++)
        tmp.array[i] = new int [length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            tmp.array[i][j] = this->array[i][j] - matrix1.array[i][j];
    return tmp;
}

Matrix Matrix :: operator -()
{
    Matrix tmp;
    tmp.width = this->width;
    tmp.length = this->length;

    tmp.array = new int * [width];

    for (int i = 0; i < width; i++)
        tmp.array[i] = new int [length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            tmp.array[i][j] = -this->array[i][j];
    return tmp;
}

Matrix Matrix :: operator *(const Matrix & matrix1)
{
    Matrix tmp;
    tmp.width = width;
    tmp.length = matrix1.length;

    tmp.array = new int * [width];

    for (int i = 0; i < width; i++)
        tmp.array[i] = new int [length];

    for(int i = 0; i < width; i++)
        for(int j = 0; j < matrix1.length; j++)
        {
            tmp.array[i][j] = 0;
            for(int k = 0; k < length; k++)
                tmp.array[i][j] += array[i][k] * matrix1.array[k][j];
        }
    return tmp;
}

Matrix & Matrix :: operator++()
{
    for (int i = 0; i < this->width; i++)
        for (int j = 0; j < this->length; j++)
            this->array[i][j]+=1;
    return *this;
}

Matrix & Matrix :: operator++(int)
{
    Matrix tmp(*this);
    ++(*this);
    return tmp;
}

ifstream & operator >> (ifstream & input, Matrix & matrix)
{
    int w, l;
    input >> w >> l;
    Matrix tmp(w , l);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < l; j++)
            input >> tmp.Get_Array()[i][j];
    matrix = tmp;
    return input;
}

ofstream & operator << (ofstream & output, Matrix & matrix)
{
    for (int i = 0; i < matrix.Get_Width(); i++)
    {
        for (int j = 0; j < matrix.Get_Length(); j++)
            output << matrix.Get_Array()[i][j] << " ";
        output << endl;
    }
    return output;
}
