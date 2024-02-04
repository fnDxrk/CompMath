#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    Matrix(int rows, int cols);
};

int main()
{
    ifstream file("../input.txt");

    // Проверка на открытие файла
    if (!file.is_open()) {
        cout << "Error : file is not open";
        return 1;
    }

    string line;
    int count = 0, rows = 0, cols = 0;

    // Кол-во строк и кол-во цифр
    while (getline(file, line)) {
        ++rows;
        for (char c : line) {
            if (!isspace(c))
                count++;
        }
    }

    // Кол-во столбцов
    cols = count % rows != 0 ? count / rows + 1 : count / rows;

    // Перевод курсора в начало
    file.clear();
    file.seekg(0);

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n" << endl;
    }
}