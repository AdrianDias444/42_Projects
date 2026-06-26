class Negative_Error(Exception):
    """
    Exception raised for negative or zero (when flagged) number inputs.
    """
    pass


class Perfect_Error(Exception):
    """
    Exception raised for invalid perfect maze boolean string input.
    """
    pass


class X_Out_Width(Exception):
    """
    Exception raised when cell x-coordinate exceeds grid width.
    """
    pass


class Y_Out_Height(Exception):
    """
    Exception raised when cell y-coordinate exceeds grid height.
    """
    pass


class Invalid_Output_File(Exception):
    """
    Exception raised for invalid output file extension.
    """
    pass


class Cell:
    def __init__(self, x: int, y: int) -> None:
        """
        Initialize a Cell with coordinates, walls, state flags 
        and variables for the output file.
        
        Args:
            x: The x-coordinate of the cell.
            y: The y-coordinate of the cell.
        """
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
        """Convert the binary_list attribute to an integer binary representation.
        
        Returns:
            Integer representing the binary value of binary_list.
        """
        binary = 0
        for i in self.binary_list:
            binary = binary * 2 + i
        return binary

    def convert_binary_to_hex(self, binary: int) -> str:
        """Convert a binary integer to its hexadecimal string representation.
        
        Args:
            binary: Integer to convert to hexadecimal.
            
        Returns:
            Hexadecimal string representation of the binary integer.
        """
        return format(binary, "X")


def raise_negative_error(nb: int, flag: bool) -> None:
    """
    Raise Negative_Error if nb is negative or zero when flagged.
    
    Args:
        nb: Number to validate.
        flag: If True, also raise error when nb is zero.
        
    Raises:
        Negative_Error: If nb is negative, or if flag is True and nb is zero.
    """
    if nb < 0:
        raise Negative_Error(f"Invalid input! [{nb}] is a invalid (negative) "
                             "number")
    if nb == 0 and flag:
        raise Negative_Error(f"Invalid input! [{nb}] is a invalid number")


def raise_perfect_error(perfect: str) -> None:
    """
    Raise Perfect_Error if perfect is not 'TRUE' or 'FALSE' (case-insensitive).
    
    Args:
        perfect: String to validate as boolean.
        
    Raises:
        Perfect_Error: If perfect is not 'TRUE' or 'FALSE'.
    """
    perfect = perfect.upper()
    if not (perfect == "TRUE" or perfect == "FALSE"):
        raise Perfect_Error(f"Invalid input! [{perfect}] is not "
                            "a boolean string")


def raise_x_out_width(grid_width: int, cell_x: int) -> None:
    """
    Raise X_Out_Width if cell_x is greater than or equal to grid_width.
    
    Args:
        grid_width: Width of the grid.
        cell_x: X-coordinate to validate.
        
    Raises:
        X_Out_Width: If cell_x >= grid_width.
    """
    if cell_x >= grid_width:
        raise X_Out_Width(f"Invalid input! [{cell_x}] invalid x-axis")


def raise_y_out_height(grid_height: int, cell_y: int) -> None:
    """
    Raise Y_Out_Height if cell_y is greater than or equal to grid_height.
    
    Args:
        grid_height: Height of the grid.
        cell_y: Y-coordinate to validate.
        
    Raises:
        Y_Out_Height: If cell_y >= grid_height.
    """
    if cell_y >= grid_height:
        raise Y_Out_Height(f"Invalid input! [{cell_y}] invalid y-axis")


def raise_invalid_output_file(output_file: str) -> None:
    """
    Raise Invalid_Output_File if output_file extension is not '.txt'.
    
    Args:
        output_file: Filename to validate.
        
    Raises:
        Invalid_Output_File: If extension is not 'txt'.
    """
    str1 = output_file.split(".", maxsplit=1)
    if "." in output_file:
        if not str1[1] == "txt":
            raise Invalid_Output_File(
                f"Invalid input! [.{str1[1]}] is a invalid extension"
            )


def process_number_input(nb: str, flag: bool) -> int | str:
    """
    Process and validate a numeric string input.
    
    Args:
        nb: String to convert to integer.
        flag: Passed to raise_negative_error to control zero validation.
        
    Returns:
        The integer value if valid, or "Error" string if invalid.
    """
    try:
        number = int(nb)
        raise_negative_error(number, flag)
        return number
    except ValueError:
        print(f"[{nb.strip()}] is not a int number")
        return "Error"
    except Negative_Error as e:
        print(e)
        return "Error"


def process_cell_input(cell: str, configs: 'Config', flag: bool) -> str | Cell:
    """
    Process and validate cell coordinate input string.
    
    Args:
        cell: String with x,y coordinates.
        configs: Config object for grid dimensions validation.
        flag: Passed to process_number_input for zero validation.
        
    Returns:
        Valid cell coordinate string, or "Error" string if invalid.
    """
    i = 0
    try:
        array = cell.split(",", maxsplit=1)
        if len(array) == 1:
            print(f"[{array[0]}] is a invalid Cell Config. ", end="")
            print("Need correct coordinates format")
            return "Error"
        for c in array:
            c = process_number_input(c, flag) # type: ignore
            c = int(c) #type: ignore
            if i == 0:
                if not configs.width == "Error":
                    raise_x_out_width(configs.width, c) #type: ignore
            elif i == 1:
                if not configs.height == "Error":
                    raise_y_out_height(configs.height, c) #type: ignore
            i += 1

    except ValueError:
        print(f"[{cell.strip()}] is a invalid cell coordinate")
        return "Error"
    except X_Out_Width as e:
        print(e)
        return "Error"
    except Y_Out_Height as e:
        print(e)
        return "Error"

    return cell


def process_output_file(output_file: str) -> str:
    """
    Process and validate output filename string.
    
    Args:
        output_file: Filename string to validate.
        
    Returns:
        Valid output filename, or "Error" string if invalid.
    """
    output_file = output_file.strip()
    try:
        raise_invalid_output_file(output_file)
    except Invalid_Output_File as e:
        print(e)
        return "Error"
    return output_file


def process_perfect_input(perfect: str) -> str:
    """
    Process and validate perfect maze boolean string input.
    
    Args:
        perfect: String to validate as boolean.
        
    Returns:
        Valid perfect string, or "Error" string if invalid.
    """
    perfect = perfect.strip()
    try:
        raise_perfect_error(perfect)
    except Perfect_Error as e:
        print(e)
        return "Error"
    return perfect


class Config:
    def __init__(self, lst_values) -> None:
        """
        Initialize Config by processing all input values from lst_values.
        
        Args:
            lst_values: List of strings containing width, height, entry, exit, 
                output_file, and perfect.
        """
        self.width = process_number_input(lst_values[0].replace(" ", ""),
                                          True)
        self.height = process_number_input(lst_values[1].replace(" ", ""),
                                           True)
        self.entry = process_cell_input(lst_values[2].replace(" ", ""), self,
                                        False)
        self.exit = process_cell_input(lst_values[3].replace(" ", ""), self,
                                       False)
        self.output_file = process_output_file(lst_values[4].replace(" ", ""))
        self.perfect = process_perfect_input(lst_values[5].replace(" ", ""))




class Grid:
    def __init__(self, configs) -> None:
        """
        Initialize Grid from Config object, create grid and mark entry/exit cells.
        
        Args:
            configs: Config object with grid parameters.
        """
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
        """
        Create a 2D grid of Cell objects based on width and height.
        
        Returns:
            2D list of Cell objects representing the grid.
        """
        grid = []
        for y in range(self.height):
            row = []
            for x in range(self.width):
                cell = Cell(x, y)
                row.append(cell)
            grid.append(row)
        return grid

    def print_grid(self) -> None:
        """
        Print the grid displaying coordinates of each cell.
        """
        for row in self.grid:
            for cell in row:
                print(f"({cell.x},{cell.y})", end="")
            print()

    def mark_entry(self) -> Cell:
        """
        Mark the entry cell in the grid and return it.
        
        Returns:
            The Cell marked as entry, or Cell(-1, -1) if not found.
        """
        self.entry[0] = int(self.entry[0])
        self.entry[1] = int(self.entry[1])
        for row in self.grid:
            for cell in row:
                if cell.x == self.entry[0] and cell.y == self.entry[1]:
                    cell.entry = True
                    return cell
        return Cell(-1, -1)

    def mark_exit(self) -> Cell:
        """
        Mark the exit cell in the grid and return it.
        
        Returns:
            The Cell marked as exit, or Cell(-1, -1) if not found.
        """
        self.exit[0] = int(self.exit[0])
        self.exit[1] = int(self.exit[1])
        for row in self.grid:
            for cell in row:
                if cell.x == self.exit[0] and cell.y == self.exit[1]:
                    cell.exit = True
                    return cell
        return Cell(-1, -1)