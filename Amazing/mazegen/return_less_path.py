from .config import Cell, Grid
from .return_correct_path import calculate_possible_cell


def bfs(grid: Grid):
    entry_cell = grid.entry_cell
    exit_cell = grid.exit_cell

    queue = [[entry_cell]]
    visited = {entry_cell}

    while queue:
        path = queue.pop(0)
        current_cell = path[-1]

        if current_cell == exit_cell:
            return path

        for neighbor in calculate_possible_cell(grid, current_cell):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(path + [neighbor])

    return []
