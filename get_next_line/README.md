*This project has been created as part of the 42 curriculum by addias.*

## Description
This project consists of returning the next line of a file, reading from its file descriptor. If the function is called multiple times, `get_next_line()` saves the reading state from the last call.

## Instructions
Compile with standard flags (`-Wall -Wextra -Werror`) and optionally define `-D BUFFER_SIZE=n`, or modify the buffer size directly in `get_next_line.h`.

## Resources
Various resources were used, including GeeksForGeeks and browser-based debuggers like PythonTutor. AI was used in specific parts, such as determining where to free variables.

## Algorithm Explanation

### Overview
`get_next_line()` performs error handling (invalid fd or BUFFER SIZE). It relies on three auxiliary functions:

1. **`read_newline()`** – traverses the buffer according to BUFFER SIZE until a newline is found.
2. **`extract_line()`** – extracts only the relevant portion up to the newline.
3. **`clean_old_stack()`** – manages the static variable so it persists correctly across multiple calls.
