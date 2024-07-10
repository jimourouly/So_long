#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 6

// Position structure
typedef struct {
    int x;
    int y;
} Position;

// Helper function to find positions of elements in the grid
void find_positions(char grid[ROWS][COLS], char element, Position positions[], int *count) {
    *count = 0;
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            if (grid[y][x] == element) {
                positions[*count].x = x;
                positions[*count].y = y;
                (*count)++;
            }
        }
    }
}

// Flood fill function to mark reachable cells
void flood_fill(char grid[ROWS][COLS], int x, int y, int visited[ROWS][COLS]) {
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) return;
    if (grid[y][x] == '1' || visited[y][x]) return;
    
    visited[y][x] = 1;
    
    flood_fill(grid, x + 1, y, visited);
    flood_fill(grid, x - 1, y, visited);
    flood_fill(grid, x, y + 1, visited);
    flood_fill(grid, x, y - 1, visited);
}

// Function to check if the path is valid
int is_path_valid(char grid[ROWS][COLS]) {
    Position player;
    Position coins[ROWS * COLS];
    Position exit;
    int coin_count, exit_count;
    
    find_positions(grid, 'P', &player, 1);
    find_positions(grid, 'C', coins, &coin_count);
    find_positions(grid, 'E', &exit, &exit_count);
    
    int visited[ROWS][COLS] = {0};
    flood_fill(grid, player.x, player.y, visited);
    
    for (int i = 0; i < coin_count; i++) {
        if (!visited[coins[i].y][coins[i].x]) {
            return 0; // Coin not reachable
        }
    }
    
    if (!visited[exit.y][exit.x]) {
        return 0; // Exit not reachable
    }
    
    return 1; // All coins and exit are reachable
}

int main() {
    char grid[ROWS][COLS] = {
        {'1', '1', '1', '1', '1', '1'},
        {'1', 'P', '0', 'C', '0', '1'},
        {'1', '0', '1', '0', '0', '1'},
        {'1', 'C', '0', '1', 'E', '1'},
        {'1', '1', '1', '1', '1', '1'}
    };
    
    if (is_path_valid(grid)) {
        printf("Path is valid.\n");
    } else {
        printf("Path is not valid.\n");
    }
    
    return 0;
}
