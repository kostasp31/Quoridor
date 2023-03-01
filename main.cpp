#include <iostream>
#include <string>
#include <set>

using namespace std;

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

int main(void) {
    set<string> commands;
    setCommands(commands);

    for (string const& str : commands) {
        std::cout << str << ' ';
    }
    return 0;
}