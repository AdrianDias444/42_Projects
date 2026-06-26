from .config import Grid, Cell


def c(texto: str, cor: str) -> str:
    """
    Apply ANSI color formatting to text.

    Args:
        texto: Text string to colorize.
        cor: ANSI color code string.

    Returns:
        Colorized text string with ANSI reset at the end.
    """
    return f"\033[{cor}m{texto}\033[0m"


def print_grid(grid: Grid, caminho: list[Cell],
               print_path: bool, color: str) -> None:
    """
    Print the maze grid with walls, entry, exit, logo cells, and optional path.

    Args:
        grid: Grid object containing the maze.
        caminho: List of Cell objects representing the valid path.
        print_path: If True, highlight the path cells with dots.
        color: ANSI color code for grid walls.
    """
    for row in grid.grid:
        # LINHA TOP
        for cell in row:
            if cell.walls["top"]:
                print(c("+---", color), end="")
            else:
                print(c("+   ", color), end="")
            last_cell = cell
        print(c("+", color))

        # LINHA MID
        for cell in row:
            if cell.walls["left"]:
                if cell == grid.entry_cell:
                    print(c("|", color), c("Ent", "33"), end="", sep="")
                elif cell == grid.exit_cell:
                    print(c("|", color), c("Exi", "33"), end="", sep="")
                elif cell.logo:
                    print(c("|", color), c("###", "31"), end="", sep="")
                elif cell in caminho and print_path:
                    print(c("|", color), c(" . ", "38;5;46"), end="", sep="")
                else:
                    print(c("|   ", color), end="")
            else:
                if cell == grid.entry_cell:
                    print(c(" Ent", "33"), end="")
                elif cell == grid.exit_cell:
                    print(c(" Exi", "33"), end="")
                elif cell.logo:
                    print(c("####", "31"), end="")
                elif cell in caminho and print_path:
                    print(c("  . ", "38;5;46"), end="")
                else:
                    print(c("    ", color), end="")
            last_cell = cell

        # BORDA DIREITA
        if last_cell.walls["right"]:
            print(c("|", color))
        else:
            print(" ")

    # LINHA BOTTOM
    for cell in grid.grid[-1]:
        print(c("+---", color) if cell.walls["bottom"]
              else c("+   ", color), end="")
    print(c("+", color))
