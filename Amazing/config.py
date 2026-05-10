class Negative_Error(Exception):
    pass


class Perfect_Error(Exception):
    pass


class X_Out_Width(Exception):
    pass


class Y_Out_Height(Exception):
    pass


class Invalid_Output_File(Exception):
    pass


def raise_negative_error(nb: int, grid: bool) -> None:
    if nb < 0:
        raise Negative_Error(f"Invalid input! [{nb}] is a invalid (negative) number")
    if nb == 0 and grid:
        raise Negative_Error(f"Invalid input! [{nb}] is a invalid number")


def raise_perfect_error(perfect: str) -> None:
    if (
        not perfect == "True"
        and not perfect == "true"
        and not perfect == "False"
        and not perfect == "false"
    ):
        raise Perfect_Error(f"Invalid input! [{perfect}] is not a boolean string")


def raise_x_out_width(grid_width: int, cell_x: int) -> None:
    if not grid_width == "Error" and cell_x >= grid_width:
        raise X_Out_Width(f"Invalid input! [{cell_x}] invalid x-axis")


def raise_y_out_height(grid_height: int, cell_y: int) -> None:
    if not grid_height == "Error" and cell_y >= grid_height:
        raise Y_Out_Height(f"Invalid input! [{cell_y}] invalid y-axis")


def raise_invalid_output_file(output_file: str) -> None:
    str = output_file.split(".", maxsplit=1)
    if "." in output_file:
        if len(str) > 2 or not str[1] == "txt":
            raise Invalid_Output_File(
                f"Invalid input! [.{str[1]}] is a invalid extension"
            )


def process_number_input(nb: str, grid: bool):
    try:
        number = int(nb)
        raise_negative_error(number, grid)
        return number
    except ValueError:
        print(f"[{nb.strip()}] is not a number")
        return "Error"
    except Negative_Error as e:
        print(e)
        return "Error"


def process_cell_input(cell: str, configs, grid: bool) -> str:
    i = 0
    try:
        array = cell.split(",", maxsplit=1)
        for c in array:
            c = process_number_input(c, grid)
            c = int(c)
            if i == 0:
                raise_x_out_width(configs.width, c)
            elif i == 1:
                raise_y_out_height(configs.height, c)
            i += 1

    except ValueError:
        print(f"[{cell}] is a invalid cell coordinate")
        return "Error"
    except X_Out_Width as e:
        print(e)
        return "Error"
    except Y_Out_Height as e:
        print(e)
        return "Error"

    return cell


def process_output_file(output_file: str) -> str:
    output_file = output_file.strip()
    try:
        raise_invalid_output_file(output_file)
    except Invalid_Output_File as e:
        print(e)
        return "Error"
    return output_file


def process_perfect_input(perfect: str) -> str:
    perfect = perfect.strip()
    try:
        raise_perfect_error(perfect)
    except Perfect_Error as e:
        print(e)
        return "Error"
    return perfect


class Config:
    def __init__(self, config) -> None:
        self.width = process_number_input(config[0].replace(" ", ""), True)
        self.height = process_number_input(config[1].replace(" ", ""), True)
        self.entry = process_cell_input(config[2].strip().replace(" ", ""), self, False)
        self.exit = process_cell_input(config[3].strip().replace(" ", ""), self, False)
        self.output_file = process_output_file(config[4].replace(" ", ""))
        self.perfect = process_perfect_input(config[5].replace(" ", ""))


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
