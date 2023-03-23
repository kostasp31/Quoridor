#include <iostream>
#include <string>
#include <set>
#include <bits/stdc++.h>


using namespace std;
enum color {W, B};

class pawn {
    public:
        int x, y;
        color clr;
        pawn(int xi, int yi, color c) {
            this->x = xi;
            this->y = yi;
            this->clr = c;
        }
        void setCoords(int xi, int yi) {
            this->x = xi;
            this->y = yi;
        }
};

class board {
    private:
        char** table = NULL;
        bool initiallized = false;
        int dim=0, rows=0, columns=0;
        int Bwalls, Wwalls;
    public:    
        bool isInit(void)const {return initiallized;}
        void setDim(int dimension) {
            dim = dimension;
            columns= (4*dim)+1;
            rows = (2*dim)+1;
        }
        void allocateTable(void) {
            if (initiallized == true) {
                for(int i=0; i<rows; i++)
                    delete[] table[i];
                delete[] table;
                this->table = NULL;
                initiallized = false;
            }
            table = new char*[rows];
            for (int i=0; i<rows; i++) {
                table[i] = new char[columns];
            }
            initiallized = true;
        }
        void delTable(void) {
            for(int i=0; i<rows; i++)
                delete[] table[i];
            delete[] table;
        }

        void initTable(void) {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<columns; j++) {
                    if ((i%2==0) || (i==0)) {
                        if ((j%4 == 0) || (j==0)) {
                            table[i][j] = '+';	/*Put "+" in the sections of the cells*/
                        }
                        else {
                            table[i][j] = '-';	/*Put '-' in the up and down of cells*/
                        }
                    }
                    else {
                        if ((j%4 == 0) || (j==0)) {
                            table[i][j] = '|';	/*Put '|' in the left and right of cells*/
                        }
                        else {
                            table[i][j] = ' ';	/*The center of the cells is empty*/
                        }
                    }
                }
            }   
            Bwalls = -1;
            Wwalls = -1;
        }

        void clearB(void) {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<columns; j++) {
                    if (i%2!=0 && j%4!=0) {
                            table[i][j] = ' ';
                    }
                }
            }   
        }

        int getDim(void)const {
            return this->dim;
        }

        void setChar(int xi, int yi, char ch) {
            int row, col;
            row = (xi*2)+1;
            col = (yi*4)+2;
            this->table[row][col] = ch;
            return;
        }

        void printTable(void)const {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<columns; j++)
                    cout << table[i][j];
                cout << endl;
            }
        }

        void setWalls(int n, color clc) {
            if (clc == W)
                Wwalls = n;
            if (clc == B)
                Bwalls = n;
        }
        int getWalls(color clc)const {
            if (clc == W)
                return this->Wwalls;
            if (clc == B)
                return this->Bwalls;
        }
};

void setCommands(set<string>& st) {
    st.insert("name");
    st.insert("known_command");
    st.insert("list_commands");
    st.insert("quit");
    st.insert("boardsize");
    st.insert("clear_board");
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

void clrBoard(board brd, pawn& pw, pawn& pb) {
    brd.clearB();
    int D = brd.getDim();
    brd.setChar(0, D/2, 'W');
    brd.setChar(D-1, D/2, 'B');
    cout << "=\n\n";
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

void setBoard(string& sizeS, board& bd) {
    int dim = stoi(sizeS);
    if (dim%2==0 || dim <5 || dim > 21) {
        cout << "? Unacceptable size\n\n";
        return;
    }
    bd.setDim(dim);
    bd.allocateTable();
    bd.initTable();
    cout << "=\n\n";
}

void setWalls(board& bd, string& nof) {
    int numberOfWalls = stoi(nof);
    bd.setWalls(numberOfWalls, W);
    bd.setWalls(numberOfWalls, B);
    cout << "=\n\n";
}

int main(void) {
    string comm;
    string word1, word2, word3, word4;
    set<string> commands;
    setCommands(commands);

    board brd;
    pawn White(-1, -1, W), Black(-1, -1, B);
    do {
        getline(cin, comm);
        getTokens(comm, word1, word2, word3, word4);

        if (!exists(commands, word1)) continue;
        if (word1 == "name") printName();
        if (word1 == "list_commands") printCommands(commands);
        if (word1 == "known_command") check_com(commands, word2);
        if (word1 == "boardsize") setBoard(word2, brd);
        if (word1 == "showboard") brd.printTable();
        if (word1 == "clear_board") clrBoard(brd, White, Black);
        if (word1 == "walls") setWalls(brd, word2);
    } while (comm != "quit");

    brd.delTable();
    cout << "=\n\n";
    return 0;
}