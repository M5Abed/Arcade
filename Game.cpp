#include "Game.h"
#include <utility>
//main class
void Game::SetName(string name) {
    this->Name = std::move(name);
}
void Game::SetDev(string dev) {
    this->Develper =std::move(dev);
}
void Game::SetHTP(string HTP) {
    this->HTP = std::move(HTP);
}
void Game::Welcome(const string& GameName) {
    system("cls");
    cout<<"----------------------------------------\n";
    cout<<"     \"Welcome to "<< GameName << "\"             \n";
    cout<<"----------------------------------------\n";
    sleep_for(1s);
}
void Game::GetData() {
    cout<<"The name of the the game: "<<Name<<endl;
    sleep_for(1s);
    cout<<"This game is developed by: "<<Develper<<endl;
    sleep_for(1s);
    cout<<"How to play this game: "<<HTP<<endl;
    system("pause");
}
int main(); //main declaration to cam make it as return in classes below

//Rock paper scissors
RockPaperScissors::RockPaperScissors() {
    RockPaperScissors::SetName("Rock Paper Scissors");
    RockPaperScissors::SetDev("Mohamed Abed");
    RockPaperScissors::SetHTP("\n\t\t\t\"You will play this game vs PC \n     You will choose ROCK,PAPER OR SCISSORS and the PC will chose one also and will see who wil gain more points\" \n");
    RockPaperScissors::GetData();
    sleep_for(3s);
}
int RockPaperScissors::play() {
    bool draw=false;
    int pc=0;
    string input,output;
    RockPaperScissors::Welcome(this->Name);
    do {
        srand(time(nullptr));
        Rand = rand();
        res = Rand % (3 - 1 + 1) + 1;
        cout<<"Rock,Paper or Scissors?\t(You can use shortcuts by first letter :D)\n";
        cin>>input;
        if (input[0]<97) {
            for (char & i : input)
                i+=32;
        }
        if (input[0]=='e') {
            system("cls");
        }
        if ((input[0]=='r'&&res==1)||(input[0]=='p'&&res==2)||(input[0]=='s'&&res==3)) {
            draw=true;
            sleep_for(0.5s);
            cout<<"The PC chose the same :D, We gonna play again\n";
            sleep_for(1.5s);
            system("cls");
        }
        else if ((input[0]=='r'&&res==2)) {
            cout<<"You: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"PC Win !!\n";
            pc++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='r'&&res==3)) {
            cout<<"You: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"You Win !!\n";
            Points++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='p'&&res==1)) {
            cout<<"You: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"You Win !!\n";
            Points++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='p'&&res==3)) {
            cout<<"You: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"PC Win !!\n";
            pc++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='s'&&res==1)) {
            cout<<"You: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"PC Win !!\n";
            pc++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='s'&&res==2)) {
            cout<<"You: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"You Win !!\n";
            Points++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
    }while (draw||input[0]!='e');
    return main();
}

//Guessing game
Guessing::Guessing() {
    Guessing::SetName("Guessing Game");
    Guessing::SetDev("Mohamed Abed");
    Guessing::SetHTP("\n\t\"You will enter a number(x) to guess random number between 0 and (x) \n      then you will have 3 attempts to guss the random number that computer chose\" \n");
    Guessing::GetData();
    sleep_for(1s);
} //game details
int Guessing::Guessed(int &x) {
    do {
        cout << "\bGuess the number between 0 and " << high << ": \n";
        cin >> x;
    } while (x<0 || x>high);
    return x;
} //To make sure that the input is valid value
int Guessing::play(){
    Guessing::Welcome(this->Name);
    int guessed;
    string input;
    cout<<"You want to play in range from 0 to ... ?\n";
    cin>>high;
        cout<<"Are You sure you want to guess number between 0 and "<<high<<"? (y/n)\n";
        cin>>input;
        if (input[0]<97) {
            for (int i=0;i<input.size();i++)
                input[i]+=32;
        }
    if (input[0]=='y') {
        cout<< "wait a second ...\n"<<flush;
        sleep_for(1.5s);
    }
    else {
        system("cls");
        return main();
    }

    srand(time(nullptr));
    int temp = rand(),temp2=0;
    value = temp % (high - low + 1) + low;
    cout<<"Now we are ready :)\n"<<flush;
    sleep_for(0.5s);
    system("cls");
    Guessed(guessed);
    if (guessed==value)
        cout<<"WOW YOU GUESSED IT RIGHT !!\n";
    else {
        do {
            if (guessed==value) {
                cout<<"WOW YOU GUESSED IT RIGHT !!\n";
                break;
            }
            else if ((guessed-value)>5) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"It's much lower than this !\n";
                cin>>guessed;
            }
            else if ((guessed-value)<=5&&(guessed-value)>0) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"You are not much away :D (It's lower than this ;) ) ! \n";
                cin>>guessed;
            }
            else if ((guessed-value)<0&&(guessed-value)>=-5) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"You are not much away :D (It's higher than this ;) ) ! \n";
                cin>>guessed;
            }
            else if ((guessed-value)<0&&(guessed-value)<-5) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"You are not much away :D (It's much higher than this ;) ) ! \n";
                cout<<"It's much higher than this !\n";
                cin>>guessed;

            }
            temp2++;
        }while (temp2<3);
    }
if (guessed==value) {
    cout<<"\nYou got it right and we was happy to play with you :D \n";
    cout<<"Thanks to play our game :D  \n";
}
else {
    cout<<"It seems like that's not your day :D \n";
    cout<<"The answer was: "<<value<<endl;
}
system("pause");
system("cls");
return main();
}
//Connect 4
Connect4::Connect4() {
    Connect4::SetName("Connect 4");
    Connect4::SetDev("Khaled Youssef");
    Connect4::SetHTP("\n\"Connect Four is a classic two-player game where the goal is to get four of your X,or,O checkers in a row\n   \teither horizontally, vertically, or diagonally NOTE THAT:"
                     " in this game player 1 is X , player 2 is O\" \n");
    Connect4::GetData();
    player = 1;
    rowIndex = 5;
    gameEnd = false;
    // Initialize the board with zeros
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = 0;
        }
    }
}
void Connect4::handleInput(int input) {
    if (rowIndex >= 0) {
        if (board[rowIndex][input] != 0) { // if the row is full
            rowIndex--;
            handleInput(input);
        } else {
            board[rowIndex][input] = player;
            rowIndex = 5;
        }
    } else {
        cout << "Wrong input please try again !\n";
        player = (player == 1) ? 2 : 1;
        rowIndex = 5;
    }
}
void Connect4::checkWinner() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++)
        {
            // check win with columns
            if (board[i][j]==player&&board[i][j-1]==player&&board[i][j-2]==player&&board[i][j-3]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }
                //check win with rows
            else if (board[i][j]==player&&board[i-1][j]==player&&board[i-2][j]==player&&board[i-3][j]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }
                //to check scissors to left side
            else if (board[i][j]==player&&board[i-1][j-1]==player&&board[i-2][j-2]==player&&board[i-3][j-3]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }
                //to check scissors to right side
            else if (board[i][j]==player&&board[i-1][j+1]==player&&board[i-2][j+2]==player&&board[i-3][j+3]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }

        }
    }
}
void Connect4::draw() {
    system("cls");
    // to initialize the columns with its numbers
    for (int j = 0; j < 7; j++) {
        cout << "-" << j + 1 << "--";
    }
    //to make numbers horizontal
    cout << endl;
    //to initialize the shape and declare player 1x,2o
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 0) {
                cout << "|  |";
            } else if (board[i][j] == 1) {
                cout << "|x |";
            } else if (board[i][j] == 2) {
                cout << "|o |";
            }
        }
        cout << endl;
    }
    for (int j = 0; j < 7; j++) {
        cout << "====";
    }
    cout << endl;
}
int Connect4::play() {
    Connect4::Welcome(this->Name);
    sleep_for(2s);
    draw();
    while (!gameEnd) {
        cout << "Player " << player << ": ";
        int input;
        cin >> input;
        handleInput(input - 1);
        draw();
        checkWinner();
        player = (player == 1) ? 2 : 1;
    }
    system("pause");
    system("cls");
    return main();
}

//TIc Tac Toe
TicTacToe::TicTacToe() {
    TicTacToe::SetName("Tic Tac Toe");
    TicTacToe::SetDev("Mariam Mohamed");
    TicTacToe::SetHTP("\n\t\"Classic TicTacToe or as known as (X,O), You need to make your character (X or O) be in the same line\n\t\teither this line is horizontally, vertically, or diagonally\" \n");
    TicTacToe::GetData();
    sleep_for(3s);
}
char TicTacToe::whoWin() {
    int xc, oc;
    for (int x = 0; x < 3; x++) {
        xc = oc = 0;
        for (int y = 0; y < 3; y++) {
            if (matrix[x][y] == 'x')
                xc++;
            else if (matrix[x][y] == 'o')
                oc++;
        }
        if (xc == 3 || oc == 3)
            return xc > oc ? 'x' : 'o';
    }

    for (int y = 0; y < 3; y++) {
        xc = oc = 0;
        for (int x = 0; x < 3; x++) {
            if (matrix[x][y] == 'x')
                xc++;
            else if (matrix[x][y] == 'o')
                oc++;
        }
        if (xc == 3 || oc == 3)
            return xc > oc ? 'x' : 'o';
    }


    if ((matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x') ||
        (matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x'))
        return 'x';
    else if ((matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o') ||
             (matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o'))
        return 'o';


    int counter = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (matrix[x][y] != 'x' && matrix[x][y] != 'o')
                counter++;
        }
    }
    if (counter == 0)
        return 'z';

    return '.';
}
void TicTacToe::printMatrix() {
    system("cls");
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cout << matrix[x][y] << '\t';
        }
        cout << endl;
    }
}
int TicTacToe::play() {
    TicTacToe::Welcome(this->Name);
    sleep_for(2s);
    while (whoWin() == '.') {
        printMatrix();
        char pos;
        cout << "Choose your position - Player (" << player << ") :";
        cin >> pos;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (matrix[x][y] == pos) {
                    matrix[x][y] = player;
                    if (player == 'x')
                        player = 'o';
                    else
                        player = 'x';
                }
            }
        }
        cout << "Invalid move! Please choose a valid position." << endl;
    }
    printMatrix();
    char winner = whoWin();
    if (winner == 'z')
        cout << "\nNo winner!!\n\n" << endl;
    else
        cout << "\nThe Winner is Player (" << winner << "), congratulations!!\n\n";
    sleep_for(3s);
    system("cls");
    return main();
}

//HangMan
Hangman::Hangman(){
    Hangman::SetName("HangMan Game");
    Hangman::SetDev("Salma Hany");
    Hangman::SetHTP("\n\t\t\"You have 5 attempts to guess the right word character by character\" \n");
    Hangman::GetData();
    srand(time(0));  //each time the program runs a different sequence of random numbers will be generated
    word = words[rand()%5];  //rand() selects a random word "%5" makes sure the result is within the range of indices of array
    guessedWord = string(word.length(),'_');
    maxAttempts = 5;
    remainingAttempts = maxAttempts;
    //numGuessLetters=0;
}
bool Hangman::isAlreadyGuessed (char letter)
{
    for(int i=0;i<numGuessdLetters;i++)
    {
        if(guessedLetters[i]==letter){return true;}  //indicates the letter has been already guessed
    }
    return false;
}
int Hangman::play(){
    Hangman::Welcome(this->Name);
    char letter;
    while(remainingAttempts > 0 && guessedWord != word)
    {
        cout<<"Guess the word: ";
        cout<<guessedWord<<endl;
        cout<<"Enter a letter: ";
        cin>>letter;
        if(!((letter>='A' && letter<='Z') || (letter>='a' && letter<='z')))
        {
            cout<<"Please enter a valid letter."<<endl;
            continue;
        }
        if(letter >= 'A' && letter <= 'Z')
        {
            letter=tolower(letter);  //convert to lowercase if it's uppercase
        }
        if(isAlreadyGuessed(letter))
        {
            cout<<"You've already guessed that letter."<<endl;
            continue;
        }
        guessedLetters[numGuessdLetters++]=letter;
        bool found = false;
        for(int i=0; i<word.length();++i)
        {
            if(word[i]==letter)
            {
                guessedWord[i]=letter;
                found=true;
            }
        }

        if(!found)
        {
            cout<<"Incorrect guess!"<<endl;
            remainingAttempts--;
            cout<<"Remaining attempts: "<<remainingAttempts<<endl;
        }
    }

    if(guessedWord==word)
    {
        cout<<"Congratulations! You guessed the word: "<<word<<endl;
    }
    else
    {
        cout<<"Sorry, you ran out of attempts :(\nThe word was: "<<word<<endl;
    }
    system("pause");
    system("cls");
    return main();
}

//memory game
MemoryGame::MemoryGame(int rows, int cols): numRows(rows), numCols(cols), pairsFound(0), movesLeft(rows * cols / 2) {

    MemoryGame::SetName("Memory game");
    MemoryGame::SetDev("Menna");
    MemoryGame::SetHTP("\n\t \""
                       "You will see 16 card for 5 seconds \n\tand you will need to remember it's positions\" \n");
    MemoryGame::GetData();

    vector<char> symbols = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int numPairs = (numRows * numCols) / 2;
    srand(static_cast<unsigned int>(time(0)));

    // Select random symbols and pair them
    vector<char> chosenSymbols;
    for (int i = 0; i < numPairs; ++i) {
        chosenSymbols.push_back(symbols[i]);
        chosenSymbols.push_back(symbols[i]); // Pair each symbol
    }

    // Shuffle the chosen symbols to randomize their positions
    random_shuffle(chosenSymbols.begin(), chosenSymbols.end());

    // Populate the game board with cards having randomized symbols
    for (int i = 0; i < numRows; ++i) {
        vector<Card> row;
        for (int j = 0; j < numCols; ++j) {
            char symbol = chosenSymbols[i * numCols + j];
            row.push_back(Card(symbol));
        }
        board.push_back(row);
    }
}
void MemoryGame::displayBoard() const {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << board[i][j].getSymbol() << ' ';
        }
        cout << endl;
    }
}
void MemoryGame::playBoard() const {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << board[i][j].getActualSymbol() << ' ';
        }
        cout << endl;
    }
}
bool MemoryGame::flipCard(int row, int col) {
    if (!board[row][col].isRevealed()) {
        board[row][col].reveal();
        return true;
    }
    return false;
}
bool MemoryGame::isGameOver() const {
    return pairsFound == (numRows * numCols) / 2 || movesLeft == 0;
}
bool MemoryGame::checkMatch(int row1, int col1, int row2, int col2) const {
    return board[row1][col1].getSymbol() == board[row2][col2].getSymbol();
}
int MemoryGame::play() {
    MemoryGame::Welcome(this->Name);
    system("cls");
    this->playBoard();
    cout << "All cards revealed. Get ready!" << endl;
    sleep_for(4s);
    system("cls");
    while (!this->isGameOver()) {
        this->displayBoard();
        int row1, col1, row2, col2;
        cout << "Enter row and column of first card to flip (1-4): ";
        cin >> row1 >> col1;
        cout << "Enter row and column of second card to flip (1-4): ";
        cin >> row2 >> col2;

        // Adjust input indices to 0-based for internal use
        row1--; col1--; row2--; col2--;

        if (row1 < 0 || row1 >= this->getNumRows() || col1 < 0 || col1 >= this->getNumCols() ||
            row2 < 0 || row2 >= this->getNumRows() || col2 < 0 || col2 >= this->getNumCols()) {
            cout << "Invalid input. Please enter valid row and column numbers (1-" << this->getNumRows() << ")." << endl;
            continue;
        }
        bool flipped1 = this->flipCard(row1, col1);
        bool flipped2 = this->flipCard(row2, col2);
        if (flipped1 && flipped2) {
            if (this->checkMatch(row1, col1, row2, col2)) {
                system("cls");
                cout << "Match found!" << endl;
                this->incrementPairsFound();
            } else {
                system("cls");
                cout << "No match. Try again." << endl;
                this->flipCard(row1, col1); // Flip back if no match
                this->flipCard(row2, col2); // Flip back if no match
            }
            this->decrementMovesLeft();
        } else {
            cout << "Invalid move. One or both cards are already revealed." << endl;
        }
        cout << endl;
    }
    if (this->isGameOver() && this->getPairsFound() == (this->getNumRows() * this->getNumCols()) / 2) {
        cout << "Congratulations! You found all pairs." << endl;
    } else {
        cout << "Sorry, you've used all your moves. Good luck next time!" << endl;
    }

    return main();
}