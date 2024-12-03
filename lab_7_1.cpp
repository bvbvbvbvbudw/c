#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct STUDENT {
    string surname;
    int groupNumber;
    int grades[5];
};

double calculateAverage(const STUDENT& student) {
    double sum = 0;
    for (int grade : student.grades) {
        sum += grade;
    }
    return sum / 5.0;
}

bool hasOnlyHighGrades(const STUDENT& student) {
    for (int grade : student.grades) {
        if (grade < 4) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;

    vector<STUDENT> students(n);

    for (int i = 0; i < n; i++) {
        cout << "Введіть прізвище студента: ";
        cin >> students[i].surname;
        cout << "Введіть номер групи: ";
        cin >> students[i].groupNumber;
        cout << "Введіть 5 оцінок: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].grades[j];
        }
    }

    sort(students.begin(), students.end(), [](const STUDENT& a, const STUDENT& b) {
        return calculateAverage(a) < calculateAverage(b);
    });

    bool found = false;
    cout << "Студенти з оцінками 4 і 5:\n";
    for (const auto& student : students) {
        if (hasOnlyHighGrades(student)) {
            cout << "Прізвище: " << student.surname << ", Група: " << student.groupNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Студентів з оцінками 4 і 5 немає.\n";
    }

    char letter;
    cout << "Введіть першу літеру для пошуку: ";
    cin >> letter;
    cout << "Студенти, прізвище яких починається на '" << letter << "':\n";
    found = false;
    for (const auto& student : students) {
        if (tolower(student.surname[0]) == tolower(letter)) {
            cout << "Прізвище: " << student.surname << ", Група: " << student.groupNumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Немає студентів з прізвищем на цю літеру.\n";
    }

    return 0;
}
