from .config import Grid


def create_more_possible_paths(grid: Grid):
    """
    Remove walls along the entry row to create multiple possible paths.
    
    Args:
        grid: Grid object containing the maze.
    """
    entry_cell = grid.entry_cell

    for cell in grid.grid[entry_cell.y]:
        if cell.x == 0:
            cell.walls["right"] = False
        elif cell.x == grid.width - 1:
            cell.walls["left"] = False
        else:
            cell.walls["right"] = False
            cell.walls["left"] = False