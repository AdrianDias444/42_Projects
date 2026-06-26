from .config import Grid, Cell


def make_cells_visited_right(grid: Grid, center_cell: Cell,
                             aresta: int) -> list[Cell]:
    """
    Mark cells to the right of center_cell as visited and
    define them as logo cells.

    Args:
        grid: Grid object.
        center_cell: Reference cell to start from.
        aresta: Number of cells to mark to the right.

    Returns:
        List of Cell objects that were marked.
    """
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


def make_cells_visited_left(grid: Grid, center_cell: Cell,
                            aresta: int) -> list[Cell]:
    """
    Mark cells to the left of center_cell as visited and
    define them as logo cells.

    Args:
        grid: Grid object.
        center_cell: Reference cell to start from.
        aresta: Number of cells to mark to the left.

    Returns:
        List of Cell objects that were marked.
    """
    i = 0
    cells = []
    for cell in reversed(grid.grid[center_cell.y]):
        if (
            cell.x < center_cell.x and i < aresta and
            not cell.entry and not cell.exit
        ):

            cell.visited = True
            cell.logo = True
            cells.append(cell)
            i += 1
    return cells


def make_cells_visited_top(grid: Grid, center_cell: Cell,
                           aresta: int) -> list[Cell]:
    """Mark cells above center_cell as visited and
    define them as logo cells.

    Args:
        grid: Grid object.
        center_cell: Reference cell to start from.
        aresta: Number of cells to mark above.

    Returns:
        List of Cell objects that were marked.
    """
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


def make_cells_visited_bottom(grid: Grid, center_cell: Cell,
                              aresta: int) -> list[Cell]:
    """Mark cells below center_cell as visited and
    define them as logo cells.

    Args:
        grid: Grid object.
        center_cell: Reference cell to start from.
        aresta: Number of cells to mark below.

    Returns:
        List of Cell objects that were marked.
    """
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


def make_4(grid: Grid, center_cell: Cell, aresta: int) -> None:
    """Create the '4' shape of the logo using visited cells.

    Args:
        grid: Grid object.
        center_cell: Reference cell for logo placement.
        aresta: Size parameter for the shape.
    """
    left_cells = make_cells_visited_left(grid, center_cell, aresta)

    make_cells_visited_top(grid, left_cells[-1], aresta - 1)
    make_cells_visited_bottom(grid, left_cells[0], aresta - 1)


def make_2(grid: Grid, center_cell: Cell, aresta: int) -> None:
    """Create the '2' shape of the logo using visited cells.

    Args:
        grid: Grid object.
        center_cell: Reference cell for logo placement.
        aresta: Size parameter for the shape.
    """
    right_cells = make_cells_visited_right(grid, center_cell, aresta)

    top_right = make_cells_visited_top(grid, right_cells[-1], aresta - 1)
    make_cells_visited_left(grid, top_right[0], aresta - 1)

    bottom_right = make_cells_visited_bottom(grid, right_cells[0], aresta - 1)
    make_cells_visited_right(grid, bottom_right[-1], aresta - 1)


def retry_logo_cells(grid: Grid) -> None:
    """Draw the '42' logo in the center of the grid by marking cells.

    Args:
        grid: Grid object.
    """
    mid_x = grid.width // 2
    mid_y = grid.height // 2

    center_cell = grid.grid[mid_y][mid_x]

    aresta = 3

    make_4(grid, center_cell, aresta)
    make_2(grid, center_cell, aresta)
