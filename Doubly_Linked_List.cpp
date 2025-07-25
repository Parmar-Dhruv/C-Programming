#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node* head = nullptr;

void insertFront(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFront() {
    if (!head) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void deleteEnd() {
    if (!head) {
        cout << "List is Empty\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) return;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void display() {
    if (!head) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        ++count;
        temp = temp->next;
    }
    cout << count << endl;
}

int main() {
    int choice, val, key;
    while (cin >> choice && choice != 0) {
        if (choice == 1) {
            cin >> val;
            insertFront(val);
        } else if (choice == 2) {
            cin >> val;
            insertEnd(val);
        } else if (choice == 3) {
            deleteFront();
        } else if (choice == 4) {
            deleteEnd();
        } else if (choice == 5) {
            cin >> key >> val;
            insertAfter(key, val);
        } else if (choice == 6) {
            display();
        } else if (choice == 7) {
            countNodes();
        }
    }   
    return 0;
}
