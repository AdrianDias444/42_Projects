import sys

import dfs
import parser
from config import Config, Grid
from logo import retry_logo_cells
from output_file import coordinates_valid_path as cvp
from output_file import hex
from utils import print_grid, return_less_path, return_possible_paths
from utils import retrieve_position as rp
from utils.return_correct_path import return_correct_path


def config_class_checker(config_class: Config) -> int:
    if config_class.width == "Error":
        return -1
    if config_class.height == "Error":
        return -1
    if config_class.entry == "Error":
        return -1
    if config_class.exit == "Error":
        return -1
    if config_class.output_file == "Error":
        return -1
    if config_class.perfect == "Error":
        return -1
    return 0


def main():
    if len(sys.argv) == 2:
        file = open(sys.argv[1], "r")
        config_class = parser.parser_to_class(file)
        if config_class == "Error":
            return
        if config_class_checker(config_class) == -1:
            return

        grid_class = Grid(config_class)

        if grid_class.width > 10 and grid_class.height > 10:
            retry_logo_cells.retry_logo_cells(grid_class)
        else:
            print("Not enought space for 42 logo")
        dfs.dfs(grid_class)
        caminho = []
        if grid_class.perfect == "True":
            caminho = return_correct_path(grid_class)
        elif grid_class.perfect == "False":
            return_possible_paths.create_more_possible_paths(grid_class)
            caminho = return_less_path.bfs(grid_class)
        print_grid.print_grid(grid_class, caminho)

        coordinates = cvp.coordinates_valid_path(grid_class, caminho)
        hex.give_hex_to_cells(grid_class)
        hex.put_hex_cells_in_file(grid_class, coordinates)

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
