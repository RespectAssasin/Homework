#include "Libraries.h"

// Замена слова в тексте
void replaceWord(char* text, const char* oldWord, const char* newWord) {
    char* pos = strstr(text, oldWord);
    while (pos != nullptr) {
        int lenDiff = strlen(newWord) - strlen(oldWord);
        memmove(pos + strlen(newWord), pos + strlen(oldWord), strlen(pos + strlen(oldWord)) + 1);
        memcpy(pos, newWord, strlen(newWord));
        pos = strstr(pos + strlen(newWord), oldWord);
    }
}

// Каждое предложение начинается с большой буквы
void capitalizeAfterDots(char* text) {
    bool capitalizeNext = true;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '.') {
            capitalizeNext = true;
        }
        else if (isalpha(text[i])) {
            if (capitalizeNext) {
                text[i] = toupper(text[i]);
                capitalizeNext = false;
            }
            else {
                text[i] = tolower(text[i]);
            }
        }
    }
}

// Подсчет количества каждых букв и цифр
void countAndPrintCharacters(const char* text) {
    unordered_map<char, int> charCount;//Создание аналога map

    for (int i = 0; text[i] != '\0'; ++i) {
        charCount[text[i]]++;
    }

    // Вывод результатов
    cout << "Символ - Количество" << endl;
    for (const auto& pair : charCount) {
        cout << pair.first << " - " << pair.second << endl;
    }
}

//Общее количество букв и цифр
void countCharacterTypes(const char* input) {
    int letters{0};
    int digits{ 0 };
    int other{ 0 };
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
    cout << "Буквы: " << letters << endl;
    cout << "Цифры: " << digits<< endl;
    cout << "Другое: " << other << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    const int maxLength{1000};
    char text[maxLength];

    cout << "Введите текст:" << endl;
    cin.getline(text, maxLength);

    char oldWord[maxLength], newWord[maxLength];

    cout << "Введите слово, которое нужно заменить: ";
    cin >> oldWord;
    cout << "Введите новое слово: ";
    cin >> newWord;

    replaceWord(text, oldWord, newWord);

    capitalizeAfterDots(text);

    cout << "Изменённый текст: " << text << endl;
    countAndPrintCharacters(text);

    countCharacterTypes(text);

    return 0;
}