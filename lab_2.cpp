// 1. доступ до елемента масиву через арифметику покажчиків
// 2. розадресування – це доступ до значення, на яке вказує покажчик
// 3. дії: присвоєння, арифметика, розадресування, порівняння
// 4. дивись код
// 5. використовувати динамічну пам’ять через new або malloc

#include <iostream>
#include <algorithm>
using namespace std;

void sortRow(int* row, int size) {
    sort(row, row + size);
}

void sortColumn(int** matrix, int rows, int columnIndex) {
    int* column = new int[rows];
    for (int i = 0; i < rows; i++) {
        column[i] = matrix[i][columnIndex];
    }
    sort(column, column + rows);
    for (int i = 0; i < rows; i++) {
        matrix[i][columnIndex] = column[i];
    }
    delete[] column;
}

int main() {
    int rows = 3, cols = 3;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    sortRow(matrix[0], cols); // сортуємо перший рядок
    sortColumn(matrix, rows, 1); // сортуємо другий стовпець

    cout << "Матриця після сортування:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}