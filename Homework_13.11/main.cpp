#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoubleList {
    Node* head;
    Node* tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void AddFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        if (tail == nullptr) {
            tail = newNode;
        }
        head = newNode;
    }

    void AddBack(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) {
            head = newNode;
        }
        tail = newNode;
    }

    void RemoveFront() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        if (tail == temp) {
            tail = nullptr;
        }
        delete temp;
    }

    void RemoveBack() {
        if (tail == nullptr) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        if (head == temp) {
            head = nullptr;
        }
        delete temp;
    }

    void Print() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertToPos(int pos, int data) {
        if (pos == 0) {
            AddFront(data);
            return;
        }

        Node* curr = head;
        int count = 0;
        while (curr != nullptr && count != pos) {
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) {
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = curr;
        newNode->prev = curr->prev;

        if (curr->prev != nullptr) {
            curr->prev->next = newNode;
        }
        curr->prev = newNode;

        if (curr == head) {
            head = newNode;
        }
    }

    int Find(int value) const {
        Node* curr = head;
        int pos = 0;
        while (curr != nullptr) {
            if (curr->data == value) {
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1;
    }

    void RemoveAll() {
        while (head != nullptr) {
            RemoveFront();
        }
    }

    void Reverse() {
        Node* curr = head;
        Node* temp = nullptr;
        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    DoubleList operator+ (const DoubleList& other) const {
        DoubleList result;
        Node* curr = head;
        while (curr != nullptr) {
            result.AddBack(curr->data);
            curr = curr->next;
        }
        curr = other.head;
        while (curr != nullptr) {
            result.AddBack(curr->data);
            curr = curr->next;
        }
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    DoubleList list;
    list.AddFront(5);
    list.AddFront(10);
    list.AddBack(15);
    list.AddBack(20);
    cout << "После добавления: ";
    list.Print();

    list.RemoveFront();
    list.RemoveBack();
    cout << "После удаления: ";
    list.Print();

    list.InsertToPos(1, 7);
    cout << "После вставки: ";
    list.Print();

    cout << "Нашёл: " << list.Find(7) << endl;
    cout << "Нашёл: " << list.Find(10) << endl;

    list.RemoveAll();
    cout << "Пустой лист: ";
    list.Print();

    list.AddFront(5);
    list.AddBack(10);
    cout << "После добавления: ";
    list.Print();

    list.Reverse();
    cout << "Перевернутый лист: ";
    list.Print();

    DoubleList list2;
    list2.AddFront(1);
    list2.AddBack(2);
    list2.AddBack(3);

    DoubleList list3 = list + list2;
    cout << "Два листа: ";
    list3.Print();

    return 0;
}