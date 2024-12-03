// 1) програма C++ складається з підключення бібліотек, функції main і коду всередині неї
// 2) типи даних: int, float, double, char, bool, масиви, рядки, структури
// 3) змінні можна змінювати, константи – ні
// 4) інформацію вводять за допомогою cin
// 5) інформацію виводять за допомогою cout
// 6) Умовні оператори: if, if-else, switch – різняться кількістю умов і порівняннями
// 7) цикли: for, while, do-while

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 1.45, y = -1.22, z = 3.5;
    const double pi = 3.14159;

    // перше завдання
    double b = 2;
    double a = (sin(y) / cos(x)) + pow(b, 2) / pow(pi, 2) - 6;
    double z1 = sqrt(pow(x, 2) + pow(y, 2));
    double z2 = b + z1 + 3;

    cout << "a = " << a << endl;
    cout << "z1 = " << z1 << ", z2 = " << z2 << endl;

    // друге завдання
    double h = 0.1;
    for (double xi = 1; xi <= 2; xi += h) {
        for (double yi = 1; yi <= 2; yi += 0.2) {
            double ax_b = a * xi + b;
            if (ax_b > 1) {
                z = log(a + xi + yi);
            } else {
                z = a + b + 2;
            }
            cout << "x = " << xi << ", y = " << yi << ", z = " << z << endl;
        }
    }
    return 0;
}
