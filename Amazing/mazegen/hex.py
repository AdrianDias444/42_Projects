from .config import Grid


def give_hex_to_cells(grid: Grid) -> None:
    """Assign hexadecimal values to each cell based on its wall configuration.

    Args:
        grid: Grid object containing cells to update with hex values.
    """
    for row in grid.grid:
        for cell in row:
            if not cell.walls["top"]:
                cell.binary_list[3] = 0
            if not cell.walls["right"]:
                cell.binary_list[2] = 0
            if not cell.walls["bottom"]:
                cell.binary_list[1] = 0
            if not cell.walls["left"]:
                cell.binary_list[0] = 0
            cell.binary = cell.convert_binaryList_to_binary()
            cell.hex = cell.convert_binary_to_hex(cell.binary)


def put_hex_cells_in_file(grid: Grid, coordinates: list[str]) -> None:
    """Write the grid's hex values and path coordinates to the output file.

    Args:
        grid: Grid object containing cells and output configuration.
        coordinates: List of directional strings representing the valid path.
    """
    file = open(grid.output_file, "a")
    for row in grid.grid:
        for cell in row:
            file.write(cell.hex)
        file.write("\n")
    file.write("\n")

    file.write(str(grid.entry_cell.x))
    file.write(",")
    file.write(str(grid.entry_cell.y))

    file.write("\n")
    file.write(str(grid.exit_cell.x))
    file.write(",")
    file.write(str(grid.exit_cell.y))

    file.write("\n")
    for i in coordinates:
        file.write(i)
