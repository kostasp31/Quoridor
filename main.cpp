#include <iostream>
#include <string>

using namespace std;

string getCommand(string& com) {
    cin >> com;
    return com;
}

int main(void) {
    string command;
    while (1) {
        cout << getCommand(command) << endl;
    }
    return 0;
}