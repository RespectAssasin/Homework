#include "Libraries.h"

// ������ ����� � ������
void replaceWord(char* text, const char* oldWord, const char* newWord) {
    char* pos = strstr(text, oldWord);
    while (pos != nullptr) {
        int lenDiff = strlen(newWord) - strlen(oldWord);
        memmove(pos + strlen(newWord), pos + strlen(oldWord), strlen(pos + strlen(oldWord)) + 1);
        memcpy(pos, newWord, strlen(newWord));
        pos = strstr(pos + strlen(newWord), oldWord);
    }
}

// ������ ����������� ���������� � ������� �����
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

// ������� ���������� ������ ���� � ����
void countAndPrintCharacters(const char* text) {
    unordered_map<char, int> charCount;//�������� ������� map

    for (int i = 0; text[i] != '\0'; ++i) {
        charCount[text[i]]++;
    }

    // ����� �����������
    cout << "������ - ����������" << endl;
    for (const auto& pair : charCount) {
        cout << pair.first << " - " << pair.second << endl;
    }
}

//����� ���������� ���� � ����
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
    cout << "�����: " << letters << endl;
    cout << "�����: " << digits<< endl;
    cout << "������: " << other << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    const int maxLength{1000};
    char text[maxLength];

    cout << "������� �����:" << endl;
    cin.getline(text, maxLength);

    char oldWord[maxLength], newWord[maxLength];

    cout << "������� �����, ������� ����� ��������: ";
    cin >> oldWord;
    cout << "������� ����� �����: ";
    cin >> newWord;

    replaceWord(text, oldWord, newWord);

    capitalizeAfterDots(text);

    cout << "��������� �����: " << text << endl;
    countAndPrintCharacters(text);

    countCharacterTypes(text);

    return 0;
}