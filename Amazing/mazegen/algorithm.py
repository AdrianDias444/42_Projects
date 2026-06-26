from .config import Grid
from .retry_logo_cells import retry_logo_cells
from .dfs import dfs
from .return_correct_path import return_correct_path
from .print_grid import print_grid
from .coordinates_valid_path import coordinates_valid_path
from .hex import give_hex_to_cells, put_hex_cells_in_file
from .return_possible_paths import create_more_possible_paths
from .return_less_path import bfs


def algorithm(config_class, print_path, color):
    """Execute the maze generation algorithm from configuration to output.
    
    Args:
        config_class: Config object with maze parameters.
        print_path: Boolean flag to control path printing.
        color: Color setting for grid printing.
        
    Returns:
        Grid object representing the generated maze.
    """
    grid_class = Grid(config_class)

    if grid_class.width > 10 and grid_class.height > 10:
        retry_logo_cells(grid_class)
    else:
        print("Not enought space for 42 logo")
    dfs(grid_class)
    caminho = []
    if grid_class.perfect.capitalize() == "True":
        caminho = return_correct_path(grid_class)
    elif grid_class.perfect.capitalize() == "False":
        create_more_possible_paths(grid_class)
        caminho = bfs(grid_class)
    print_grid(grid_class, caminho, print_path, color)

    coordinates = coordinates_valid_path(grid_class, caminho)
    give_hex_to_cells(grid_class)
    put_hex_cells_in_file(grid_class, coordinates)

    return grid_class