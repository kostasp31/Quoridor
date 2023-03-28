#include <set>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "header.h"

using namespace std;

void setCommands(set<string>& st) {
    st.insert("name");
    st.insert("known_command");
    st.insert("list_commands");
    st.insert("setup");
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
    pw.setCoords(0, D/2);
    pb.setCoords(D-1, D/2);
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

void checkWinner(pawn& p1, pawn& p2, int dim) {
    if (p1.x == dim-1)
        cout << "= true White\n\n";
    else if (p2.x == 0)
        cout << "= true Black\n\n";   
    else    
        cout << "= false\n\n";    
}

void translateMove(string& mv, int& X, int& Y) {
    string x,y;
    x = mv.substr(0,1);
    y = mv.substr(1,2);

	char arr[mv.length() + 1]; 
	strcpy(arr, mv.c_str());
    char chX = arr[0];
    char chY = arr[1];
    int xi, yi;
    if (chX >= 65 && chX <= 90)
        xi = chX - 65;
    else    
        xi = chX - 97;
    yi = chY - 49;
    X = xi;
    Y = yi;
}

void playMove(string& who, board& bd, string& mv, pawn& wt, pawn& bk) {
    int x, y;
    translateMove(mv, x, y);
    if (bd.getChar(x,y) != ' ') {
        cout << "? illegal move; pawn already there\n\n";
        return;
    }
    if (x<0 || x>bd.getDim() || y<0 || y>bd.getDim()) {
        cout << "? illegal move\n\n";
        return;
    }
    if (who == "white" || who == "White" || who == "WHITE") {
        bd.setChar(wt.x, wt.y, ' ');
        //
        //cout << "x is: " << wt.x << " and y: " << wt.y;
        //
        wt.setCoords(x, y);
        bd.setChar(wt.x, wt.y, 'W');
        cout << "=\n\n";
        //
        //cout << "x became: " << wt.x << " and y: " << wt.y;
        //
    }
    else if (who == "black" || who == "Black" || who == "BLACK") {
        bd.setChar(bk.x, bk.y, ' ');
        bk.setCoords(x, y);
        bd.setChar(bk.x, bk.y, 'B');
        cout << "=\n\n";
    }
    else {
        cout << "? color not recognized\n\n";
    }
}