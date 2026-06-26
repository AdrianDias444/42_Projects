from random import choice
from .config import Config
from .algorithm import algorithm
from .print_grid import print_grid
from .return_less_path import bfs


class MazeGenerator:
    def __init__(self, config: Config) -> None:
        self.config = config

    @staticmethod
    def config_class_checker(config: Config) -> int:
        if config.width == "Error":
            return -1
        if config.height == "Error":
            return -1
        if config.entry == "Error":
            return -1
        if config.exit == "Error":
            return -1
        if config.output_file == "Error":
            return -1
        if config.perfect == "Error":
            return -1
        if config.entry == config.exit:
            print("Entry and Exit Cell cannot be the same.")
            print("Invalid Config File!")
            return -1
        return 0

    def run(self, print_path, color) -> None:
        grid_class = algorithm(self.config, print_path, color)
        return grid_class

    def menu(self) -> None:
        user_nb = 0
        print_path = True
        print("\33c")
        nb = "38;2;0;255;255"
        grid_class = self.run(print_path, nb)
        array = ["38;2;0;255;255", "38;2;80;250;123",
                 "38;2;255;230;167", "38;2;250;240;230", "38;2;255;255;153",
                 "38;2;245;245;220", "38;2;255;245;238", "38;2;173;216;230"
                 "38;2;255;255;255", "38;2;135;206;235", "38;2;255;250;205"]
        try:
            while not user_nb == 4:
                user_nb = int(input("=== A-Maze-ing ===\n"
                                    "1. Re-generate a new maze\n"
                                    "2. Show/Hide path from entry to exit\n"
                                    "3. Rotate maze colors\n"
                                    "4. Quit\n"
                                    "Choice? (1-4): "))

                if user_nb == 1:
                    print("\33c")
                    grid_class = self.run(print_path, nb)
                if user_nb == 2:
                    print("\33c")
                    print(f"\033[{nb}m", end="")
                    if print_path:
                        print_path = False
                    else:
                        print_path = True
                    caminho = bfs(grid_class)
                    print_grid(grid_class, caminho, print_path, nb)
                if user_nb == 3:
                    old_nb = nb
                    array.remove(old_nb)
                    nb = choice(array)
                    array.append(old_nb)
                    print("\33c")
                    print(f"\033[{nb}m", end="")
                    caminho = bfs(grid_class)
                    print_grid(grid_class, caminho, print_path, nb)
            print("\33c")

        except Exception as e:
            print(e)
            exit(-1)
