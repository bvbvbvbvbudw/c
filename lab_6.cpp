// 1. бібліотечні функції введення-виведення поділяються на функції роботи з файлами, текстовими та бінарними потоками
// 2. потік – це абстракція для роботи з даними, що надходять або зберігаються
// 3. так, можна працювати зі стандартними потоками cin, cout, cerr
// 4. потік відкривається в бінарному режимі через ios::binary або режим b у fopen
// 5. функція fopen повертає покажчик на файл або NULL, якщо файл не відкрито
// 6. функція putchar виводить символ у стандартний потік
// 7. функції fgets та fputs працюють із рядками
// 8. покажчик встановлюється на кінець файлу функцією fseek(file, 0, SEEK_END)
// 9. кінець файлу перевіряється через feof(file)
// 10. наявність помилки перевіряється функцією ferror(file)
// 11. індикатор помилки можна скинути через clearerr(file)
// 12. функція fprintf виконує форматоване виведення в потік
// 13. printf виводить у стандартний потік, а fprintf – у заданий потік
// 14. поле введення для fscanf визначає кількість символів для зчитування
// 15. рядок формату fscanf містить специфікатори типу даних, наприклад, %d, %s, %f

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isNonZeroColumn(const vector<vector<int>>& matrix, int colIndex) {
    for (const auto& row : matrix) {
        if (row[colIndex] == 0) {
            return false;
        }
    }
    return true;
}

int calculateRowCharacteristic(const vector<int>& row) {
    int sum = 0;
    for (int elem : row) {
        if (elem > 0 && elem % 2 == 0) {
            sum += elem;
        }
    }
    return sum;
}

int main() {
    int rows, cols;
    cout << "Введіть кількість рядків і стовпців: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int nonZeroColumns = 0;
    for (int j = 0; j < cols; j++) {
        if (isNonZeroColumn(matrix, j)) {
            nonZeroColumns++;
        }
    }
    cout << "Кількість стовпців без нульових елементів: " << nonZeroColumns << endl;

    vector<pair<int, vector<int>>> rowsWithCharacteristics;
    for (const auto& row : matrix) {
        rowsWithCharacteristics.push_back({calculateRowCharacteristic(row), row});
    }
    sort(rowsWithCharacteristics.begin(), rowsWithCharacteristics.end());

    cout << "Матриця після сортування рядків за характеристиками:" << endl;
    for (const auto& pair : rowsWithCharacteristics) {
        for (int elem : pair.second) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
