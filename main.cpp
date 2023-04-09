#include <iostream>
#include <string>
#include <set>
#include <deque> //
#include "header.h"

using namespace std;

int main(void) {
    string comm;
    string word1, word2, word3, word4;
    string def_dim = "7", def_walls = "10";
    set<string> commands;
    deque<string> history; //

    setCommands(commands);
    board brd;
    pawn White(-1, -1, W);
    pawn Black(-1, -1, B);
    do {
        getline(cin, comm);
        getTokens(comm, word1, word2, word3, word4);

        if (!exists(commands, word1)) continue;
        if (word1 == "name") printName();
        if (word1 == "list_commands") printCommands(commands);
        if (word1 == "known_command") check_com(commands, word2);
        if (word1 == "boardsize") setBoard(word2, brd);
        if (word1 == "showboard") {cout << "=\n\n"; brd.printTable();}
        if (word1 == "clear_board") clrBoard(brd, White, Black);
        if (word1 == "walls") setWalls(brd, word2);
        if (word1 == "winner") checkWinner(White, Black, brd.getDim());
        if (word1 == "setup") {setBoard(def_dim, brd); clrBoard(brd, White, Black); setWalls(brd, def_walls); brd.printTable(); cout << "=\n\n";}
        if (word1 == "show_history") showHis(history);
        if (word1 == "playmove") {playMove(word2, brd, word3, White, Black); cout << "=\n\n"; brd.printTable();}
        if (word1 == "playwall") playWall(word2, word3, word4, brd);
        if (word1 == "genmove") continue;
        if (word1 == "undo") continue;
        if (exists(commands, word1)) history.push_front(comm);
    } while (comm != "quit");

    brd.delTable();
    cout << "=\n\n";
    return 0;
}
