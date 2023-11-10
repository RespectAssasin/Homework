#include <iostream>
#include <string>
using namespace std;

class Man {
public:
    Man(string name, string surname, int age) : name(name), surname(surname), age(age) {}
    Man(){}

    virtual void say() {
        cout << "Меня зовут " << name << " " << surname << ", мне " << age << " лет" << endl;
    }

protected:
    string name;
    string surname;
    int age;
};

class Teacher : public Man {
public:
    Teacher(string name, string surname, int age, string department) : Man(name, surname, age), department(department) {}

    void say() {
        Man::say();
        cout << "Я учитель, моя кафедра: " << department << endl;
    }

protected:
    string department;
};

class Student : public Man {
public:
    Student(string name, string surname, int age, int group) : Man(name, surname, age), group(group) {}

    void say() {
        Man::say();
        cout << "Я студент, моя группа: " << group << endl;
    }

private:
    int group;
};

class Security : public Man {
public:
    Security(string name, string surname, int age, string position) : Man(name, surname, age), position(position) {}

    void say() {
        Man::say();
        cout << "Я сотрудник охраны, моя должность: " << position << endl;
    }

protected:
    string position;
};

class MegaTeacher : public Teacher {
public:
    MegaTeacher(string name, string surname, int age, string department, string second_job) : Teacher(name, surname, age, department), second_job(second_job) {}

    void say() {
        Teacher::say();
        cout << "Моя вторая работа: " << second_job << endl;
    }

protected:
    string second_job;
};

int main() {
    setlocale(LC_ALL, "RU");

    Man man("Сергей", "Сергеев", 24);
    man.say();
    cout << endl;

    Teacher teacher("Иван", "Иванов", 35, "математики");
    teacher.say();
    cout << endl;

    Student student("Петр", "Петров", 22, 3);
    student.say();
    cout << endl;

    Security security("Семен", "Семенов", 30, "Младший сержант");
    security.say();
    cout << endl;

    MegaTeacher megateacher("Александр", "Александрович", 44, "философия", "президент");
    megateacher.say();

    return 0;
}