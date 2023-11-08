#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return 0;
        }
        int popp_d = top->data;
        Node* popp_n = top;
        top = top->next;
        delete popp_n;
        return popp_d;
    }

    int peek() {
        if (isEmpty()) {
            return 0;
        }
        return top->data;
    }
};