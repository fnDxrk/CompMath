#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Matrix {
private:
    vector<vector<double>> matrix;
    vector<double> x;
    int size;
    

public:
    Matrix();

    Matrix(const string& filename);

    void readFromFile(const std::string& filename);

    void printMatrix();

    void methodGauss(bool value);

    void solutionX();

    void printX();
};