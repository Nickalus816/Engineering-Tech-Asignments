//Checkers
//Nickalus Lowrey
//Version 1.6.1

//Should mostly work. I can't figure out AI and I dont feel like asking ChatGPT or Magic school so hope this works.

#include <iostream>

int absolute(int value) {
    return (value < 0) ? -value : value;
}

struct Move {
    int fromRow, fromCol;
    int toRow, toCol;
};

// Function to check if a piece should become a king
bool shouldBecomeKing(char piece, int row) {
    return (piece == 'X' && row == 7) || (piece == 'O' && row == 0);
}

// Function to check if a piece is a king
bool isKing(char piece) {
    return piece == 'K' || piece == 'Q';  // K for X's kings, Q for O's kings
}

bool isValidMove(const char board[8][8], Move move, char currentPlayer) {
    // Check bounds
    if (move.fromRow < 0 || move.fromRow > 7 || move.fromCol < 0 || move.fromCol > 7 ||
        move.toRow < 0 || move.toRow > 7 || move.toCol < 0 || move.toCol > 7) {
        return false;
    }

    char piece = board[move.fromRow][move.fromCol];
    bool isCurrentPieceKing = isKing(piece);

    // Check if starting position has the player's piece
    if (currentPlayer == 'X' && piece != 'X' && piece != 'K') return false;
    if (currentPlayer == 'O' && piece != 'O' && piece != 'Q') return false;

    // Check if destination is empty
    if (board[move.toRow][move.toCol] != ' ') return false;

    int rowDiff = move.toRow - move.fromRow;
    int colDiff = move.toCol - move.fromCol;

    // Normal move - one square diagonally
    if (absolute(rowDiff) == 1 && absolute(colDiff) == 1) {
        if (!isCurrentPieceKing) {
            return (currentPlayer == 'X' && rowDiff > 0) || 
                   (currentPlayer == 'O' && rowDiff < 0);
        }
        return true; // Kings can move in any direction
    }

    // Jump move - two squares diagonally
    if (absolute(rowDiff) == 2 && absolute(colDiff) == 2) {
        int jumpedRow = (move.fromRow + move.toRow) / 2;
        int jumpedCol = (move.fromCol + move.toCol) / 2;
        char jumpedPiece = board[jumpedRow][jumpedCol];

        // Check if jumping over opponent's piece
        if (currentPlayer == 'X' && (jumpedPiece == 'O' || jumpedPiece == 'Q')) {
            return isCurrentPieceKing ? true : rowDiff > 0;
        }
        if (currentPlayer == 'O' && (jumpedPiece == 'X' || jumpedPiece == 'K')) {
            return isCurrentPieceKing ? true : rowDiff < 0;
        }
    }

    return false;
}

void printBoard(const char board[8][8]) {
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
}

bool makeMove(char board[8][8], Move move) {
    char piece = board[move.fromRow][move.fromCol];
    board[move.fromRow][move.fromCol] = ' ';

    // Handle jumping
    if (absolute(move.toRow - move.fromRow) == 2) {
        int jumpedRow = (move.fromRow + move.toRow) / 2;
        int jumpedCol = (move.fromCol + move.toCol) / 2;
        board[jumpedRow][jumpedCol] = ' ';  // Remove jumped piece
    }

    // Check if piece should become king
    if (shouldBecomeKing(piece, move.toRow)) {
        piece = (piece == 'X') ? 'K' : 'Q';
    }

    board[move.toRow][move.toCol] = piece;
    return true;
}

bool checkWin(const char board[8][8]) {
    bool hasX = false;
    bool hasO = false;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'X' || board[i][j] == 'K') hasX = true;
            if(board[i][j] == 'O' || board[i][j] == 'Q') hasO = true;
        }
    }

    return !hasX || !hasO;
}

int main() {
    char board[8][8];
    char playerChoice;
    char currentPlayer;

    // Ask player to choose X or O
    do {
        std::cout << "Choose your piece (X/O): ";
        std::cin >> playerChoice;
        playerChoice = toupper(playerChoice);  // Convert to uppercase

        if (playerChoice != 'X' && playerChoice != 'O') {
            std::cout << "Invalid choice! Please choose X or O." << std::endl;
        }
    } while (playerChoice != 'X' && playerChoice != 'O');

    // Set starting player based on piece selection
    currentPlayer = 'X';  // X always goes first in checkers

    std::cout << "Player 1 is " << playerChoice << std::endl;
    std::cout << "Player 2 is " << (playerChoice == 'X' ? 'O' : 'X') << std::endl;
    std::cout << "X always moves first!" << std::endl;

    // Initialize board
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = ' ';
        }
    }

    // Place X pieces
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 1) {
                board[i][j] = 'X';
            }
        }
    }

    // Place O pieces
    for(int i = 5; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 1) {
                board[i][j] = 'O';
            }
        }
    }

    // Game loop
    while(true) {
        printBoard(board);

        if (checkWin(board)) {
            std::cout << "Game Over! Player " 
                      << (currentPlayer == 'X' ? 'O' : 'X') 
                      << " wins!" << std::endl;
            break;
        }

        std::cout << "Player " << currentPlayer;
        if (currentPlayer == playerChoice) {
            std::cout << " (Player 1)";
        } else {
            std::cout << " (Player 2)";
        }
        std::cout << "'s turn." << std::endl;

        std::cout << "Enter move (fromCol fromRow toCol toRow): ";

        Move playerMove;
        std::cin >> playerMove.fromRow >> playerMove.fromCol 
                 >> playerMove.toRow >> playerMove.toCol;

        if (isValidMove(board, playerMove, currentPlayer)) {
            makeMove(board, playerMove);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
        }

        std::cout << "Enter 'q' to quit or any other key to continue: ";
        char choice;
        std::cin >> choice;
        if (choice == 'q' || choice == 'Q') break;
    }

    return 0;
}