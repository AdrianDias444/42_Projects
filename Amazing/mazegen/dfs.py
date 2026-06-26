from typing import Generator
from random import choice
from .config import Grid, Cell
from .retrieve_position import (return_north_cell, return_east_cell,
                                return_south_cell, return_west_cell)


def calculate_unvisited_neighbors(
    grid: Grid, cell: Cell
) -> Generator[Cell, None, None]:
    """Yield all unvisited neighbor cells of a given cell.
    
    Args:
        grid: Grid object containing the maze.
        cell: Cell to check neighbors from.
        
    Yields:
        Unvisited neighbor Cell objects (north, east, south, west).
    """
    norht_cell = return_north_cell(grid, cell)
    if norht_cell.x >= 0 and not norht_cell.visited:
        yield norht_cell

    east_cell = return_east_cell(grid, cell)
    if east_cell.x >= 0 and not east_cell.visited:
        yield east_cell

    south_cell = return_south_cell(grid, cell)
    if south_cell.x >= 0 and not south_cell.visited:
        yield south_cell

    west_cell = return_west_cell(grid, cell)
    if west_cell.x >= 0 and not west_cell.visited:
        yield west_cell


def remove_walls_between(cell1: Cell, cell2: Cell):
    """Remove the walls between two adjacent cells.
    
    Args:
        cell1: First Cell object.
        cell2: Second Cell object adjacent to cell1.
    """
    if cell2.x == cell1.x + 1:  # cell2 está à direita
        cell1.walls["right"] = False
        cell2.walls["left"] = False
    elif cell2.x == cell1.x - 1:  # cell2 está à esquerda
        cell1.walls["left"] = False
        cell2.walls["right"] = False
    elif cell2.y == cell1.y + 1:  # cell2 está abaixo
        cell1.walls["bottom"] = False
        cell2.walls["top"] = False
    elif cell2.y == cell1.y - 1:  # cell2 está acima
        cell1.walls["top"] = False
        cell2.walls["bottom"] = False


def dfs(grid: Grid):
    """Generate a maze using iterative Depth-First Search algorithm.
    
    Args:
        grid: Grid object with cells to remove the correct walls
        to make the maze.
        
    Returns:
        List of Cell objects representing the DFS traversal path.
    """
    caminho = []
    total = []
    entry_cell = grid.entry_cell
    entry_cell.visited = True
    caminho.append(entry_cell)
    total.append(entry_cell)

    while len(total) != grid.width * grid.height:
        current = caminho[-1]

        unvisited = list(calculate_unvisited_neighbors(grid, current))

        if len(unvisited) > 0:
            next_cell = choice(unvisited)
            next_cell.visited = True

            if not next_cell.logo:
                remove_walls_between(current, next_cell)

            caminho.append(next_cell)
            total.append(next_cell)
        else:
            caminho.pop()
            if not caminho:
                break
    return caminho