from config import Cell, Grid

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
                    print("|Ent", end="")
                elif cell == grid.exit_cell:
                    print("|Exi", end="")
                elif cell.logo:
                    print("|###", end="")
                elif cell in caminho:
                    print("| . ", end="")
                else:
                    print("|   ", end="")
            else:
                if cell == grid.entry_cell:
                    print(" Ent", end="")
                elif cell == grid.exit_cell:
                    print(" Exi", end="")
                elif cell.logo:
                    print("####", end="")
                elif cell in caminho:
                    print("  . ", end="")
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
