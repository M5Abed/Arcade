#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <ctime>
#include <thread>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace this_thread;

//HTP -> How to play

class Game {
protected:
    string Name;
    string Develper;
    string HTP;
public:
    void SetName(string);
    void SetDev(string);
    void SetHTP(string);
    void Getdata();
};

class RockPaperScissors:public Game{
protected:
    int Points=0;
    int Rand=0;
    int res=0;
public:
    int play();
    RockPaperScissors();
};

class Gussing:public Game{
private:
    int high=0,low=0,value=0;
    string input;
public:
    int play();
    Gussing();
};

class Connect4: public Game {
private:
    int board[6][7];
    int player;
    int rowIndex;
    bool gameEnd;

public:
    Connect4();
    void handleInput(int input) ;

    void checkWinner() ;
    void draw() ;
    int play() ;

};

class TicTacToe:public Game{
private:
    char player = 'x';
    char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
public:
    TicTacToe();
    void printMatrix();
    char whoWin() ;
    int play() ;
};

class Hangman : public Game
{
private:
    string words[5]={"apple","banana","kiwi","orange","grape"};
    string word;  //word to guess
    string guessedWord; //guessed word with blanks
    int maxAttempts;
    int remainingAttempts;
    char guessedLetters [26];
    int numGuessdLetters;

public:
    Hangman();
    bool isAlreadyGuessed (char letter);
    int play() ;

};

class memory : public Game{
public:
    virtual void displayBoard() const = 0;

    virtual bool flipCard(int row, int col) = 0;

    virtual bool isGameOver() const = 0;

    virtual ~memory() {}
};
class Card {
private:
    char symbol;
    bool revealed;

public:

    Card(char sym) : symbol(sym), revealed(false) {}
    char getSymbol() const {
        return revealed ? symbol : '#';

    }

    char getActualSymbol() const {
        return symbol;

    }

    bool isRevealed() const {
        return revealed;

    }

    void reveal() {
        revealed = true;
    }

    void conceal() {
        revealed = false;
    }
};
class MemoryGame : public memory {
private:

    vector<vector<Card>> board;

    int numRows;

    int numCols;

    int pairsFound;

    int movesLeft;

public:
    MemoryGame();
    MemoryGame(int rows, int cols);
    void displayBoard() const override;
    bool flipCard(int row, int col) override;
    bool isGameOver() const override;
    bool checkMatch(int row1, int col1, int row2, int col2) const;
    int getPairsFound() const { return pairsFound; }
    int getNumRows() const { return numRows; }
    int getNumCols() const { return numCols; }
    void incrementPairsFound() { pairsFound++; }
    void decrementMovesLeft() { movesLeft--; }
    void playBoard() const;
    int play();

};
#endif //GAME_H