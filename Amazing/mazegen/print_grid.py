from .config import Grid


def c(texto, cor):
    return f"\033[{cor}m{texto}\033[0m"


def print_grid(grid: Grid, caminho, print_path: bool, color: int):
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
                    print(c("|", color), c("Ent", 33), end="", sep="")
                elif cell == grid.exit_cell:
                    print(c("|", color), c("Exi", 33), end="", sep="")
                elif cell.logo:
                    print(c("|", color), c("###", 31), end="", sep="")
                elif cell in caminho and print_path:
                    print(c("|", color), c(" . ", "38;5;46"), end="", sep="")
                else:
                    print(c("|   ", color), end="")
            else:
                if cell == grid.entry_cell:
                    print(c(" Ent", 33), end="")
                elif cell == grid.exit_cell:
                    print(c(" Exi", 33), end="")
                elif cell.logo:
                    print(c("####", 31), end="")
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
        print(c("+---", color) if cell.walls["bottom"] else c("+   ", color), end="")
    print(c("+", color))
