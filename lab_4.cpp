// 1. структура – це користувацький тип даних, який об’єднує поля різних типів
// 2. структура може містити будь-які типи полів, включаючи інші структури
// 3. звернення до елементів – через оператор . або -> для покажчиків
// 4. опис через ключове слово struct із зазначенням імені структури
// 5. так, можна присвоїти одну структуру іншій, якщо їхній тип однаковий

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    string lastName;
    string firstName;
    string middleName;
    int number;
    int birthMonth;
};

void findEmployeesByMonth(const vector<Employee>& employees, int month) {
    cout << "Співробітники, які народилися в місяці " << month << ":" << endl;
    for (const auto& employee : employees) {
        if (employee.birthMonth == month) {
            cout << employee.lastName << " " << employee.firstName << " " << employee.middleName
                 << ", номер: " << employee.number << endl;
        }
    }
}

int main() {
    vector<Employee> employees = {
        {"Іваненко", "Іван", "Іванович", 101, 3},
        {"Петренко", "Петро", "Петрович", 102, 5},
        {"Сидоренко", "Сидір", "Сидорович", 103, 3},
        {"Коваленко", "Костянтин", "Костянтинович", 104, 8}
    };

    int month;
    cout << "Введіть номер місяця: ";
    cin >> month;

    findEmployeesByMonth(employees, month);

    return 0;
}
