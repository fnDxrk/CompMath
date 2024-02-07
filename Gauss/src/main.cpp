#include "Matrix.h"

using namespace std;

int main()
{
    string filename = "Gauss/input.txt";
    Matrix matrix(filename);

    matrix.printMatrix();

    matrix.methodGauss(true);

    matrix.printMatrix();

    matrix.printX();

    return 0;
}