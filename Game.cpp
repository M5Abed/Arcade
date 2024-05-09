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
void Game::Getdata() {
    cout<<"The name of the the game: "<<Name<<endl;
    sleep_for(1s);
    cout<<"This game is developed by: "<<Develper<<endl;
    sleep_for(1s);
    cout<<"How to play this game: "<<HTP<<endl;

}
int main(); //main declaration to cam make it as return in classes below

//Rock paper scissors
RockPaperScissors::RockPaperScissors() {
    RockPaperScissors::SetName("Rock Paper Scissors");
    RockPaperScissors::Develper="Mohamed Abed";
    RockPaperScissors::HTP="\n\t\t\t\"You will play this game vs PC \n     You will chose ROCK,PAPER OR SCISSORS and the PC will chose one also and will see who wil gain more points\" \n";
    RockPaperScissors::Getdata();
    sleep_for(3s);
}
int RockPaperScissors::play() {
    bool draw=false;
    int pc=0;
    string input,output;
    cout<<"----------------------------------------\n";
    cout<<"\"Welcome to ROCK, PAPER, SCISSORS game\"\n";
    cout<<"----------------------------------------\n";
    sleep_for(1s);
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
            system("clear");
        }
        if ((input[0]=='r'&&res==1)||(input[0]=='p'&&res==2)||(input[0]=='s'&&res==3)) {
            draw=true;
            cout<<"The PC chose the same :D, We gonna play again\n";
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
            cout<<"\t\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
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
            cout<<"\t\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
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
            cout<<"\t\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
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
            cout<<"\t\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
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
            cout<<"\t\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
    }while (draw||input[0]!='e');
    return main();
}

//Gussing game
Gussing::Gussing() {
    Gussing::Name="Gussing Game";
    Gussing::Develper="Mohamed Abed";
    Gussing::HTP="\n\t\"You will enter a number(x) to guess random number between 0 and (x) \n      then you will have 3 attempts to guss the random number that computer chose\" \n";
    Gussing::Getdata();
    sleep_for(3s);
}
int Gussing::play(){
    int gussed;
    string input ;
    cout<<"----------------------------------------\n";
    cout<<"     \"Welcome to gussing game\"             \n";
    cout<<"----------------------------------------\n";
    cout<<"You want to play in range from 0 to ... ?\n";
    cin>>high;
    do {
        cout<<"Are You sure you want to guess number between 0 and "<<high<<"? (y/n)\n";
        cin>>input;
        if (input[0]<97) {
            for (int i=0;i<input.size();i++)
                input[i]+=32;
        }
    }while (input[0]!='y'&&input[0]!='e'&&input[0]!='n');
    if (input[0]=='y') {
        cout<< "wait a second ...\n"<<flush;
        sleep_for(1.5s);
    }
    else if (input[0]=='e'||input[0]=='n'){
        system("pause");
        return main();
    }

    srand(time(nullptr));
    int temp = rand(),temp2=0;
    value = temp % (high - low + 1) + low;
    cout<<"Now we are ready :)\n"<<flush;
    sleep_for(0.5s);
    system("cls");
    cout<<"\bGuess the number between 0 and "<< high<<": \n";
    cin>>gussed;
    if (gussed==value)
        cout<<"WOW YOU ARE RIGHT !!";
    else {
        do {
            if (gussed==value) {
                cout<<"WOWW YOU ARE RIGHT !! \n";
                break;
            }
            else if ((gussed-value)>5) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"It's much lower than this !\n";
                cin>>gussed;
            }
            else if ((gussed-value)<=5&&(gussed-value)>0) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"You are not much away :D (It's lower than this ;) ) ! \n";
                cin>>gussed;
            }
            else if ((gussed-value)<0&&(gussed-value)>=-5) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"You are not much away :D (It's higher than this ;) ) ! \n";
                cin>>gussed;
            }
            else if ((gussed-value)<0&&(gussed-value)<-5) {
                cout<<"Wrong guess but you still have "<<3-temp2<<" attempts\n";
                cout<<"You are not much away :D (It's much higher than this ;) ) ! \n";
                cout<<"It's much higher than this !\n";
                cin>>gussed;

            }
            temp2++;
        }while (temp2<3);
    }
    if (gussed==value) {
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
    Connect4::Name="Connect 4";
    Connect4::Develper="Khaled Youssef";
    Connect4::HTP="\n\t\t\"Connect Four is a classic two-player game where the goal is to get four of your X,or,O checkers in a row\n     either horizontally, vertically, or diagonally note in this game player 1 is X , player 2 is O\" \n";
    Connect4::Getdata();
    player = 1;
    rowIndex = 5;
    gameEnd = false;
    // Initialize the board with zeros
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = 0;
        }
    }
    sleep_for(1.5s);
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
    TicTacToe::Name="Tic Tac Toe";
    TicTacToe::Develper="Mariam Mohamed";
    TicTacToe::HTP="\n\t\t\t\t\"Classic TicTacToe or as known as (X,O), You need to make your character (X or O) be in the same line\n\t\t\t\t\t\t\teither this line is horizontally, vertically, or diagonally\" \n";
    TicTacToe::Getdata();
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
    Hangman::Name="HangMan";
    Hangman::Develper="Salma Hany";
    Hangman::HTP="\n\t\t\t\t\"Yu have 5 attempts to guess the right word character by character\" \n";
    Hangman::Getdata();
    sleep_for(3s);
    srand(time(0));  //each time the program runs a different sequence of random numbers will be generated
    word = words[rand()%5];  //rand() selects a random word "%5" makes sure the result is within the range of indices of array
    guessedWord = string(word.length(),'_');
    maxAttempts = 7;
    remainingAttempts = maxAttempts;
    //numGuessLetters=0;
}
bool Hangman::isAlreadyGuessed(char letter){
    for(int i=0;i<numGuessdLetters;i++)
    {
        if(guessedLetters[i]==letter){return true;}  //indicates the letter has been already guessed
    }
    return false;
}
int Hangman::play()
{
    char letter;
    cout<<"Guess the word: ";
    while(remainingAttempts>0&&guessedWord != word)
    {
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
        if(guessedWord==word)
        {
            cout<<"Congratulations1! You guessed the word: "<<word<<endl;
        }
        else
        {
            cout<<"Sorry, you ran out of attempts :(\nThe word was: "<<word<<endl;
        }
    }
    sleep_for(3s);
    system("cls");
    return main();
}

//memory game