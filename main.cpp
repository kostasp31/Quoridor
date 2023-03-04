#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <sstream>

using namespace std;

class board {
    char** table = NULL;

};

class game {
    //board brd = new board();

};

void setCommands(set<string>& st) {
    st.insert("name");
    st.insert("known_command");
    st.insert("list_commands");
    st.insert("quit");
    st.insert("boardsize");
    st.insert("clearboard");
    st.insert("walls");
    st.insert("playmove");
    st.insert("genmove");
    st.insert("playwaall");
    st.insert("undo");
    st.insert("winner");
    st.insert("showboard");
}

void printCommands(const set<string>& commands) {
    for (string const& str : commands)
        std::cout << str << '\n';
}

void exists(const set<string>& commands, const string& com) {
    const bool inSet = commands.find(com) != commands.end();
    if (inSet)
        cout << "= true\n\n";
    else
        cout << "= false\n\n";
}

void printName(void) {
    cout << "= IP Quoridor renovated be KostasP\n\n";
}

int main(void) {
    string comm;
    string word, word1, word2, word3, word4;
    set<string> commands;
    setCommands(commands);

    cin >> comm;

    while (comm != "quit") {
        istringstream iss(comm);
        int i=0;
        while (getline(iss, word, ' ')) {
            switch (i) {
            case 0:
                word1 = word;
                i++;
                break;
            case 1:
                word2 = word;
                i++;
                break;
            case 2:
                word3 = word;
                i++;                
                break;
            case 3:
                word4 = word;
                i++;
                break;
            }
        }
        cout << word1 << endl << word2 << endl << word3 << endl << word4 << endl;
        cin >> comm;
    }
    cout << "=\n\n";
 

    return 0;
}