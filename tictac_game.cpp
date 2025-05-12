#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;
    bool gameOver;
    char winner;

public:
    TicTacToe() : board(9, ' '), currentPlayer('X'), gameOver(false), winner(' ') {}

    void printBoard() {
        system("cls"); 
        cout << "\nTic-Tac-Toe\n";
        cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i * 3 + j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool makeMove(int position) {
        if (position < 0 || position >= 9 || board[position] != ' ') {
            return false;
        }

        board[position] = currentPlayer;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin() {
       
        for (int i = 0; i < 3; i++) {
            if (board[i * 3] != ' ' && 
                board[i * 3] == board[i * 3 + 1] && 
                board[i * 3] == board[i * 3 + 2]) {
                winner = board[i * 3];
                return true;
            }
        }

        
        for (int i = 0; i < 3; i++) {
            if (board[i] != ' ' && 
                board[i] == board[i + 3] && 
                board[i] == board[i + 6]) {
                winner = board[i];
                return true;
            }
        }

       
        if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
            winner = board[0];
            return true;
        }
        if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
            winner = board[2];
            return true;
        }

        return false;
    }

    bool checkDraw() {
        for (char cell : board) {
            if (cell == ' ') {
                return false;
            }
        }
        return true;
    }

    void playGame() {
        while (!gameOver) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";

            int position;
            cin >> position;
            position--; 

           
            while (cin.fail() || position < 0 || position >= 9 || board[position] != ' ') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid move. Try again (1-9): ";
                cin >> position;
                position--;
            }

            makeMove(position);

            if (checkWin()) {
                printBoard();
                cout << "Player " << winner << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}