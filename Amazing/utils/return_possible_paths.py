# import cmath
from turtle import width

from config import Cell, Grid
from dfs import remove_walls_between
from utils.retrieve_position import (
    return_east_cell,
    return_north_cell,
    return_south_cell,
    return_west_cell,
)
from utils.return_correct_path import calculate_possible_cell


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


"""def calculate_distance(cell1: Cell, cell2: Cell) -> int:
    if cell1.x < 0 or cell2.x < 0 or cell1.y < 0 or cell2.y < 0:
        return float("inf")
    distance = ((cell1.x - cell2.x) ** 2 + (cell1.y - cell2.y) ** 2) ** 0.5

    return distance


# Ainda tenho de analisar caso uma das celulas seja do norte, este, oeste ou sul nao existirem a distancia entre as duas
# celulas pode ficar comprometidas
def remove_brick(grid: Grid, current_cell: Cell) -> Cell:
    north_cell = return_north_cell(grid, current_cell)
    east_cell = return_east_cell(grid, current_cell)
    west_cell = return_west_cell(grid, current_cell)
    south_cell = return_south_cell(grid, current_cell)

    north_distance = calculate_distance(north_cell, grid.entry_cell)
    east_distance = calculate_distance(east_cell, grid.entry_cell)
    west_distance = calculate_distance(west_cell, grid.entry_cell)
    south_distance = calculate_distance(south_cell, grid.entry_cell)

    d = {
        north_distance: north_cell,
        east_distance: east_cell,
        west_distance: west_cell,
        south_distance: south_cell,
    }
    key_cell = min(north_distance, east_distance, west_distance, south_distance)
    remove_walls_between(d[key_cell], current_cell)

    return d[key_cell]


# Com uma lista de celulas proximas consigo retornar a celula mais proxima a celula que defino como ENTER_CELL
def return_closer_cell(enter_cell: Cell, list) -> Cell:
    distances = []
    for c in list:
        distances.append(calculate_distance(c, enter_cell))
    less_distance = min(distances)
    for c in list:
        if calculate_distance(c, enter_cell) == less_distance:
            return c
    return Cell(-1, -1)


def create_more_possible_paths(grid: Grid, caminho):
    entry_cell = grid.entry_cell
    current_cell = grid.exit_cell

    visited = [grid.exit_cell]
    path = [grid.exit_cell]
    while current_cell != entry_cell:
        possible_cells = []
        for c in calculate_possible_cell(grid, current_cell):
            if c not in caminho and c not in visited:
                possible_cells.append(c)
        if possible_cells:
            if len(possible_cells) > 1:
                current_cell = return_closer_cell(entry_cell, possible_cells)
            else:
                current_cell = possible_cells[0]
            visited.append(current_cell)
            path.append(current_cell)
        else:
            current_cell = remove_brick(grid, current_cell)
            visited.append(current_cell)
            path.append(current_cell)
            possible_cells = list(calculate_possible_cell(grid, current_cell))
            if not possible_cells:
                break
            possible_cells = [c for c in possible_cells if c not in visited]
            if not possible_cells:
                break
            current_cell = return_closer_cell(entry_cell, possible_cells)
            path.append(current_cell)
            visited.append(current_cell)
    return path
"""
