// 1. рядок символів – це послідовність символів, яка закінчується нульовим символом '\0'
// 2. використовуються об’єкти cin, cout, getline для роботи з рядками
// 3. довжину можна не описувати при ініціалізації рядка рядковим літералом
// 4. функції: strlen, strcpy, strcat, strcmp, substr, find, append

#include <iostream>
#include <string>
using namespace std;

int countWordOccurrences(const string& sentence, const string& word) {
    int count = 0;
    size_t pos = sentence.find(word);
    while (pos != string::npos) {
        count++;
        pos = sentence.find(word, pos + word.length());
    }
    return count;
}

int main() {
    string sentence;
    cout << "Введіть речення: ";
    getline(cin, sentence);

    int informaticsCount = countWordOccurrences(sentence, "інформатика");
    int computerCount = countWordOccurrences(sentence, "комп’ютер");

    cout << "Слово \"інформатика\" зустрічається " << informaticsCount << " раз(ів)." << endl;
    cout << "Слово \"комп’ютер\" зустрічається " << computerCount << " раз(ів)." << endl;

    return 0;
}
