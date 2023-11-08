#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    Node* getHead() const {
        return head;
    }

    void add(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    LinkedList* clone() const {
        LinkedList* cloneList = new LinkedList;
        Node* curr = head;

        while (curr != nullptr) {
            cloneList->add(curr->data);
            curr = curr->next;
        }
        return cloneList;
    }

    LinkedList* operator+(const LinkedList& other) const {
        LinkedList* newList = new LinkedList;
        Node* curr = head;

        while (curr != nullptr) {
            newList->add(curr->data);
            curr = curr->next;
        }

        curr = other.head;
        while (curr != nullptr) {
            newList->add(curr->data);
            curr = curr->next;
        }

        return newList;
    }

    LinkedList* operator*(const LinkedList& other) const {
        LinkedList* newList = new LinkedList;
        Node* curr1 = head;
        Node* curr2 = other.head;

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data == curr2->data) {
                newList->add(curr1->data);
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return newList;
    }
};