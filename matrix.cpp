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
