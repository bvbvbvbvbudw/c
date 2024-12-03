// 1. ідея препроцесорної обробки – підготовка коду до компіляції через директиви
// 2. типи макропідстановки: заміна тексту, параметризовані макроси
// 3. макроси швидші, бо не викликають функції, але ускладнюють налагодження
// 4. умовна компіляція дозволяє включати або виключати частини коду залежно від умов
// 5. умовна компіляція дозволяє використовувати різний код для різних платформ
// 6. оператор # перетворює аргумент у рядок, ## об'єднує два токени
// 7. визначення макросу скасовується через директиву #undef

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cout << "Введіть кількість елементів масиву: ";
    cin >> N;

    vector<double> array(N);
    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    double positiveSum = 0;
    for (double num : array) {
        if (num > 0) {
            positiveSum += num;
        }
    }
    cout << "Сума додатних елементів: " << positiveSum << endl;

    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < N; i++) {
        if (fabs(array[i]) > fabs(array[maxIndex])) maxIndex = i;
        if (fabs(array[i]) < fabs(array[minIndex])) minIndex = i;
    }

    double product = 1;
    if (minIndex > maxIndex) swap(minIndex, maxIndex);
    for (int i = minIndex + 1; i < maxIndex; i++) {
        product *= array[i];
    }
    cout << "Добуток елементів між мінімальним і максимальним за модулем: " << product << endl;

    sort(array.begin(), array.end(), greater<double>());
    cout << "Масив після сортування за спаданням:" << endl;
    for (double num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
