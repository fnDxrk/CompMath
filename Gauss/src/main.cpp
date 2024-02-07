#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Вывод матрицы
void printMatrix(vector<vector<double>> matrix, int size)
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
void methodGauss(vector<vector<double>>& matrix, int size, bool value)
{
    // Перестановка строк
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
}

int main()
{
    // Файл
    ifstream file("../input.txt");

    // Проверка на открытие файла
    if (!file.is_open()) {
        cout << "Error : file is not open";
        return 1;
    }

    // Строка для чтения
    string line;

    // Размер матрицы
    int size = 0;

    // Кол-во строк
    while (getline(file, line)) {
        ++size;
    }

    // Перевод курсора в начало
    file.clear();
    file.seekg(0);

    // Вектор матрицы
    vector<vector<double>> matrix(size, vector<double>(size + 1));
    // Вектор X'ов
    vector<double> x(size);

    // Заполнение матрицы из файла
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size + 1; j++) {
            file >> matrix[i][j];
        }
    }

    printMatrix(matrix, size);

    methodGauss(matrix, size, true);

    printMatrix(matrix, size);

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

    for (int i = 0; i < size; i++) {
        cout << "x[" << i + 1 << "] = " << setprecision(2) << fixed << x[i] << endl;
    }
}