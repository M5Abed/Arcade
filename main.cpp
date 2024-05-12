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
        cout<<"     1. \"Guessing Game\"             \n";
        cout<<"     2. \"Rock,Paper, Scissors\"             \n";
        cout<<"     3. \"Tic Tac Toe\"             \n";
        cout<<"     4. \"Connect Four\"             \n";
        cout<<"     5. \"Hang Man\"             \n";
        cout<<"     6. \"Memory Game\"             \n";
        cout<<"--------------------------------------------------\n";
        cin>>ans;
    }while (ans<1||ans>6);
    switch (ans) {
        case 1: {
            system("cls");
            auto *guessing = new Guessing;
            guessing->play();
            delete guessing;
        }
        case 2: {
            system("cls");
            auto *RPS = new RockPaperScissors;
            RPS->play();
            delete RPS;
        }
        case 3: {
            system("cls");
            auto *XO =new TicTacToe;
            XO->play();
            delete XO;
        }
        case 4: {
            system("cls");
            auto *c4 = new Connect4;
            c4->play();
            delete c4;
        }
        case 5: {
            system("cls");
            auto *hangman = new Hangman ;
            hangman->play();
            delete hangman;
        }
        case 6: {
            system("cls");
            auto *game = new MemoryGame(4, 4);
            game->play();
            delete game;
        }
        default:
            cout<<"Error";
    }
    return 0;
}
