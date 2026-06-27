from .config import Grid


def if_is_row_all_open(grid: Grid) -> int:
    """
    Check if all walls along the entry row are already open.
    """
    entry_cell = grid.entry_cell

    for cell in grid.grid[entry_cell.y]:
        if cell.x == 0:
            if cell.walls["right"]:
                return -1
        if cell.x == grid.width - 1:
            if cell.walls["left"]:
                return -1
        if cell.walls["right"] and cell.walls["left"]:
            return -1
    return 1


def create_more_possible_paths(grid: Grid) -> None:
    """
    Remove walls along the entry row to create multiple possible paths.

    Args:
        grid: Grid object containing the maze.
    """
    entry_cell = grid.entry_cell
    if if_is_row_all_open(grid) == -1:
        for cell in grid.grid[entry_cell.y]:
            if cell.x == 0:
                cell.walls["right"] = False
            elif cell.x == grid.width - 1:
                cell.walls["left"] = False
            else:
                cell.walls["right"] = False
                cell.walls["left"] = False
    else:
        if entry_cell.y == 0:
            entry_cell.walls["bottom"] = False
        if entry_cell.y == grid.height - 1:
            entry_cell.walls["top"] = False
        else:
            if entry_cell.walls["top"]:
                entry_cell.walls["top"] = False
            elif entry_cell.walls["bottom"]:
                entry_cell.walls["bottom"] = False
