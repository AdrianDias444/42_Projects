from config import Grid
from utils import retrieve_position as rp


def coordinates_valid_path(grid: Grid, path):
    coordinates = []
    current_cell = grid.entry_cell
    visited = [current_cell]

    while not current_cell == grid.exit_cell:
        north_cell = rp.return_north_cell(grid, current_cell)
        east_cell = rp.return_east_cell(grid, current_cell)
        south_cell = rp.return_south_cell(grid, current_cell)
        west_cell = rp.return_west_cell(grid, current_cell)
        if (
            north_cell in path
            and north_cell not in visited
            and not north_cell.walls["bottom"]
        ):
            coordinates.append("N")
            visited.append(north_cell)
            current_cell = north_cell

        elif (
            east_cell in path
            and east_cell not in visited
            and not east_cell.walls["left"]
        ):
            coordinates.append("E")
            visited.append(east_cell)
            current_cell = east_cell

        elif (
            south_cell in path
            and south_cell not in visited
            and not south_cell.walls["top"]
        ):
            coordinates.append("S")
            visited.append(south_cell)
            current_cell = south_cell

        elif (
            west_cell in path
            and west_cell not in visited
            and not west_cell.walls["right"]
        ):
            coordinates.append("W")
            visited.append(west_cell)
            current_cell = west_cell
        else:
            break
    return coordinates
