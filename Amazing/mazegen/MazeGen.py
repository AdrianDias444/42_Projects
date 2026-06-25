from .config import Config
from .algorithm import algorithm
from sys import exit

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
        return 0


    def run(self) -> None:
        if self.config_class_checker(self.config) == -1:
            exit(-1)

        algorithm(self.config)


"""     def menu(self) -> None:
        choice = 0
        while not choice == 4:
            choice = int(input("=== A-Maze-ing ==="
            "1. Re-generate a new maze"
            "2. Show/Hide path from entry to exit"
            "3. Rotate maze colors"
            "4. Quit"
            "Choice? (1-4): "))

            if choice == 1:
                self.run()
 """