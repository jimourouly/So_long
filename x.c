#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} t_map;

void floodFill(int **array, int x, int y, int nbrlines, int nbrcount, int *coinsCollected, int *foundExit) {
    // Check for out-of-bounds or invalid cells
    if (x < 0 || x >= nbrlines || y < 0 || y >= nbrcount || array[x][y] == 1 || array[x][y] == 5) {
        return;
    }

    // Check if it's a coin
    if (array[x][y] == 2) {
        (*coinsCollected)++;
    }

    // Check if it's the exit
    if (array[x][y] == 3) {
        *foundExit = 1;
    }

    // Mark the cell as visited
    array[x][y] = 5;

    // Recursive calls for adjacent cells
    floodFill(array, x + 1, y, nbrlines, nbrcount, coinsCollected, foundExit);
    floodFill(array, x - 1, y, nbrlines, nbrcount, coinsCollected, foundExit);
    floodFill(array, x, y + 1, nbrlines, nbrcount, coinsCollected, foundExit);
    floodFill(array, x, y - 1, nbrlines, nbrcount, coinsCollected, foundExit);
}

int isPathOk(int **array, t_map *player, t_map *exit, int nbrlines, int nbrcount, int nbrcoins) {
    int coinsCollected = 0;
    int foundExit = 0;

    // Create a copy of the array to preserve the original grid
    int **gridCopy = (int **)malloc(nbrlines * sizeof(int *));
    for (int i = 0; i < nbrlines; i++) {
        gridCopy[i] = (int *)malloc(nbrcount * sizeof(int));
        for (int j = 0; j < nbrcount; j++) {
            gridCopy[i][j] = array[i][j];
        }
    }

    // Start flood fill from the player's position
    floodFill(gridCopy, player->x, player->y, nbrlines, nbrcount, &coinsCollected, &foundExit);

    // Free the copied grid
    for (int i = 0; i < nbrlines; i++) {
        free(gridCopy[i]);
    }
    free(gridCopy);

    // Check if all coins are collected and the exit is found
    return (coinsCollected == nbrcoins && foundExit);
}

int main() {
    // Example usage
    int nbrlines = 5, nbrcount = 5, nbrcoins = 2;
    int grid[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 4, 0, 2, 1},
        {1, 0, 0, 0, 1},
        {1, 2, 0, 3, 1},
        {1, 1, 1, 1, 1}
    };

    t_map player = {1, 1};
    t_map exit = {3, 3};

    // Convert the grid to a dynamically allocated 2D array
    int **array = (int **)malloc(nbrlines * sizeof(int *));
    for (int i = 0; i < nbrlines; i++) {
        array[i] = (int *)malloc(nbrcount * sizeof(int));
        for (int j = 0; j < nbrcount; j++) {
            array[i][j] = grid[i][j];
        }
    }

    if (isPathOk(array, &player, &exit, nbrlines, nbrcount, nbrcoins)) {
        printf("A valid path exists!\n");
    } else {
        printf("No valid path exists!\n");
    }

    // Free the allocated array
    for (int i = 0; i < nbrlines; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
