from .config import Grid
from .return_correct_path import calculate_possible_cell


def bfs(grid: Grid):
    """Find the shortest path from entry to exit using Breadth-First Search.
    
    Args:
        grid: Grid object.
        
    Returns:
        List of Cell objects representing the shortest path from entry to exit,
        or empty list if no path found.
    """
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