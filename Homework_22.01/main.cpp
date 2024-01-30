#include "Libraries.h"

// ������� 1
void removeCharacterByIndex(char* input, int index) {
    if (index < strlen(input)) {
        memmove(&input[index], &input[index + 1], strlen(input) - index);
    }
    else {
        cerr << "Index out of range!" << endl;
    }
}

// ������� 2
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

// ������� 3
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

// ������� 4
void replaceDotsWithExclamation(char* input) {
    while (*input) {
        if (*input == '.') {
            *input = '!';
        }
        input++;
    }
}

// ������� 5
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

// ������� 6
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

    // ������� 1
    /*cout << "������� 1 - ������� ������ �� �������:" << endl;

    cout << "������� ������: ";
    cin.getline(testString, sizeof(testString));

    int indexToRemove;
    cout << "������� ������ ������� ��� ��������: ";
    cin >> indexToRemove;
    removeCharacterByIndex(testString, indexToRemove);
    cout << "���������: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // ������� 2
    /*cout << endl << "������� 2 - ������� ��� ��������� �������:" << endl;

    cout << "������� ������: ";
    cin.getline(testString, sizeof(testString));

    char charToRemove;
    cout << "������� ������ ��� ��������: ";
    cin >> charToRemove;
    removeAllOccurrences(testString, charToRemove);
    cout << "���������: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // ������� 3
    /*cout << endl << "������� 3 - �������� ������ �� �������:" << endl;
    
    cout << "������� ������: ";
    cin.getline(testString, sizeof(testString));

    int positionToInsert;
    char charToInsert;
    cout << "������� ������� ��� �������: ";
    cin >> positionToInsert;
    cout << "������� ������ ��� �������: ";
    cin >> charToInsert;
    insertCharacter(testString, positionToInsert, charToInsert);
    cout << "���������: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // ������� 4
    /*cout << endl << "������� 4 - �������� ����� �� ��������������� �����:" << endl;
    
    cout << "������� ������: ";
    cin.getline(testString, sizeof(testString));

    replaceDotsWithExclamation(testString);
    cout << "���������: " << testString << endl;
    memset(testString, 0, sizeof(testString));*/

    // ������� 5
    /*cout << endl << "������� 5 - ���������� ��������� �������:" << endl;
    
    cout << "������� ������: ";
    cin.getline(testString, sizeof(testString));

    char charToCount;
    cout << "������� ������ ��� ��������: ";
    cin >> charToCount;
    cout << "������ '" << charToCount << "' ����������� " << countCharacterOccurrences(testString, charToCount) << " ���" << endl;
    memset(testString, 0, sizeof(testString));*/

    // ������� 6
    /*cout << endl << "������� 6 - ���������� ���� ��������:" << endl;
    
    cout << "������� ������: ";
    cin.getline(testString, sizeof(testString));

    int letters, digits, other;
    countCharacterTypes(testString, letters, digits, other);
    cout << "�����: " << letters << endl << "�����: " << digits << endl << "������: " << other << endl;
    memset(testString, 0, sizeof(testString));*/

    return 0;
}
