// 1. прототип функцій дозволяє оголосити функцію перед її використанням
// 2. функції зі змінною кількістю параметрів реалізуються через ... (stdarg.h)
// 3. працювати з даними треба через параметри або локальні змінні
// 4. функції-покажчики дозволяють передавати функцію як аргумент
// 5. масиви передаються у функції за покажчиком на перший елемент

#include <iostream>
#include <vector>
using namespace std;

vector<int> findCommonElements(const vector<int>& array1, const vector<int>& array2) {
    vector<int> common;
    for (int elem1 : array1) {
        for (int elem2 : array2) {
            if (elem1 == elem2) {
                common.push_back(elem1);
                break;
            }
        }
    }
    return common;
}

int main() {
    const int rows = 3, cols = 5;
    int matrix[rows][cols] = {
        {1, 2, 3, 4, 5},
        {4, 5, 6, 7, 8},
        {1, 3, 4, 8, 9}
    };

    for (int i = 0; i < rows - 1; i++) {
        vector<int> row1(matrix[i], matrix[i] + cols);
        vector<int> row2(matrix[i + 1], matrix[i + 1] + cols);

        vector<int> common = findCommonElements(row1, row2);
        cout << "Однакові елементи між рядками " << i + 1 << " та " << i + 2 << ": ";
        for (int elem : common) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
