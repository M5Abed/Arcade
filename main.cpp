#include "Game.h"
using namespace std;

int main() {
    int ans;
    do {
        cout<<"--------------------------------------------------\n";
        cout<<"             \"Welcome to ARCADE\"             \n";
        cout<<"--------------------------------------------------\n";
        cout<<"\nChoose your game\n";
        cout<<"--------------------------------------------------\n";
        cout<<"     1. \"Gussing Game\"             \n";
        cout<<"     2. \"Rock,Paper, Scissors\"             \n";
        cout<<"     3. \"Tic Tac Toe\"             \n";
        cout<<"     4. \"Connect Four\"             \n";
        cout<<"     5. \"Hang Man\"             \n";
        cout<<"--------------------------------------------------\n";
        cout<<"Note: You can back to this menu by type \"exit\" \n"; //MAKE SURE TO ADD THIS IN ALL GAMES
        cin>>ans;
    }while (ans<1||ans>5);
    switch (ans) {
        case 1: {
            system("cls");
            Gussing gussing;
            gussing.play();
        }
        case 2: {
            system("cls");
            RockPaperScissors RPS;
            RPS.play();
        }
        case 3: {
            system("cls");
            TicTacToe XO;
            XO.play();
        }
        case 4: {
            system("cls");
            Connect4 c4;
            c4.play();
        }
        case 5: {
            system("cls");
            Hangman hangman;
            hangman.play();
        }
        default:
            cout<<"Error";
    }
    return 0;
}