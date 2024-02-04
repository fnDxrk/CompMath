#pragma once

using namespace std;

#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    Matrix(int rows, int cols);
    
    void fillMatrix();

    void printMatrix();
};