#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void printList(List& ls) {
    Node* temp = ls.first;
    if (temp == NULL) {
        cout << "Empty List";
    }
    while (temp != NULL) {
        cout << temp->value;
        if (temp->next != NULL)
            cout << " --> ";
        temp = temp->next;
    };
    cout << endl; 
}

void insertList(List& ls, string str) {
    Node* temp = ls.first;
    if (temp == NULL) {
        Node* tmp = new Node(str, NULL);
        temp = tmp;
        delete tmp;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp == NULL) cout << "1!" << endl;
    Node* tmp = new Node(str, NULL);
    temp->next = tmp;
}

void deleteFirst(List& ls) {
    Node* temp = ls.first;
    ls.first = ls.first->next;
    delete temp;
}

void deleteLast(List& ls) {
    Node* temp = ls.first;
    if (ls.first->next == NULL) {
        delete ls.first;
        ls.first = NULL;
    }
    else {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
    }
    delete temp->next;
    temp->next = NULL;
}

int numberOfItems(List& ls) {
    int i=0;
    Node* temp = ls.first;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}