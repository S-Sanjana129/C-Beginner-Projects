#include <stdio.h>
#include <stdlib.h>

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char player = 'X', computer = 'O';

void drawBoard() {
    printf("\n  ❌ TIC-TAC-TOE ENGINE ⭕\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

void computerMove() {
    // Basic AI block logic: search for the first available open space
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                board[i][j] = computer;
                return;
            }
        }
    }
}

int main() {
    int choice, moves = 0;
    while (moves < 9) {
        drawBoard();
        printf("Enter your choice slot (1-9): ");
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("\n❌ Invalid choice slot! Try again.\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin()) {
            drawBoard();
            printf("🎉 Congratulations! You beat the matrix!\n");
            return 0;
        }

        if (moves < 9) {
            computerMove();
            moves++;
            if (checkWin()) {
                drawBoard();
                printf("🤖 The AI won! Better luck next time.\n");
                return 0;
            }
        }
    }
    drawBoard();
    printf("🤝 It's a clean draw match!\n");
    return 0;
}
