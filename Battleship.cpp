#include "Battleship.hpp"
#include "Battleshipfunctions.cpp"
#include <map>
#include <iostream>
using namespace std;

/*Need:
    choice to populate board manually or random
    Using a bot so random is necessary

    bot will fire random until it hits, then it
    will choose another direction at random
    Could use trees for decision tree

    Main menu: 1 to start then that goes to 
    1 or 2 for manual or random placement
*/

int main(){
    char gameboard[10][10];
    char compBoard[10][10];
    string space;
    int turn = 1, shipsAmt = 5, mode;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            gameboard[i][j] = '~';
            compBoard[i][j] = '~';
        }
    }

    cout << "**********************\n";
    cout << "******BATTLESHIP******\n";
    cout << "**********************\n";
    cout << "1: Manual\t2:Random\n";
    cin >> mode;

    do{
    if(mode == 1){
        manPopulate(gameboard);
        break;
    } else if(mode == 2){
        //ranPopulate(gameboard);
    } else {
        cout << "Pick 1 or 2";
    }
    } while(mode != 1 || mode != 2);

    //ranPopulate(compBoard);

    while(shipsAmt != 0){
        //drawOppBoard(compBoard);
        drawBoard(gameboard);
        cout << "\nChoose a space: ";
        cin >> space;

        //Here check if valid spot or if already fired on spot
        //fire(space);
    };
}
