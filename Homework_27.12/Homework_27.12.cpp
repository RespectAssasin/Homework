#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//1
class SquareArray {
public:
    explicit SquareArray(size_t size) : size_(size), array_(new int* [size]) {
        if (size > 100) {
            throw invalid_argument("Size must be less than or equal to 100");
        }
        array_[0] = new int[size * size];
        for (size_t i = 1; i < size; ++i) {
            array_[i] = array_[i - 1] + size;
        }
        fill(begin(), end(), 0);
    }

    ~SquareArray() {
        delete[] array_[0];
        delete[] array_;
    }

    int* begin() {
        return array_[0];
    }

    int* end() {
        return array_[0] + size_ * size_;
    }

    size_t size() const {
        return size_;
    }

    int& operator()(size_t i, size_t j) {
        if (i >= size_ || j >= size_) {
            throw out_of_range("Index out of range");
        }
        return array_[i][j];
    }

    friend ostream& operator<<(ostream& os, SquareArray& arr) {
        for (int i = 0; i < arr.size_; ++i) {
            for (int j = 0; j < arr.size_; ++j) {
                os << arr(i, j) << ' ';
            }
            os << '\n';
        }
        return os;
    }

    size_t countPositiveBelowDiagonal() const {
        size_t count = 0;
        for (size_t i = 0; i < size_; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (array_[i][j] > 0) {
                    ++count;
                }
            }
        }
        return count;
    }

private:
    size_t size_;
    int** array_;
};

//2
class Student {
public:
    Student(const string& name, int age, double gpa) : name_(name), age_(age), gpa_(gpa) {}

    const string& getName() const {
        return name_;
    }

    int getAge() const {
        return age_;
    }

    double getGPA() const {
        return gpa_;
    }

    void setName(const string& name) {
        name_ = name;
    }

    void setAge(int age) {
        age_ = age;
    }

    void setGPA(double gpa) {
        gpa_ = gpa;
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Name: " << student.name_ << ", Age: " << student.age_ << ", GPA: " << student.gpa_;
        return os;
    }

private:
    string name_;
    int age_;
    double gpa_;
};
class School {
public:
    void addStudent(const Student& student) {
        students_.push_back(student);
    }

    void removeStudent(size_t index) {
        if (index >= students_.size()) {
            throw out_of_range("Index out of range");
        }
        students_.erase(students_.begin() + index);
    }

    void modifyStudent(size_t index, const Student& newStudent) {
        if (index >= students_.size()) {
            throw out_of_range("Index out of range");
        }
        students_[index] = newStudent;
    }

    void printStudents() const {
        for (size_t i = 0; i < students_.size(); ++i) {
            cout << i + 1 << ". " << students_[i] << '\n';
        }
    }

private:
    vector<Student> students_;
};

//3
class Shape {
public:
    virtual void move(double dx, double dy) = 0;
    virtual void resize(double factor) = 0;
    virtual double area() const = 0;
    virtual void print() const = 0;
};
class Circle : public Shape {
public:
    Circle(double x, double y, double radius) : x_(x), y_(y), radius_(radius) {}

    void move(double dx, double dy) override {
        x_ += dx;
        y_ += dy;
    }

    void resize(double factor) override {
        radius_ *= factor;
    }

    double area() const override {
        return 3.1415 * radius_ * radius_;
    }

    void print() const override {
        cout << "Circle: center (" << x_ << ", " << y_ << "), radius " << radius_ << ", area " << area() << '\n';
    }

private:
    double x_, y_, radius_;
};
class Rectangle : public Shape {
public:
    Rectangle(double x, double y, double width, double height) : x_(x), y_(y), width_(width), height_(height) {}

    void move(double dx, double dy) override {
        x_ += dx;
        y_ += dy;
    }

    void resize(double factor) override {
        width_ *= factor;
        height_ *= factor;
    }

    double area() const override {
        return width_ * height_;
    }

    void print() const override {
        cout << "Rectangle: top left corner (" << x_ << ", " << y_ << "), width " << width_ << ", height " << height_ << ", area " << area() << '\n';
    }

private:
    double x_, y_, width_, height_;
};

//4
class Book {
public:
    Book(const string& title, const string& author, int year) : title_(title), author_(author), year_(year) {}

    const string& getTitle() const {
        return title_;
    }

    const string& getAuthor() const {
        return author_;
    }

    int getYear() const {
        return year_;
    }

    void setTitle(const string& title) {
        title_ = title;
    }

    void setAuthor(const string& author) {
        author_ = author;
    }

    void setYear(int year) {
        year_ = year;
    }

    bool compareByTitle(const Book& other) const {
        return title_ < other.title_;
    }

    bool compareByAuthor(const Book& other) const {
        return author_ < other.author_;
    }

    bool compareByYear(const Book& other) const {
        return year_ < other.year_;
    }

private:
    string title_;
    string author_;
    int year_;
};
class HomeLibrary {
public:
    void addBook(const Book& book) {
        books_.push_back(book);
    }

    bool removeBook(const Book& book) {
        for (size_t i = 0; i < books_.size(); ++i) {
            if (books_[i].getTitle() == book.getTitle() && books_[i].getAuthor() == book.getAuthor() && books_[i].getYear() == book.getYear()) {
                books_.erase(books_.begin() + i);
                return true;
            }
        }
        return false;
    }

    void sortBooksByTitle() {
        sort(books_.begin(), books_.end(), [](const Book& a, const Book& b) {
            return a.compareByTitle(b);
            });
    }

    void sortBooksByAuthor() {
        sort(books_.begin(), books_.end(), [](const Book& a, const Book& b) {
            return a.compareByAuthor(b);
            });
    }

    void sortBooksByYear() {
        sort(books_.begin(), books_.end(), [](const Book& a, const Book& b) {
            return a.compareByYear(b);
            });
    }

    void printBooks() const {
        for (const auto& book : books_) {
            cout << book.getTitle() << " by " << book.getAuthor() << " (" << book.getYear() << ")\n";
        }
    }

    void findBooksByAuthor(const string& author) const {
        for (const auto& book : books_) {
            if (book.getAuthor() == author) {
                cout << book.getTitle() << " by " << book.getAuthor() << " (" << book.getYear() << ")\n";
            }
        }
    }

    void findBooksByYear(int year) const {
        for (const auto& book : books_) {
            if (book.getYear() == year) {
                cout << book.getTitle() << " by " << book.getAuthor() << " (" << book.getYear() << ")\n";
            }
        }
    }

private:
    vector<Book> books_;
};

//5
class Contact {
public:
    Contact(const string& name, const string& phone, const string& birthdate)
        : name_(name), phone_(phone), birthdate_(birthdate) {}

    const string& getName() const {
        return name_;
    }

    const string& getPhone() const {
        return phone_;
    }

    const string& getBirthdate() const {
        return birthdate_;
    }

    void setName(const string& name) {
        name_ = name;
    }

    void setPhone(const string& phone) {
        phone_ = phone;
    }

    void setBirthdate(const string& birthdate) {
        birthdate_ = birthdate;
    }

    bool compareByName(const Contact& other) const {
        return name_ < other.name_;
    }

    bool compareByPhone(const Contact& other) const {
        return phone_ < other.phone_;
    }

    bool compareByBirthdate(const Contact& other) const {
        return birthdate_ < other.birthdate_;
    }

private:
    string name_;
    string phone_;
    string birthdate_;
};
class AddressBook {
public:
    void addContact(const Contact& contact) {
        contacts_.push_back(contact);
    }

    bool removeContact(const Contact& contact) {
        for (size_t i = 0; i < contacts_.size(); ++i) {
            if (contacts_[i].compareByName(contact) || contacts_[i].compareByPhone(contact) || contacts_[i].compareByBirthdate(contact)) {
                contacts_.erase(contacts_.begin() + i);
                return true;
            }
        }
        return false;
    }

    void sortContactsByName() {
        sort(contacts_.begin(), contacts_.end(), [](const Contact& a, const Contact& b) {
            return a.compareByName(b);
            });
    }

    void sortContactsByPhone() {
        sort(contacts_.begin(), contacts_.end(), [](const Contact& a, const Contact& b) {
            return a.compareByPhone(b);
            });
    }

    void sortContactsByBirthdate() {
        sort(contacts_.begin(), contacts_.end(), [](const Contact& a, const Contact& b) {
            return a.compareByBirthdate(b);
            });
    }

    void printContacts() const {
        for (const auto& contact : contacts_) {
            cout << contact.getName() << ": " << contact.getPhone() << ", " << contact.getBirthdate() << "\n";
        }
    }

    void findContactsByName(const string& name) const {
        for (const auto& contact : contacts_) {
            if (contact.getName() == name) {
                cout << contact.getName() << ": " << contact.getPhone() << ", " << contact.getBirthdate() << "\n";
            }
        }
    }

    void findContactsByPhone(const string& phone) const {
        for (const auto& contact : contacts_) {
            if (contact.getPhone() == phone) {
                cout << contact.getName() << ": " << contact.getPhone() << ", " << contact.getBirthdate() << "\n";
            }
        }
    }

    void findContactsByBirthdate(const string& birthdate) const {
        for (const auto& contact : contacts_) {
            if (contact.getBirthdate() == birthdate) {
                cout << contact.getName() << ": " << contact.getPhone() << ", " << contact.getBirthdate() << "\n";
            }
        }
    }

private:
    vector<Contact> contacts_;
};

//6
class Student1 {
public:
    Student1(const string& name, const string& birthdate, const string& phone)
        : name_(name), birthdate_(birthdate), phone_(phone) {}

    const string& getName() const {
        return name_;
    }

    const string& getBirthdate() const {
        return birthdate_;
    }

    const string& getPhone() const {
        return phone_;
    }

    void setName(const string& name) {
        name_ = name;
    }

    void setBirthdate(const string& birthdate) {
        birthdate_ = birthdate;
    }

    void setPhone(const string& phone) {
        phone_ = phone;
    }

    bool compareByName(const Student1& other) const {
        return name_ < other.name_;
    }

    bool compareByBirthdate(const Student1& other) const {
        return birthdate_ < other.birthdate_;
    }

    bool compareByPhone(const Student1& other) const {
        return phone_ < other.phone_;
    }

private:
    string name_;
    string birthdate_;
    string phone_;
};
class StudentGroup {
public:
    void addStudent(const Student1& student) {
        students_.push_back(student);
    }

    bool removeStudent(const Student1& student) {
        for (size_t i = 0; i < students_.size(); ++i) {
            if (students_[i].compareByName(student) || students_[i].compareByBirthdate(student) || students_[i].compareByPhone(student)) {
                students_.erase(students_.begin() + i);
                return true;
            }
        }
        return false;
    }

    void sortStudentsByName() {
        sort(students_.begin(), students_.end(), [](const Student1& a, const Student1& b) {
            return a.compareByName(b);
            });
    }

    void sortStudentsByBirthdate() {
        sort(students_.begin(), students_.end(), [](const Student1& a, const Student1& b) {
            return a.compareByBirthdate(b);
            });
    }

    void sortStudentsByPhone() {
        sort(students_.begin(), students_.end(), [](const Student1& a, const Student1& b) {
            return a.compareByPhone(b);
            });
    }

    void printStudents() const {
        for (const auto& student : students_) {
            cout << student.getName() << ": " << student.getBirthdate() << ", " << student.getPhone() << "\n";
        }
    }

    void findStudentsByName(const string& name) const {
        for (const auto& student : students_) {
            if (student.getName() == name) {
                cout << student.getName() << ": " << student.getBirthdate() << ", " << student.getPhone() << "\n";
            }
        }
    }

    void findStudentsByBirthdate(const string& birthdate) const {
        for (const auto& student : students_) {
            if (student.getBirthdate() == birthdate) {
                cout << student.getName() << ": " << student.getBirthdate() << ", " << student.getPhone() << "\n";
            }
        }
    }

    void findStudentsByPhone(const string& phone) const {
        for (const auto& student : students_) {
            if (student.getPhone() == phone) {
                cout << student.getName() << ": " << student.getBirthdate() << ", " << student.getPhone() << "\n";
            }
        }
    }

private:
    vector<Student1> students_;
};

//7
class CPoint {
public:
    CPoint(int x, int y) : x_(x), y_(y) {}

    int getX() const {
        return x_;
    }

    int getY() const {
        return y_;
    }

    void setX(int x) {
        x_ = x;
    }

    void setY(int y) {
        y_ = y;
    }

private:
    int x_, y_;
};
class CColoredPoint : public CPoint {
public:
    CColoredPoint(int x, int y, int color) : CPoint(x, y), color_(color) {}

    int getColor() const {
        return color_;
    }

    void setColor(int color) {
        color_ = color;
    }

private:
    int color_;
};
class CLine {
public:
    CLine(const CPoint& p1, const CPoint& p2) : p1_(p1), p2_(p2) {}

    const CPoint& getP1() const {
        return p1_;
    }

    const CPoint& getP2() const {
        return p2_;
    }

private:
    CPoint p1_, p2_;
};
class CColoredLine : public CLine {
public:
    CColoredLine(const CPoint& p1, const CPoint& p2, int color) : CLine(p1, p2), color_(color) {}

    int getColor() const {
        return color_;
    }

    void setColor(int color) {
        color_ = color;
    }

private:
    int color_;
};
class CPolyLine {
public:
    void addPoint(const CPoint& point) {
        points_.push_back(point);
    }

    const CPoint& getPoint(size_t index) const {
        return points_[index];
    }

    size_t size() const {
        return points_.size();
    }

private:
    vector<CPoint> points_;
};
class CColoredPolyLine : public CPolyLine {
public:
    void setColor(int color) {
        color_ = color;
    }

    int getColor() const {
        return color_;
    }

private:
    int color_;
};

//8
class CVehicle {
public:
    CVehicle(int x, int y) : x_(x), y_(y) {}

    int getX() const {
        return x_;
    }

    int getY() const {
        return y_;
    }

    virtual double getPrice() const = 0;
    virtual double getSpeed() const = 0;
    virtual int getYear() const = 0;

protected:
    int x_, y_;
};
class CPlane : public CVehicle {
public:
    CPlane(int x, int y, double price, double speed, int year, int height, int passengers)
        : CVehicle(x, y), price_(price), speed_(speed), year_(year), height_(height), passengers_(passengers) {}

    double getPrice() const override {
        return price_;
    }

    double getSpeed() const override {
        return speed_;
    }

    int getYear() const override {
        return year_;
    }

    int getHeight() const {
        return height_;
    }

    int getPassengers() const {
        return passengers_;
    }

private:
    double price_;
    double speed_;
    int year_;
    int height_;
    int passengers_;
};
class CCar : public CVehicle {
public:
    CCar(int x, int y, double price, double speed, int year)
        : CVehicle(x, y), price_(price), speed_(speed), year_(year) {}

    double getPrice() const override {
        return price_;
    }

    double getSpeed() const override {
        return speed_;
    }

    int getYear() const override {
        return year_;
    }

private:
    double price_;
    double speed_;
    int year_;
};
class CShip : public CVehicle {
public:
    CShip(int x, int y, double price, double speed, int year, int passengers, const string& port)
        : CVehicle(x, y), price_(price), speed_(speed), year_(year), passengers_(passengers), port_(port) {}

    double getPrice() const override {
        return price_;
    }

    double getSpeed() const override {
        return speed_;
    }

    int getYear() const override {
        return year_;
    }

    int getPassengers() const {
        return passengers_;
    }

    const string& getPort() const {
        return port_;
    }

private:
    double price_;
    double speed_;
    int year_;
    int passengers_;
    string port_;
};

int main() {
    //1
    /*SquareArray arr(5);
    arr(1, 1) = 1;
    arr(2, 2) = 2;
    arr(3, 3) = 3;
    cout << arr;
    cout << "Count of positive elements below diagonal: " << arr.countPositiveBelowDiagonal() << '\n';*/

    //2
    /*School school;
    int choice;
    while (true) {
        cout << "1. Add student\n2. Remove student\n3. Modify student\n4. Print students\n5. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            string name;
            int age;
            double gpa;
            cout << "Enter name, age, and GPA: ";
            cin >> name >> age >> gpa;
            school.addStudent(Student(name, age, gpa));
            break;
        }
        case 2: {
            size_t index;
            cout << "Enter index of student to remove: ";
            cin >> index;
            school.removeStudent(index - 1);
            break;
        }
        case 3: {
            size_t index;
            string name;
            int age;
            double gpa;
            cout << "Enter index of student to modify: ";
            cin >> index;
            cout << "Enter new name, age, and GPA: ";
            cin >> name >> age >> gpa;
            school.modifyStudent(index - 1, Student(name, age, gpa));
            break;
        }
        case 4: {
            school.printStudents();
            break;
        }
        case 5: {
            return 0;
        }
        default: {
            cout << "Invalid choice\n";
        }
        }
    }*/

    //3
    /*Circle circle(0, 0, 5);
    circle.print();
    circle.move(1, 2);
    circle.resize(2);
    circle.print();

    Rectangle rectangle(0, 0, 4, 6);
    rectangle.print();
    rectangle.move(3, 4);
    rectangle.resize(3);
    rectangle.print();*/

    //4
    /*HomeLibrary library;
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 1813));

    cout << "Initial library:\n";
    library.printBooks();

    cout << "\nSort by title:\n";
    library.sortBooksByTitle();
    library.printBooks();

    cout << "\nRemove Pride and Prejudice:\n";
    library.removeBook(Book("Pride and Prejudice", "Jane Austen", 1813));
    library.printBooks();

    cout << "\nFind books by author \"Harper Lee\":\n";
    library.findBooksByAuthor("Harper Lee");

    cout << "\nFind books by year 1960:\n";
    library.findBooksByYear(1960);*/
    
    //5
    /*AddressBook addressBook;
    addressBook.addContact(Contact("John Doe", "123-456-7890", "01/01/1990"));
    addressBook.addContact(Contact("Jane Doe", "234-567-8901", "02/02/1980"));

    cout << "Initial address book:\n";
    addressBook.printContacts();

    cout << "\nSort by name:\n";
    addressBook.sortContactsByName();
    addressBook.printContacts();

    cout << "\nRemove John Doe:\n";
    addressBook.removeContact(Contact("John Doe", "123-456-7890", "01/01/1990"));
    addressBook.printContacts();

    cout << "\nFind contacts by phone \"234-567-8901\":\n";
    addressBook.findContactsByPhone("234-567-8901");*/

    //6
    /*StudentGroup studentGroup;
    studentGroup.addStudent(Student1("John Doe", "01/01/1990", "123-456-7890"));
    studentGroup.addStudent(Student1("Jane Doe", "02/02/1980", "234-567-8901"));

    cout << "Initial student group:\n";
    studentGroup.printStudents();

    cout << "\nSort by name:\n";
    studentGroup.sortStudentsByName();
    studentGroup.printStudents();

    cout << "\nRemove John Doe:\n";
    studentGroup.removeStudent(Student1("John Doe", "01/01/1990", "123-456-7890"));
    studentGroup.printStudents();

    cout << "\nFind students by birthdate \"02/02/1980\":\n";
    studentGroup.findStudentsByBirthdate("02/02/1980");*/
    
    //7
    /*CColoredPoint p1(1, 2, 3);
    CColoredPoint p2(4, 5, 6);
    CColoredLine line(p1, p2, 7);

    cout << "Line: (" << line.getP1().getX() << ", " << line.getP1().getY()
        << ") to (" << line.getP2().getX() << ", " << line.getP2().getY()
        << ") color: " << line.getColor() << "\n";

    CColoredPolyLine polyLine;
    polyLine.addPoint(CPoint(1, 1));
    polyLine.addPoint(CPoint(2, 2));
    polyLine.addPoint(CPoint(3, 3));
    polyLine.setColor(4);

    cout << "Polyline: ";
    for (size_t i = 0; i < polyLine.size(); ++i) {
        cout << "(" << polyLine.getPoint(i).getX() << ", " << polyLine.getPoint(i).getY() << ")";
    }
    cout << " color: " << polyLine.getColor() << "\n";*/

    //8
    /*CPlane plane(1, 2, 100000.0, 600.0, 2010, 10000, 200);
    CCar car(3, 4, 50000.0, 200.0, 2015);
    CShip ship(5, 6, 200000.0, 50.0, 2005, 500, "New York");

    cout << "Plane: x=" << plane.getX() << ", y=" << plane.getY()
        << ", price=" << plane.getPrice() << ", speed=" << plane.getSpeed()
        << ", year=" << plane.getYear() << ", height=" << plane.getHeight()
        << ", passengers=" << plane.getPassengers() << "\n";

    cout << "Car: x=" << car.getX() << ", y=" << car.getY()
        << ", price=" << car.getPrice() << ", speed=" << car.getSpeed()
        << ", year=" << car.getYear() << "\n";

    cout << "Ship: x=" << ship.getX() << ", y=" << ship.getY()
        << ", price=" << ship.getPrice() << ", speed=" << ship.getSpeed()
        << ", year=" << ship.getYear() << ", passengers=" << ship.getPassengers()
        << ", port=" << ship.getPort() << "\n";*/
     
    return 0;
}