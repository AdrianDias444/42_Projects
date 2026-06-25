from .config import Cell, Grid
from .dfs import remove_walls_between
from .retrieve_position import (
    return_east_cell,
    return_north_cell,
    return_south_cell,
    return_west_cell,
)
from .return_correct_path import calculate_possible_cell


def create_more_possible_paths(grid: Grid):
    entry_cell = grid.entry_cell

    for cell in grid.grid[entry_cell.y]:
        if cell.x == 0:
            cell.walls["right"] = False
        elif cell.x == grid.width - 1:
            cell.walls["left"] = False
        else:
            cell.walls["right"] = False
            cell.walls["left"] = False
