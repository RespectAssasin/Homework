#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Ex.1
string Compress(string l) {
    string result{ "" };
    bool word {false};

    int count{ 0 };
    for (char c : l) {
        if (c != ' ') {
            break;
        }
        count++;
    }

    for (char c : l) {
        if (c == ' ') {
            if (word) {
                result += c;
                word = false;
            }
        }
        else {
            result += c;
            word = true;
        }
    }

    if (count != 0) {
        result.insert(0, count, ' ');
    }

    return result;
}
//Ex.2
string ComRemove(string l) {
    string result{ "" };
    bool BlockDelCom = false;

    for (int i = 0; i < l.size(); i++) {
        if (BlockDelCom) {
            if (l[i] == '*' && l[i + 1] == '/') {
                BlockDelCom = false;
                i++;
            }
        }
        else {
            if (l[i] == '/' && l[i + 1] == '/') {
                while (l[i] != '\n' && i < l.size()) {
                    i++;
                }
            }
            else if (l[i] == '/' && l[i + 1] == '*') {
                BlockDelCom = true;
                i++;
            }
            else {
                result += l[i];
            }
        }
    }
    return result;
}
//Ex.3
string Replace(string result, string search) {
    int pos{0};
    string replace{ "(" + search + ")" };

    while ((pos = result.find(search, pos)) != string::npos) {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return result;
}
//Ex.4
string _str(string str, int start, int end) {
    string new_str{ "" };
    if (start < 0 || end > str.length() || start > end) {
        return "";
    }
    for (int i{ start }; i < end; i++) {
        new_str += str[i];
    }
    return new_str;
}
int StrInt(string l) {
    int num{ 0 };
    int i = 0;
    if (l.empty() || i < 0 || i > l.size()) {
        return 0;
    }
    while (i < l.size() && l[i] >= '0' && l[i] <= '9') {
        num = num * 10 + (l[i] - '0');
        i++;
    }
    return num;
}
bool isDigit(char c) {
    return std::isdigit(static_cast<unsigned char>(c)) != 0;
}
//↓↓
string Calculation(string l) {
    string Ans{ "" };
    string res_str{ "" };
    int res;
    int space1{ 0 }, space2{ 0 };
    string num1_str, num2_str, action{ "" };
    int num1, num2;
    string calc_str{ "" };

    for (int i{ 0 }; i < l.size(); i++) {

        if (l[i] == ' ') {
            space1 = i;
        }
        if (l[i] == '+') {
            action = { " " };
            for (int n = i; n < l.size(); n++) {
                if (l[n] == ' ') {
                    space2 = n;
                    break;
                }
            }
            num1_str = _str(l, space1 + 1, i);
            num2_str = _str(l, i + 1, space2);
            num1 = StrInt(num1_str);
            num2 = StrInt(num2_str);
            res = num1 + num2;
            Ans += to_string(res) += " ";
            continue;
        }
        if (l[i] == '-') {
            action = { " " };
            for (int n = i; n < l.size(); n++) {
                if (l[n] == ' ') {
                    space2 = n;
                    break;
                }
            }
            num1_str = _str(l, space1 + 1, i);
            num2_str = _str(l, i + 1, space2);
            num1 = StrInt(num1_str);
            num2 = StrInt(num2_str);
            res = num1 - num2;
            Ans += to_string(res) += " ";
            continue;
        }

        if (isDigit(l[i])) {
            continue;
        }
        if (action == "") {
            Ans += l[i];
        }
        else {
            action = "";
        }
    }
    return Ans;
}
//↑↑
//Ex.5
string Rome(int num) {
    if (num == 0) return "";
    if (num >= 1000) return "M" + Rome(num - 1000);
    if (num >= 900) return "CM" + Rome(num - 900);
    if (num >= 500) return "D" + Rome(num - 500);
    if (num >= 400) return "CD" + Rome(num - 400);
    if (num >= 100) return "C" + Rome(num - 100);
    if (num >= 90) return "XC" + Rome(num - 90);
    if (num >= 50) return "L" + Rome(num - 50);
    if (num >= 40) return "XL" + Rome(num - 40);
    if (num >= 10) return "X" + Rome(num - 10);
    if (num >= 9) return "IX" + Rome(num - 9);
    if (num >= 5) return "V" + Rome(num - 5);
    if (num >= 4) return "IV" + Rome(num - 4);
    if (num >= 1) return "I" + Rome(num - 1);
    return "";
}
//Ex.6
void Analyze(string path) {
    string filename;
    string filepath;
    string fileext;
    string dirname;
    string basename;

    for (int i = path.length() - 1; i >= 0; i--) {
        if (path[i] == '\\' || path[i] == '/') {
            filename = path.substr(i + 1);
            filepath = path.substr(0, i);
            break;
        }
    }

    if (filename.empty()) {
        filename = path;
    }
    else {
        for (int i = filename.length() - 1; i >= 0; i--) {
            if (filename[i] == '.') {
                fileext = filename.substr(i);
                basename = filename.substr(0, i);
                break;
            }
        }

        if (fileext.empty()) {
            basename = filename;
        }
    }

    if (!filepath.empty()) {
        int start = filepath.find_last_of("/\\");
        dirname = filepath.substr(start + 1);
    }

    cout << "a) " << filepath << '\n';
    cout << "b) " << dirname << '\n';
    cout << "c) " << filename << '\n';
    cout << "d) " << fileext << '\n';
    cout << "e) " << basename << '\n';
}

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Задание_1: " << endl;
    cout << "Было: " << "     Тро    -     ло   -    ло" << endl;
    cout << "Стало: " << Compress("     Тро    -     ло   -    ло") << endl << endl;
    
    cout << "Задание_2: " << endl;
    cout << "Было: " << "   //  Тро    -     ло   -    ло\n /*трололоо\n тролололололо*/ \n проверка" << endl;
    cout << "Стало: " << ComRemove("   //  Тро    -     ло   -    ло\n /*трололоо\n тролололололо*/ \n проверка") << endl << endl;

    cout << "Задание_3: " << endl;
    cout << "Было: " << "abaracadabra и ab" << endl;
    cout << "Стало: " << Replace("abracadabra", "ab") << endl << endl;

    cout << "Задание_4: " << endl;
    cout << "Было: " << "alpha 5+26 beta 72-35 gamma 32+45 etc" << endl;
    cout << "Стало: " << Calculation("alpha 5+26 beta 72-35 gamma 32+45 etc") << endl << endl;

    cout << "Задание_5: " << endl;
    cout << "Было: " << "961" << endl;
    cout << "Стало: " << Rome(961) << endl << endl;

    cout << "Задание_6: " << endl;
    cout << "Было: " << "C/Step/С++lesson_03/Docs/Less03.docx" << endl;
    cout << "Стало: " << endl;
    Analyze("C/Step/С++lesson_03/Docs/Less03.docx");

    return 0;
}