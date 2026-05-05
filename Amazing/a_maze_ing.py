import sys

import dfs
from config import Config, Grid
from logo import retry_logo_cells
from output_file import coordinates_valid_path as cvp
from output_file import hex
from utils import print_grid
from utils import retrieve_position as rp
from utils.return_correct_path import return_correct_path


def parser_to_class(file):
    lst_configs = []
    for row in file:
        array = row.split("=")
        lst_configs.append(array[1])
    inst = Config(lst_configs)
    return inst


def main():
    if len(sys.argv) == 2:
        # m = Mlx()
        # mlx_ptr = m.mlx_init()
        # window = m.mlx_new_window(mlx_ptr, 400, 300, "screen")
        file = open("config.txt", "r")
        config_class = parser_to_class(file)
        grid_class = Grid(config_class)

        retry_logo_cells.retry_logo_cells(grid_class)
        dfs.dfs(grid_class)
        caminho = return_correct_path(grid_class)
        print_grid.print_grid(grid_class, caminho)

        coordinates = cvp.coordinates_valid_path(grid_class, caminho)
        hex.give_hex_to_cells(grid_class)
        hex.put_hex_cells_in_file(grid_class, coordinates)

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
