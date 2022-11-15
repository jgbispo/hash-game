// Hash Game
// Created by: João Gustavo Soares Bispo
// Date: 2022-11-15
// IDE: CLion
// Version: 1.0
// Repository: github.com/jgbispo/hash-game

#include <stdio.h>
#include  <stdlib.h>

void drawBoard(int[3][3]); // Function to draw the board
void playerOne(int[3][3]); // Function to play the player one
void playerTwo(int[3][3]); // Function to play the player two
int finishGame(int[3][3]); // Function to check if the game is finished

// Main function
int main() {

    // Variables
    int hashGame[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    }; // Hash game board

    int control = 0; // Control variable

    // Game loop
    while (control == 0) {
        drawBoard(hashGame);
        playerOne(hashGame);
        control = finishGame(hashGame);

        // If the game is finished, the loop is broken
        if (control == 1) {
            drawBoard(hashGame);
            break;
        }
        drawBoard(hashGame);
        playerTwo(hashGame);
        control = finishGame(hashGame);
    }

    printf("Game Over!"); // Game over message

    return 0;
}


void drawBoard(int hashGame[3][3]) {
    system("cls"); // Clear the screen

    // Draw the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (hashGame[i][j] == 0) { // If the position is empty
                printf(" # ");
            } else if (hashGame[i][j] == 1) { // If the position is 1, the player one is in this position
                printf(" X ");
            } else if (hashGame[i][j] == 2) { // If the position is 2, the player two is in this position
                printf(" O ");
            }
        }
        printf("\n");
    }
}

void playerOne(int hashGame[3][3]) {
    int x, y;
    printf("Player 1, enter the column [0-2] and line [0-2]:");
    scanf("%d %d", &x, &y);
    if (hashGame[x][y] == 0) {
        hashGame[x][y] = 1;
    } else {
        printf("Invalid coordinates, try again!\n");
        playerOne(hashGame);
    }
}

void playerTwo(int hashGame[3][3]) {
    int x, y;
    printf("Player 2, enter the column [0-2] and line [0-2]: ");
    scanf("%d %d", &x, &y);
    if (hashGame[x][y] == 0) {
        hashGame[x][y] = 2;
    } else {
        printf("Invalid coordinates, try again!\n");
        playerTwo(hashGame);
    }
}

int finishGame(int hashGame[3][3]) {
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (hashGame[i][j] != 0) { // If the position is not empty, the count variable is incremented
                count++; // Increment the count variable
            }
        }
    }

    // If the count variable is equal to 9, the game is finished
    if (count == 9) {
        return 1;
    }

    // Check if the game is finished with a winner

    // Check lines
    for (int i = 0; i < 3; i++) {
        if (hashGame[i][0] == hashGame[i][1] && hashGame[i][1] == hashGame[i][2]) {
            if (hashGame[i][0] == 1) {
                printf("Player 1 wins!\n");
                return 1;
            } else if (hashGame[i][0] == 2) {
                printf("Player 2 wins!\n");
                return 1;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (hashGame[0][i] == hashGame[1][i] && hashGame[1][i] == hashGame[2][i]) {
            if (hashGame[0][i] == 1) {
                printf("Player 1 wins!\n");
                return 1;
            } else if (hashGame[0][i] == 2) {
                printf("Player 2 wins!\n");
                return 1;
            }
        }
    }

    // Check diagonals
    if (hashGame[0][0] == hashGame[1][1] && hashGame[1][1] == hashGame[2][2]) {
        if (hashGame[0][0] == 1) {
            printf("Player 1 wins!\n");
            return 1;
        } else if (hashGame[0][0] == 2) {
            printf("Player 2 wins!\n");
            return 1;
        }
    }

    return 0;
}
