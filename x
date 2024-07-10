def find_positions(grid, element):
    positions = []
    for y, row in enumerate(grid):
        for x, cell in enumerate(row):
            if cell == element:
                positions.append((x, y))
    return positions

def flood_fill(grid, x, y, visited):
    if x < 0 or x >= len(grid[0]) or y < 0 or y >= len(grid):
        return
    if grid[y][x] in ('1', 'P', 'C', 'E') and (x, y) not in visited:
        visited.add((x, y))
        flood_fill(grid, x+1, y, visited)
        flood_fill(grid, x-1, y, visited)
        flood_fill(grid, x, y+1, visited)
        flood_fill(grid, x, y-1, visited)

def is_path_valid(grid):
    player_pos = find_positions(grid, 'P')[0]
    coin_positions = find_positions(grid, 'C')
    exit_pos = find_positions(grid, 'E')[0]

    visited = set()
    flood_fill(grid, player_pos[0], player_pos[1], visited)

    all_positions = coin_positions + [exit_pos]
    for pos in all_positions:
        if pos not in visited:
            return False
    return True

# Exemple de tableau
grid = [
    ['1', '1', '1', '1', '1', '1'],
    ['1', 'P', '0', 'C', '0', '1'],
    ['1', '0', '1', '0', '0', '1'],
    ['1', 'C', '0', '1', 'E', '1'],
    ['1', '1', '1', '1', '1', '1']
]

print(is_path_valid(grid))  # Devrait imprimer True si le chemin est valide
