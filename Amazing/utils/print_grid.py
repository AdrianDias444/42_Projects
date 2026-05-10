from config import Cell, Grid

"""def print_grid(grid: Grid):

    print("┌", end="")
    for row in grid.grid:
        if not (row == grid.grid[0] or row == grid.grid[grid.height - 1]):
            print("┃", end="")
        for cell in row:
            if cell.y == 0:
                print("━━", end="")
                continue
            if cell.walls["left"]:
                print("┃", end="")
            print(" ", end="")
        if not row == grid.grid[grid.height - 1]:
            print()

    print("└")
"""


def print_grid(grid: Grid, caminho):
    for row in grid.grid:
        # LINHA TOP
        for cell in row:
            if cell.walls["top"]:
                print("+---", end="")
            else:
                print("+   ", end="")
            last_cell = cell
        print("+")

        # LINHA MID
        for cell in row:
            if cell.walls["left"]:
                if cell == grid.entry_cell:
                    print("| E ", end="")
                elif cell == grid.exit_cell:
                    print("|Exi", end="")
                elif cell.logo:
                    print("|###", end="")
                elif cell in caminho:
                    print("| . ", end="")
                    # elif cell in extensao:
                    # print("| ? ", end="")

                else:
                    print("|   ", end="")
            else:
                if cell == grid.entry_cell:
                    print("  E ", end="")
                elif cell == grid.exit_cell:
                    print(" Exi", end="")
                elif cell.logo:
                    print("####", end="")
                elif cell in caminho:
                    print(" .  ", end="")
                    # elif cell in extensao:
                    # print(" ?  ", end="")

                else:
                    print("    ", end="")
            last_cell = cell
        if last_cell.walls["right"]:
            print("|")
        else:
            print(" ")

    for cell in grid.grid[-1]:
        print("+---" if cell.walls["bottom"] else "+   ", end="")
    print("+")
