#include <string>

struct Node {
    std::string value;
    Node* next;
    Node() {
        this->value = "";
        this->next = NULL;
    }
    Node(std::string& str, Node* nxt) {
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
    List(std::string& element) {
        first = new Node(element, NULL);
    }
    ~List(void) {
        Node* temp = first;
        while (temp != NULL) {
            Node* tmp = temp;
            delete temp;
            temp = tmp->next;
        }
    }
};

void printList(List&);
void insertList(List&, std::string);
void deleteFirst(List&);
void deleteLast(List&);
int numberOfItems(List&);
