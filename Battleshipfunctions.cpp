#include "Battleship.hpp"
#include <iostream>
#include <map>
using namespace std;

map<char, int> spaces = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, 
    {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}};


Ship shipsList[4] = {{"Battleship", 4, 0, 0, false, rand() % 2}, {"Cruise", 3, 0, 0, false, rand() % 2}, 
    {"Destroyer", 2, 0, 0, false, rand() % 2}, {"Boat", 1, 0, 0, false, rand() % 2}};

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
    string ships[4] = {"Battleship", "Cruise", "Destroyer", "Boat"};
    int lengths[4] = {4,3,2,1};
    string space, endSpace;
    int row, col, endr, endc;
    bool valid, taken = false;

    for(int i = 0; i < 4; i++){
        do{
            cout << "Enter a coordinate for your " << ships[i] << " Ex: B5\n";
            cin >> space;

            if(space.length() != 2){
                cout << "\nInput must be a letter and a number\n";
                continue;
            }

            row = spaces[toupper(space[0])];
            col = space[1]-'1';

            if(col < 0 || col > 9 || row < 0 || row > 9){
                cout << "\nInvalid space\n";
                continue;
            }

            if(board[row][col] == 1){
                cout << "space taken";
                continue;
            }

            if(i == 3){
                board[row][col] = '1';
                break;
            }

            cout << "Choose end coordinate: ";
            cin >> endSpace;

            endr = spaces[toupper(endSpace[0])];
            endc = endSpace[1]-'1';

            if(board[endr][endc] == 1){
                cout << "space taken";
                continue;
            }

            for(int j = 0; j < lengths[i]; j++){
                if(board[row][col+j] == '1'){
                    cout << "space taken";
                    taken = true;
                }
                if(board[row+j][col] == '1'){
                    cout << "space taken";
                    taken = true;
                }
            }

            if(taken == false){
                for(int j = 0; j < lengths[i]; j++){
                    if(row == endr){
                        board[row][col+j] = '1';
                    }
                    if(col == endc){
                        board[row+j][col] = '1';
                    }
                }
                valid = true;
            }
        }while(!valid);
    }

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
                //I think this needs to be removed?
                cout << compBoard[i][j];
            }
            
        }
        cout << endl;
    }
}

void drawBoard(char compBoard[10][10]){
    char letter = 'A';
    cout << "  1 2 3 4 5 6 7 8 9 10\n";
    for(int i = 0; i < 10; i++){
        cout << static_cast<char>(letter + i);
        for(int j = 0; j < 10; j++){
            cout << ' ';
            if(compBoard[i][j] == '1'){
                cout << '1';
            } else if(compBoard[i][j] == 'm'){
                cout << 'O';
            }else if(compBoard[i][j] == 'h'){
                cout << 'X';
            }else{
                cout << '~';
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
