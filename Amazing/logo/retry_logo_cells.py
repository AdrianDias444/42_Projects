from config import Cell, Grid


def make_cells_visited_right(grid: Grid, center_cell: Cell, aresta: int):
    lock = False
    i = 0
    cells = []
    for cell in grid.grid[center_cell.y]:
        if cell == center_cell:
            lock = True
            continue
        if lock and i < aresta and not cell.entry and not cell.exit:
            cell.visited = True
            cell.logo = True
            cells.append(cell)
            i += 1
    return cells


def make_cells_visited_left(grid: Grid, center_cell: Cell, aresta: int):
    i = 0
    cells = []
    for cell in reversed(grid.grid[center_cell.y]):
        if cell.x < center_cell.x and i < aresta and not cell.entry and not cell.exit:
            cell.visited = True
            cell.logo = True
            cells.append(cell)
            i += 1
    return cells


def make_cells_visited_top(grid: Grid, center_cell: Cell, aresta: int):
    cells = []
    for row in grid.grid:
        for cell in row:
            if (
                cell.x == center_cell.x
                and center_cell.y - aresta <= cell.y < center_cell.y
                and not cell.entry
                and not cell.exit
            ):
                cell.visited = True
                cell.logo = True
                cells.append(cell)
    return cells


def make_cells_visited_bottom(grid: Grid, center_cell: Cell, aresta: int):
    cells = []
    for row in grid.grid:
        for cell in row:
            if (
                cell.x == center_cell.x
                and center_cell.y < cell.y <= center_cell.y + aresta
                and not cell.entry
                and not cell.exit
            ):
                cell.visited = True
                cell.logo = True
                cells.append(cell)
    return cells


def make_4(grid: Grid, center_cell: Cell, aresta: int):
    left_cells = make_cells_visited_left(grid, center_cell, aresta)

    make_cells_visited_top(grid, left_cells[-1], aresta - 1)
    make_cells_visited_bottom(grid, left_cells[0], aresta - 1)


def make_2(grid: Grid, center_cell: Cell, aresta: int):
    right_cells = make_cells_visited_right(grid, center_cell, aresta)

    top_right = make_cells_visited_top(grid, right_cells[-1], aresta - 1)
    make_cells_visited_left(grid, top_right[0], aresta - 1)

    bottom_right = make_cells_visited_bottom(grid, right_cells[0], aresta - 1)
    make_cells_visited_right(grid, bottom_right[-1], aresta - 1)


def retry_logo_cells(grid: Grid):
    mid_x = grid.width // 2
    mid_y = grid.height // 2

    center_cell = grid.grid[mid_y][mid_x]

    aresta = 3

    make_4(grid, center_cell, aresta)
    make_2(grid, center_cell, aresta)
