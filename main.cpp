#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

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

int main(void) {
    string comm;
    set<string> commands;
    setCommands(commands);

    cin >> comm;
    exists(commands, comm);


    return 0;
}