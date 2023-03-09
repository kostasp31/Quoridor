#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

#include <bits/stdc++.h>


using namespace std;

class board {
    private:
        char** table = NULL;
        bool initiallized = false;
        int dim=0;
    public:    
        bool isInit(void)const {return initiallized;}
        void setDim(int dimension) {dim = dimension;}
        void initallizeTable(void) {
            if (initiallized == true) {
                for(int i=0; i<dim; i++)
                    delete[] table[i];
                delete[] table;
                this->table = NULL;
                initiallized = false;
            }
            table = new char*[dim];
            for (int i=0; i<dim; i++) {
                table[i] = new char[dim];
            }
            initiallized = true;
        }
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
    st.insert("playwall");
    st.insert("undo");
    st.insert("winner");
    st.insert("showboard");
}

void printCommands(const set<string>& commands) {
    cout << "=\n";
    for (string const& str : commands)
        cout << str << '\n';
    cout << "\n";
}

bool exists(const set<string>& commands, const string& com) {
    const bool inSet = commands.find(com) != commands.end();
    return inSet;
}

void check_com(const set<string>& commands, const string& searching_for) {
    if (exists(commands, searching_for))
        cout << "= true\n\n";
    else    
        cout << "= false\n\n";
}

void printName(void) {
    cout << "= IP Quoridor renovated be KostasP\n\n";
}

void getTokens(const string& initial_comm, string& w1, string& w2, string& w3, string& w4) {
    stringstream ss(initial_comm);  
    string word;
    int i=0;
    while (ss >> word) { // Extract word from the stream.
        switch (i) {
        case 0:
            w1 = word;
            i++;
            break;
        case 1:
            w2 =word;
            i++;
            break;
        case 2:
            w3 = word;
            i++;
            break;
        case 3:
            w4 = word;
            i++;
            break;
        }
    }
}

int main(void) {
    string comm;
    string word1, word2, word3, word4;
    set<string> commands;
    setCommands(commands);

    do {
        getline(cin, comm);
        getTokens(comm, word1, word2, word3, word4);

        if (!exists(commands, word1)) continue;
        if (word1 == "name") printName();
        if (word1 == "list_commands") printCommands(commands);
        if (word1 == "known_command") check_com(commands, word2);
    } while (comm != "quit");

    cout << "=\n\n";
    return 0;
}