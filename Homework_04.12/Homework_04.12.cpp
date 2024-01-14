#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int количество_строк_в_файле(const string& filepath) {
    ifstream file(filepath);

    int count = 0;
    string line;
    while (getline(file, line)) {
        count++;
    }

    return count;
}

void копировать_файл(const string& source, const string& destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);

    dest << src.rdbuf();
    cout << "Выполнено!";
}

void сортировка_файла(const string& filepath) {
    ifstream inputFile(filepath);

    vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = 0; j < numbers.size() - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }

    ofstream outputFile(filepath);

    for (const auto& num : numbers) {
        outputFile << num << " ";
    }
    outputFile.close();
}

void анализ_файла(const string& filepath) {
    ifstream file(filepath);

    string line;
    while (getline(file, line)) {
        int line_count = 1;
        istringstream iss(line);
        string word;
        int wordCount = 0;
        while (iss >> word) {
            ++wordCount;
        }
        cout << "Строка " << line_count << " содержит " << wordCount << " слов." << endl;
        line_count++;
    }
}

void combineFiles(const vector<string>& filepaths, const string& outputfilepath) {
    ofstream outputFile(outputfilepath);

    for (const auto& filepath : filepaths) {
        ifstream inputFile(filepath);

        string line;
        while (getline(inputFile, line)) {
            outputFile << line << endl;
        }
    }
}

void поиск_в_файле(const string& filepath, const string& searchString) {
    ifstream file(filepath);

    string line;
    int lineNumber = 0, counter = 0;
    while (getline(file, line)) {
        ++lineNumber;
        if (line.find(searchString) != string::npos) {
            counter++;
            cout << "Линия " << lineNumber << " содержит \"" << searchString << "\"" << endl;
        }
    }

    if (lineNumber > 0 && counter == 0) {
        cout << "\"" << searchString << "\" не найден" << endl;
    }
}

void переместить_текст_в_файл(const string& filepath, const string& from, const string& to) {////////////////////////////////////////
    ifstream inputFile(filepath, ios::app);

    //string tempfilepath = filepath;
    ofstream outputFile(filepath);

    string line;
    while (getline(inputFile, line)) {
        string::size_type pos = 0;
        while ((pos = line.find(from, pos)) != string::npos) {
            line.replace(pos, from.length(), to);
            pos += to.length();
        }
        outputFile << line << endl;
    }


    inputFile.close();
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "");

    //1
    /*string filepath;
    cout << "Имя файла: ";
    cin >> filepath;
    int count = количество_строк_в_файле(filepath);
    cout << "Количество строк в вашем файле: " << count << endl;
    cout << "Выполнено!!!" << endl;*/

    //2
    /*string source, destination;
    cout << "Откуда закидываем: ";
    cin >> source;
    cout << "Куда закидываем: ";
    cin >> destination;
    копировать_файл(source, destination);
    cout << "Выполнено!!!" << endl;*/

    //3
    /*string filepath;
    cout << "Имя файла: ";
    cin >> filepath;
    сортировка_файла(filepath);
    cout << "Выполнено!!!" << endl;*/

    //4
    /*string filepath;
    cout << "Имя файла: ";
    cin >> filepath;
    анализ_файла(filepath);
    cout << "Выполнено!!!" << endl;*/

    //5
    /*vector<string> filepaths = { "Test.txt", "Test2.txt"};
    combineFiles(filepaths, "Test3.txt");
    cout << "Выполнено!!!" << endl;*/
    //6
    /*string filepath, str;
    cout << "Имя файла: ";
    cin >> filepath;
    cout << "Что ищем: ";
    cin >> str;
    поиск_в_файле(filepath, str);
    cout << "Выполнено!!!" << endl;*/

    //7
    /*string filepath, from, to;
    cout << "Имя файла: ";
    cin >> filepath;
    cout << "Что меняем: ";
    cin >> from;
    cout << "На что меняем :";
    cin >> to;
    переместить_текст_в_файл(filepath, from, to);
    cout << "Выполнено!!!" << endl;
    return 0;*/
}