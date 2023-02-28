#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node* next;
    Node() {
        this->value = "";
        this->next = NULL;
    }
    Node(string& str, Node* nxt) {
        //strcpy(value, str);
        this->value = str;
        this->next = nxt;
    }
};

struct List {
    Node* first = NULL;
    /*List(Node& nd) {
        first = &nd;
    }*/
    List(string& element) {
        first = new Node(element, NULL);
    }
    ~List(void) {
        delete first;
    }
};

void printList(List& ls) {
    Node* temp = ls.first;
    while (temp != NULL) {
        cout << temp->value << "-->";
        temp = temp->next;
    };
    cout << endl; 
}

void insertList(List& ls, string str) {
    Node* temp = ls.first;
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
    while (temp->next != NULL) {
        temp = temp->next;
    }
}

int main(void) {
    string str = "First!";

    List nlist(str);
    insertList(nlist, "Second!");
    insertList(nlist, "Third!");
    insertList(nlist, "Fpurth!");
    insertList(nlist, "Fifth!");
    printList(nlist);
    deleteFirst(nlist);
    printList(nlist);

    return 0;
}