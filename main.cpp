#include "lab1.h"

int main()
{
    Matrix matrix1(3, 3), matrix2(3, 3), matrix3;

    ifstream input("input.txt");
    input >> matrix1;
    input >> matrix2;
    input.close();

    ofstream output("output.txt");

    output << "Matrix1" << endl;
    output << matrix1;

    output << "Matrix2" << endl;
    output << matrix2;

    matrix1.transpose();
    matrix2.transpose();

    output << "Transpose Matrix1" << endl;
    output << matrix1;
    output << "Transpose Matrix2" << endl;
    output << matrix2;

    matrix1 *= 2;
    output << "Matrix1 *= 2" << endl;
    output << matrix1;

    matrix1 += matrix2;
    output << "Matrix1 += Matrix2" << endl;
    output << matrix1;

    matrix3 = matrix1 + matrix2;
    output << "Matrix3 = Matrix1 + Matrix2" << endl;
    output << matrix3;

    output.close();
    return 0;
}
