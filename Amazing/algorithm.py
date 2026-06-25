import dfs
from logo.retry_logo_cells import retry_logo_cells
from output_file import coordinates_valid_path as cvp
from output_file import hex
from utils import print_grid, return_less_path
from utils.return_possible_paths import create_more_possible_paths
from utils.return_correct_path import return_correct_path
from utils import retrieve_position as rp
from config import Config, Grid


def algorithm(config_class):
    grid_class = Grid(config_class)

    if grid_class.width > 10 and grid_class.height > 10:
        retry_logo_cells(grid_class)
    else:
        print("Not enought space for 42 logo")
    dfs.dfs(grid_class)
    caminho = []
    if grid_class.perfect == "True":
        caminho = return_correct_path(grid_class)
    elif grid_class.perfect == "False":
        create_more_possible_paths(grid_class)
        caminho = return_less_path.bfs(grid_class)
    print_grid.print_grid(grid_class, caminho)

    coordinates = cvp.coordinates_valid_path(grid_class, caminho)
    hex.give_hex_to_cells(grid_class)
    hex.put_hex_cells_in_file(grid_class, coordinates)