//Checker
//Nickalus Lowrey
//Version 0.1.1

#include <iostream>

int main() {
    // Create an 8x8 board
    char board[8][8];

    // Initialize the board with spaces
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = ' ';
        }
    }

    // Place X pieces (top of board)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 1) {
                board[i][j] = 'X';
            }
        }
    }

    // Place O pieces (bottom of board)
    for(int i = 5; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 1) {
                board[i][j] = 'O';
            }
        }
    }

    // Print the board
    std::cout << "  0 1 2 3 4 5 6 7" << std::endl;
    for(int i = 0; i < 8; i++) {
        std::cout << i << " ";
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                std::cout << "_";
            } else {
                std::cout << board[i][j];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}