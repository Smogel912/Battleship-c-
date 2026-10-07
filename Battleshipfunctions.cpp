#include "Battleship.hpp"
#include <iostream>
#include <map>
using namespace std;

map<char, int> spaces = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, 
    {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}};

void ranPopulate(char board[10][10]){
    srand(time(0));
    Ship ships[4] = {{"Battleship", 4, 0, 0, false, rand() % 2}, {"Cruise", 3, 0, 0, false, rand() % 2}, 
    {"Destroyer", 2, 0, 0, false, rand() % 2}, {"Boat", 1, 0, 0, false, rand() % 2}};
    for(int i = 0; i < 4; i++){

        //if what then what? How do we prevent the loop from skipping over everything?

        ships[i].x = rand()%11;
        ships[i].y = rand()%11;
    }

    //Something like this work it out. x will be random and y will be +3
    // Ship battle = {"Battleship", 4, hor, vert, false, rand() % 2};
    // Ship cruise = {"Cruise", 3, hor, vert, false, rand() % 2};
    // Ship destroy = {"Destroyer", 2, hor, vert, false, rand() % 2};
    // Ship boat = {"Boat", 1, hor, vert, false, rand() % 2};
}

void manPopulate(char board[10][10]){
    string space;
    int i = 0;
    bool endTaken = false;
    bool taken = false;
    string ships[4] = {"Battleship", "Cruise", "Destroyer", "Boat"};
    bool isTaken;
    for(int i = 0; i < 4; i++){
        //Error handling. Program accepts only one character
        //Need to add length to ships
        cout << "Place your " + ships[i];
        cout << "\nSpace: ";
        cin >> space;
        isTaken = board[spaces[toupper(space[0])]][space[1]] == '1';

        while(isTaken){
            cout << "Space taken, choose another\n";
            cout << "Place your " + ships[i];
            cout << "\nSpace: ";
            cin >> space;
            isTaken = board[spaces[toupper(space[0])]][space[1]] == '1';
        }

        board[spaces[toupper(space[0])]][space[1]] = '1';

        if(i == 3){
            break;
        }

        do{
        cout << "\nEnd of ship: ";
        cin >> space;
        isTaken = board[spaces[toupper(space[0])]][space[1]] == '1';

        while(isTaken){
            cout << "Space taken, choose another\n";
            cout << "\nEnd of ship: ";
            cin >> space;
            isTaken = board[spaces[toupper(space[0])]][space[1]] == '1';
        }

        board[spaces[toupper(space[0])]][space[1]] = '1';
        
        endTaken = true;
        }while(!endTaken);
        
    }while(!taken);
}

void drawOppBoard(char compBoard[10][10]){
    char letter = 'A';
    cout << "  1 2 3 4 5 6 7 8 9 10\n";
    for(int i = 0; i < 10; i++){
        cout << static_cast<char>(letter + i);
        for(int j = 0; j < 10; j++){
            cout << ' ';
            if(compBoard[i][j] == '1'){
                cout << '~';
            } else{
                cout << compBoard[i][j];
            }
            
        }
        cout << endl;
    }
}

void fire(string space, char gameboard[10][10]){
    char r = spaces[toupper(space[0])];
    int c = space[1];
    char sym = gameboard[spaces[toupper(space[0])]][space[1]];

    if(sym == '1'){
        gameboard[r][c] = 'h';
    } else {
        gameboard[r][c] = 'm';
    }
}

void compTurn(char gameboard[10][10]){
    srand(time(0));
    bool invalid = true;
    do{
        int hor = rand() % 11;

        //Might have to check if this == hor
        int vert = rand()%11;

        if(gameboard[vert][hor] == 'h' || gameboard[vert][hor] == 'm'){
            continue;
        }

        if(gameboard[vert][hor] == '1'){
            gameboard[vert][hor] = 'h';
        } else {
            gameboard[vert][hor] = 'm';
        }
        invalid = false;
    }while(invalid);
}

//It'll be like passing an int from main method
//Computer and player will have their own int
bool checkWin(int check){
    if(check == 0){
        return true;
    }
    return false;
}