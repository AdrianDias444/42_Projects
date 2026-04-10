import sys

from config import Cell, Config, Grid
from mlx import Mlx


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

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
