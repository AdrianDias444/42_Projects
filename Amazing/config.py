class Config:
    def __init__(self, config) -> None:
        self.width = int(config[0])
        self.height = int(config[1])
        self.entry = config[2]
        self.exit = config[3]
        self.output_file = config[4]
        self.perfect = config[5]


class Cell:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y
        self.walls = {"top": True, "left": True, "bottom": True, "right": True}
        self.entry = False
        self.exit = False
        self.visited = False
        self.logo = False
        self.binary_list = [1, 1, 1, 1]
        self.binary = 0
        self.hex = ""

    def convert_binaryList_to_binary(self) -> int:
        binary = 0
        for i in self.binary_list:
            binary = binary * 2 + i
        return binary

    def convert_binary_to_hex(self, binary):
        return format(binary, "X")


class Grid:
    def __init__(self, configs) -> None:
        self.width = configs.width
        self.height = configs.height
        self.entry = configs.entry.split(",")
        self.exit = configs.exit.split(",")
        self.output_file = configs.output_file
        self.perfect = configs.perfect
        self.grid = self.create_grid()
        self.entry_cell = self.mark_entry()
        self.exit_cell = self.mark_exit()

    def create_grid(self) -> list[list[Cell]]:
        grid = []
        for y in range(self.height):
            row = []
            for x in range(self.width):
                cell = Cell(x, y)
                row.append(cell)
            grid.append(row)
        return grid

    def print_grid(self) -> None:
        for row in self.grid:
            for cell in row:
                print(f"({cell.x},{cell.y})", end="")
            print()

    def mark_entry(self) -> Cell:
        for row in self.grid:
            for cell in row:
                if cell.x == int(self.entry[0]) and cell.y == int(self.entry[1]):
                    cell.entry = True
                    return cell
        return Cell(-1, -1)

    def mark_exit(self) -> Cell:
        for row in self.grid:
            for cell in row:
                if cell.x == int(self.exit[0]) and cell.y == int(self.exit[1]):
                    cell.exit = True
                    return cell
        return Cell(-1, -1)
