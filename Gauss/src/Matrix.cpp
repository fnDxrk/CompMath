#include "Matrix.h"

Matrix::Matrix()
    : size(0)
{
}

Matrix::Matrix(const std::string& filename)
    : size(0)
{
    readFromFile(filename);
}

// Чтение из файла
void Matrix::readFromFile(const std::string& filename)
{
    // Файл
    ifstream file(filename);


    // Проверка на открытие файла
    if (!file.is_open()) {
        cout << "Error : file is not open";
        exit(1);
    }

    // Строка для чтения
    string line;

    // Занесение матрицы и вычисление её размера
    while (getline(file, line)) {
        vector<double> row;
        istringstream iss(line);
        double val;
        while (iss >> val) {
            row.push_back(val);
        }
        matrix.push_back(row);
        size++;
    }
}

// Вывод матрицы
void Matrix::printMatrix()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size + 1; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

// Метод Гаусса
void Matrix::methodGauss(bool value)
{
    // Перестановка строк (Модифицированный вид)
    if (value == true) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i; j < size - 1; j++) {
                if (abs(matrix[i][i]) < abs(matrix[j][i])) {
                    swap(matrix[i], matrix[j]);
                }
            }
        }
    }

    // Прямой ход
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double attitude = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < size + 1; k++) {
                matrix[j][k] = matrix[j][k] - attitude * matrix[i][k];
            }
        }
    }

    solutionX();
}

// Нахождение X'ов
void Matrix::solutionX()
{   
    // Размер вектора для X
    x.resize(size);
    
    // Последний X
    x[size - 1] = matrix[size - 1][size] / matrix[size - 1][size - 1];

    // Оставшиеся x
    for (int i = size - 2; i >= 0; i--) {
        x[i] = matrix[i][size];
        for (int j = i + 1; j < size; j++) {
            x[i] -= matrix[i][j] * x[j];
        }
        x[i] = x[i] / matrix[i][i];
    }
}

// Вывод X'ов
void Matrix::printX()
{
    for (int i = 0; i < size; i++) {
        cout << "x[" << i + 1 << "] = " << setprecision(2) << fixed << x[i] << endl;
    }
}
