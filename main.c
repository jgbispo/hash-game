// Hash Game
// Created by: João Gustavo Soares Bispo
// Date: 2022-11-15
// IDE: CLion
// Version: 1.0
// Repository: github.com/jgbispo/hash-game

#include <stdio.h>


void drawHashGame(int hashGame[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (hashGame[i][j] == 0) {
                printf(" # ");
            } else if (hashGame[i][j] == 1) {
                printf(" X ");
            } else if (hashGame[i][j] == 2) {
                printf(" O ");
            }
        }
        printf("\n");
    }
}

void playerOne(int hashGame[3][3]) {
    int x, y;
    printf("Player 1, enter the coordinates: ");
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
    printf("Player 2, enter the coordinates: ");
    scanf("%d %d", &x, &y);
    if (hashGame[x][y] == 0) {
        hashGame[x][y] = 2;
    } else {
        printf("Invalid coordinates, try again!\n");
        playerTwo(hashGame);
    }
}

int main() {
    int hashGame[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    do{
        drawHashGame(hashGame);
        playerOne(hashGame);
        drawHashGame(hashGame);
        playerTwo(hashGame);
    } while (1);
}
