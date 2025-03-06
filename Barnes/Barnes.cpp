#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
using std::array;
using std::cout;
using std::string;
using std::getline;
using std::cin;
using std::ostringstream;

int takeUserInput(const array<string, 3> const& englishMoves) { 
    // Converts user input to lowercase, checks against array with possible moves, then either outputs a numeric equivalent on valid input, or prompts re-entry.
    string userMove;
    getline(cin, userMove);
    std::transform(userMove.begin(), userMove.end(), userMove.begin(),
        [](unsigned char c) {return std::tolower(c); });
    for (int i = 0; i < englishMoves.size(); i++) {
        if (userMove == englishMoves[i]) {
            return i;
        }
    }
    cout << "Invalid input, please try again.\n";
    return takeUserInput(englishMoves);
}
int generateMachineMove() {
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> aiMove{ 0, 2 };
    return aiMove(mt);
}
int getResult(int p1, int p2) { // Compares player moves to decide winner
    // By assigning english moves numerical values, we can more easily decide the winning move without using a nest of elifs

    if (p1 == p2) {
        return 1; // tie
    }
    else if (p1 == p2 - 1 || p1 == p2 + 2) {
        return 2;// player 2 win
    }
    else {
        return 3; // player 1 win
    }
}

/*
* @param gamemode -> if true, playing v computer, if false, playijng v person 
*/
void playRPS(bool gamemode, int& score) {
    // Prompts user to play game of rock paper scissors
    // Output from promptGamemode() decides whether to automatically generate player 2's moves (and award points on player 1 win), or allow the user to enter the second move
    array<string, 3> englishMoves = { "rock", "paper", "scissors" };
    cout << "Player 1: Rock, Paper, Scissors? ";
    int playerOneMove = takeUserInput(englishMoves);
    int playerTwoMove;
    system("CLS");
    if (gamemode) {
        playerTwoMove = generateMachineMove();
    }
    else {
        cout << "Player 2: Rock, Paper, Scissors? ";
        playerTwoMove = takeUserInput(englishMoves);
        system("CLS");
    }
    ostringstream printedOutput;
    printedOutput << "Player 1 chose " << englishMoves[playerOneMove] << ", player 2 chose " << englishMoves[playerTwoMove];
    
    
    switch (getResult(playerOneMove, playerTwoMove)) {
    case 1:
        printedOutput << "\n\nTie!\n";
        cout << printedOutput.str();
        break;
    case 2:
        printedOutput << "\n \nPlayer 2 wins!\n";
        cout << printedOutput.str();
        break;
    case 3:
        printedOutput << "\n \nPlayer 1 wins!\n";
        cout << printedOutput.str();
        if (gamemode) {
            cout << "+1 point! You have " << ++score << " points total.\n";
        }
        break;
    }

}
bool promptMenu(int& score) { // Allows user to select gamemode or exit program
    int selection;
    cout << "Rock Paper Scissors!\n\n1 - Play against machine\n2 - Play with a friend\n3 - Exit\n";
    cin >> selection;
    cin.ignore();
    switch (selection) {
    case 1: // Single player RPS
        playRPS(true, score);
        break;
    case 2: // Two player RPS
        playRPS(false, score);
        break;
    case 3: // Ends program
        return false;
    default: // Error handling, prompts re-input
        cout << "Invalid input, please try again.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return promptMenu(score);
    }
    return true;
}
int main() {//Allman style
    int score = 0;
    bool continuePlaying = true;
    while (continuePlaying) {
        continuePlaying = promptMenu(score);
    }
    return 0;
}