/*
para compilar:
g++ jogo_da_velha.cpp -o jogo_da_velha 

para rodar:
./jogo_da_velha

*/

#include <iostream>
using namespace std;

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char currentPlayer = 'X';

void drawBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Movimento inválido! Tente novamente." << endl;
    } else {
        board[row][col] = currentPlayer;
        switchPlayer();
    }
}

int main() {
    int row, col;
    bool gameover = false;

    cout << "Bem-vindo ao Jogo da Velha!" << endl;

    while (!gameover) {
        drawBoard();

        cout << "Jogador " << currentPlayer << ", é a sua vez." << endl;
        cout << "Informe a linha (0-2): ";
        cin >> row;
        cout << "Informe a coluna (0-2): ";
        cin >> col;

        playMove(row, col);

        if (checkWin()) {
            drawBoard();
            cout << "Parabéns! Jogador " << currentPlayer << " venceu!" << endl;
            gameover = true;
        } else if (isBoardFull()) {
            drawBoard();
            cout << "O jogo terminou em empate!" << endl;
            gameover = true;
        }
    }

    return 0;
}
