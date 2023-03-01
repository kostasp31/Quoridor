#include <iostream>
#include <string>
#include "header.h"

using namespace std;

//A --> B --> C

int main(void) {
    string str = "First!";
    List nlist(str);

    deleteFirst(nlist);
    printList(nlist);
    insertList(nlist, "Insertion");
    printList(nlist);

    return 0;
}