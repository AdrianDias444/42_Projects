*This project has been created as part of the 42 curriculum by addias, julidelg.*

# A-Maze-ing

## Description

A-Maze-ing is a terminal based maze generator written in Python. Given a configuration file, the program generates a random maze, optionally perfect (a single unique path between entry and exit), renders it visually in the terminal using ASCII art with ANSI colors, solves it using BFS, and exports the result to a hexadecimal output file.

A notable visual feature: mazes larger than 10×10 cells display the number **"42"** into the maze structure using fully closed cells.

**Key features:**
- Iterative DFS-based maze generation with optional imperfection (random wall breaks)
- BFS shortest-path solver
- Full terminal ASCII rendering with customizable wall colors
- Interactive menu: re-generate, toggle solution path, rotate colors
- Hexadecimal export format with entry, exit, and solution path
- Config file parser with full validation
- Reusable `MazeGenerator` class packaged as a pip-installable module

---

## Instructions

### Requirements

- Python 3.10 or later
- `make` (optional but recommended)
```
. mypy
. numpy
. pytest
. flake8
```

### Running the Program

```bash
make run
```

Or manually:

```bash
python3 a_maze_ing.py config.txt
```

### Makefile Targets

| Target | Description |
|--------|-------------|
| `make install` | Create virtualenv and install dependencies |
| `make run` | Run the program with `config.txt` |
| `make debug` | Run with Python's `pdb` debugger |
| `make clean` | Remove `__pycache__`, `.mypy_cache`, and virtualenv |
| `make lint` | Run `flake8` + `mypy` with standard flags |
| `make lint-strict` | Run `flake8` + `mypy --strict` |

---

## Configuration File Format

The configuration file contains one `KEY=VALUE` pair per line. Lines beginning with `#` are treated as comments and ignored. All six keys below are **mandatory**.

```
# Example config.txt
WIDTH=20
HEIGHT=15
ENTRY=0,0
EXIT=19,14
OUTPUT_FILE=maze.txt
PERFECT=True
```

| Key | Type | Description | Example |
|-----|------|-------------|---------|
| `WIDTH` | Integer ≥ 1 | Maze width in cells | `WIDTH=20` |
| `HEIGHT` | Integer ≥ 1 | Maze height in cells | `HEIGHT=15` |
| `ENTRY` | `x,y` | Entry cell coordinates | `ENTRY=0,0` |
| `EXIT` | `x,y` | Exit cell coordinates | `EXIT=19,14` |
| `OUTPUT_FILE` | `.txt` filename or only name, without extension| Path to the hex output file | `OUTPUT_FILE=maze.txt` |
| `PERFECT` | `True`/`False` | Whether the maze has a single solution | `PERFECT=True` |

**Validation rules enforced by the parser:**
- `WIDTH` and `HEIGHT` must be ≥ 1.
- `ENTRY` and `EXIT` must be different and within bounds.
- `OUTPUT_FILE` must end in `.txt`.
- No duplicate or unknown keys are allowed.
- Entry and exit cannot be placed inside the "42" decorative pattern.

---

## Maze Generation Algorithm

The project uses an **iterative DFS (Depth-First Search) with backtracking** and also **Breadth-First algorithm**.

**How it works:**
1. **Start** at the initial cell, mark it visited, and push it onto a stack.
2. **Check unvisited neighbors** of the currently cell.
3. **If neighbors exist**, randomly pick one, remove the wall between them and mark it visited.
4. **If no neighbors exist**, pop the stack to backtrack to the previous cell.
5. **Repeat** until every cell in the grid has been visited, then the maze is complete.

**Why this algorithm?**

- **Easy to implement iteratively** — avoids Python's recursion depth limit for large mazes.
- **Produces long, winding corridors** — aesthetically pleasing and challenging mazes.
- **Guarantees connectivity** — every cell is reachable, producing a valid perfect maze by default.
- **Imperfect mode** — after generation, two passes of random wall removal can create loops and multiple paths, controlled by the `PERFECT=False` flag.

---

## Output File Format

The output file stores one hexadecimal digit per cell. Each digit encodes which walls are **closed** as a 4-bit:

| Bit | Direction |
|-----|-----------|
| 0 (LSB) | North |
| 1 | East |
| 2 | South |
| 3 (MSB) | West |

A bit set to `1` means the wall is **closed**; `0` means **open**.

After the grid (one row per line), an empty line separates three additional lines:
1. Entry coordinates `(x, y)`
2. Exit coordinates `(x, y)`
3. Shortest path as a sequence of `N`, `E`, `S`, `W` characters

**Example output:**
```
FEDB...
...
(0, 0)
(19, 14)
EESSSENNE...
```

---

## Reusable Module

The maze generation logic is packaged as a standalone pip-installable Python module located at the root of the repository.

**Package name:** `mazegen-*` (e.g., `mazegen-1.0.0-py3-none-any.whl`)

### Installing the Package

```bash
pip install mazegen-1.0.0-py3-none-any.whl
```

### Basic Usage

```python
from mazegen import MazeGenerator


class Cell:
    def __init__(self, x: int, y:int):
        self.x = x
        self.y = y


class Config:
    def __init__(self, width:int, height:int, entry_cell:Cell, exit_cell:Cell, output_file: str, perfect:str):
        self.width = width
        self.height = height
        self.entry_cell = entry_cell
        self.exit_cell = exit_cell
        self.output_file = output_file
        self.perfect = perfect


config = Config(width, height, entry_cell, exit_cell, output_file, perfect)

gen = MazeGenerator(config)
gen.run()
```
You need to pass for Maze Generator a object instance from Config class that is defined with this six parameters that tou need to handle them with YOUR parser. Thx


**Interactive menu options:**

| Key | Action |
|-----|--------|
| `1` | Re-generate a new maze |
| `2` | Show / Hide the shortest solution path |
| `3` | Rotate wall colors (random palette each toggle) |
| `4` | Quit |

---

## Team & Project Management

### Team Members

| Member | Role |
|--------|------|
| `addias` | *maze generation, solving and rendering algorithm, initial project structure* |
| `julidelg` | *flake8, mypy, makefile, parser, documentation, structural organization and improvements, docstrings* |

### Planning

*In the beginning, we already had all planned out about what algorithm we'd use and how the functions and classes would be. It was a little weird to organize it into isolated modules for better reusability. Trying to understand how the Cells, grid and binary logic worked was very tricky, but we feel everything worked just like expected.*

### What Could Be Improved

Adding a supporte MLX rendering, multiple generation algorithms.

### Tools Used

- **Python 3.10+** — core language
- **flake8** — PEP 8 linting
- **mypy** — static type checking
- **AI assistance** — used to brainstorm algorithm structure and explore edge cases in the BFS solver; all generated code was reviewed.

---

## Resources

- [Maze generation algorithms — Wikipedia](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
- [Recursive backtracker explained — Jamis Buck's blog](https://weblog.jamisbuck.org/2010/12/27/maze-generation-recursive-backtracking)
- [Python `collections.deque` — official docs](https://docs.python.org/3/library/collections.html#collections.deque)
- [ANSI escape codes reference](https://en.wikipedia.org/wiki/ANSI_escape_code)
- [PEP 257 — Docstring conventions](https://peps.python.org/pep-0257/)

**AI usage:** AI tools were used to assist with documentation drafting, exploring edge cases in the maze validation logic, and reviewing the BFS implementation. All output was critically reviewed and validated against the subject requirements and tested manually.