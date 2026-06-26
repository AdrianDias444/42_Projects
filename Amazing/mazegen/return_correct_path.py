import random
from typing import Generator

from .config import Cell, Grid
from .retrieve_position import (return_east_cell, return_north_cell,
                                return_south_cell, return_west_cell,)


def calculate_possible_cell(grid: Grid,
                            current_cell: Cell) -> Generator[Cell, None, None]:
    """
    Yield all accessible neighbor cells through open walls from current_cell.

    Args:
        grid: Grid object containing the maze.
        current_cell: Cell to find accessible neighbors from.

    Yields:
        Cell objects that are connected via open walls (no wall between).
    """
    north_cell = return_north_cell(grid, current_cell)
    if not current_cell.walls["top"] and not north_cell.walls["bottom"]:
        yield north_cell
    else:
        pass

    south_cell = return_south_cell(grid, current_cell)
    if not current_cell.walls["bottom"] and not south_cell.walls["top"]:
        yield south_cell
    else:
        pass

    west_cell = return_west_cell(grid, current_cell)
    if not current_cell.walls["left"] and not west_cell.walls["right"]:
        yield west_cell
    else:
        pass

    east_cell = return_east_cell(grid, current_cell)
    if not current_cell.walls["right"] and not east_cell.walls["left"]:
        yield east_cell
    else:
        pass


def return_correct_path(grid: Grid) -> list[Cell]:
    """
    Find a valid path from entry to exit using backtracking
    with random choices.

    Args:
        grid: Grid object.

    Returns:
        List of Cell objects representing the path from entry to
        exit, or empty list if no path found.
    """
    path = [grid.entry_cell]
    visited = {grid.entry_cell}
    current_cell = grid.entry_cell

    while current_cell != grid.exit_cell:
        possible_cells = []
        for c in calculate_possible_cell(grid, current_cell):
            if c not in visited:
                possible_cells.append(c)

        if possible_cells:
            current_cell = random.choice(possible_cells)
            visited.add(current_cell)
            path.append(current_cell)
        elif len(path) > 1:
            path.pop()
            current_cell = path[-1]
        else:
            return []

    return path
