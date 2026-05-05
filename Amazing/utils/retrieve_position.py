from config import Cell, Grid


def cell_out_of_the_grid(grid: Grid, cell: Cell) -> int:
    if cell.x < 0 or cell.y < 0:
        return -1
    if cell.x >= grid.width:
        return -1
    if cell.y >= grid.height:
        return -1
    else:
        return 1


def return_north_cell(grid: Grid, center_cell: Cell) -> Cell:
    if cell_out_of_the_grid(grid, center_cell) == 1:
        for row in grid.grid:
            for cell in row:
                if cell.x == center_cell.x and center_cell.y == cell.y + 1:
                    return cell
    return Cell(-1, -1)


def return_south_cell(grid: Grid, center_cell: Cell) -> Cell:
    if cell_out_of_the_grid(grid, center_cell) == 1:
        for row in grid.grid:
            for cell in row:
                if cell.x == center_cell.x and center_cell.y == cell.y - 1:
                    return cell
    return Cell(-1, -1)


def return_east_cell(grid: Grid, center_cell: Cell) -> Cell:
    if cell_out_of_the_grid(grid, center_cell) == 1:
        for row in grid.grid:
            for cell in row:
                if cell.y == center_cell.y and cell.x == center_cell.x + 1:
                    return cell
    return Cell(-1, -1)


def return_west_cell(grid: Grid, center_cell: Cell) -> Cell:
    if cell_out_of_the_grid(grid, center_cell) == 1:
        for row in grid.grid:
            for cell in row:
                if cell.y == center_cell.y and cell.x == center_cell.x - 1:
                    return cell
    return Cell(-1, -1)
