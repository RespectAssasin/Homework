#include "Libraries.h"

// Задание 1
void removeCharacterByIndex(char* input, int index) {
    if (index < strlen(input)) {
        memmove(&input[index], &input[index + 1], strlen(input) - index);
    }
    else {
        cerr << "Index out of range!" << endl;
    }
}

// Задание 2
void removeAllOccurrences(char* input, char target) {
    char* readPtr = input;
    char* writePtr = input;

    while (*readPtr) {
        if (*readPtr != target) {
            *writePtr = *readPtr;
            writePtr++;
        }
        readPtr++;
    }

    *writePtr = '\0';
}

// Задание 3
void insertCharacter(char* input, int position, char character) {
    int len = strlen(input);

    if (position <= len) {
        memmove(&input[position + 1], &input[position], len - position + 1);
        input[position] = character;
    }
    else {
        cerr << "Position out of range!" << endl;
    }
}

// Задание 4
void replaceDotsWithExclamation(char* input) {
    while (*input) {
        if (*input == '.') {
            *input = '!';
        }
        input++;
    }
}

// Задание 5
int countCharacterOccurrences(const char* input, char target) {
    int count = 0;
    while (*input) {
        if (*input == target) {
            count++;
        }
        input++;
    }
    return count;
}

// Задание 6
void countCharacterTypes(const char* input, int& letters, int& digits, int& other) {
    letters = digits = other = 0;
    for (int i = 0; i < strlen(input); ++i) {
        if (std::isalpha(input[i])) {
            letters++;
        }
        else if (std::isdigit(input[i])) {
            digits++;
        }
        else {
            other++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    char testString[256];

    // Задание 1
    /*cout << "Задание 1 - Удалить символ по индексу:" << endl;

    cout << "Введите строку: ";
    cin.getline(testString, sizeof(testString));

    int indexToRemove;
    cout << "Введите индекс символа для удаления: ";
    cin >> indexToRemove;
    removeCharacterByIndex(testString, indexToRemove);
    cout << "Результат: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // Задание 2
    /*cout << endl << "Задание 2 - Удалить все вхождения символа:" << endl;

    cout << "Введите строку: ";
    cin.getline(testString, sizeof(testString));

    char charToRemove;
    cout << "Введите символ для удаления: ";
    cin >> charToRemove;
    removeAllOccurrences(testString, charToRemove);
    cout << "Результат: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // Задание 3
    /*cout << endl << "Задание 3 - Вставить символ на позицию:" << endl;
    
    cout << "Введите строку: ";
    cin.getline(testString, sizeof(testString));

    int positionToInsert;
    char charToInsert;
    cout << "Введите позицию для вставки: ";
    cin >> positionToInsert;
    cout << "Введите символ для вставки: ";
    cin >> charToInsert;
    insertCharacter(testString, positionToInsert, charToInsert);
    cout << "Результат: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // Задание 4
    /*cout << endl << "Задание 4 - Заменить точки на восклицательные знаки:" << endl;
    
    cout << "Введите строку: ";
    cin.getline(testString, sizeof(testString));

    replaceDotsWithExclamation(testString);
    cout << "Результат: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // Задание 5
    /*cout << endl << "Задание 5 - Подсчитать вхождения символа:" << endl;
    
    cout << "Введите строку: ";
    cin.getline(testString, sizeof(testString));

    char charToCount;
    cout << "Введите символ для подсчета: ";
    cin >> charToCount;
    cout << "Символ '" << charToCount << "' встречается " << countCharacterOccurrences(testString, charToCount) << " раз" << endl;
    memset(testString, 0, sizeof(testString));*/

    // Задание 6
    /*cout << endl << "Задание 6 - Подсчитать типы символов:" << endl;
    
    cout << "Введите строку: ";
    cin.getline(testString, sizeof(testString));

    int letters, digits, other;
    countCharacterTypes(testString, letters, digits, other);
    cout << "Буквы: " << letters << endl << "Цифры: " << digits << endl << "Прочие: " << other << endl;
    memset(testString, 0, sizeof(testString));*/

    return 0;
}
