#pragma once

enum color {W, B};

using namespace std;
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
            char ch = 'A';
            int no = 1;
            cout << "  ";
            for (int k=0; k<dim; k++) {
                cout << "   " << no;
                no++;
            }
            cout << endl;
            for (int i=0; i<rows; i++) {
                if (i%2==0)
                    cout << "   ";
                else {
                    cout << " " << ch << " ";
                    ch++;
                }
                for (int j=0; j<columns; j++)
                    cout << table[i][j];
                if (i==3)
                    cout << "   White Walls: " << Wwalls;
                if (i==5)
                    cout << "   Black Walls: " << Bwalls;
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


void setCommands(set<string>& st);
void printCommands(const set<string>& commands);
bool exists(const set<string>& commands, const string& com);
void check_com(const set<string>& commands, const string& searching_for);
void printName(void);
void clrBoard(board brd, pawn& pw, pawn& pb);
void getTokens(const string& initial_comm, string& w1, string& w2, string& w3, string& w4);
void setBoard(string& sizeS, board& bd);
void setWalls(board& bd, string& nof);
void checkWinner(pawn& p1, pawn& p2, int dim);
void translateMove(string& mv);

void playMove(string& who, board& bd, string& mv, pawn& wt, pawn& bk);
