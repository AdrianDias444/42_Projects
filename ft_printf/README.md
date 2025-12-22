# ft_printf

_This project has been created as part of the 42 curriculum by addias._

## Description

This project consists of reimplementing the `printf` function, using the `<stdarg.h>` library to handle variable arguments.

The function supports the following format specifiers:

- `%c`
- `%s`
- `%d`
- `%i`
- `%u`
- `%p`
- `%x`
- `%X`
- `%%`

## Instructions

To compile, use the standard flags:

-Wall -Wextra -Werror

with the source files:

- `ft_printf.c`
- `ft_printf_utils.c`

Alternatively, run:

make

to create the static library `libftprintf.a`.

To compile with a main file, use:

cc `ft_printf.c` `libftprintf.a`

## Resources

Various resources were used, including GeeksForGeeks and browser-based debuggers like PythonTutor.

## Algorithm Explanation

The printf function works by traversing and printing the string passed as the first parameter until it encounters a % character, followed by one of the supported format specifiers.

To identify these cases, we use `ft_spec()`.

Each time we call `ft_format()`, we pass the current argument and its corresponding format specifier as parameters. Inside `ft_format()`, multiple if statements determine the current format.

The return value of `ft_format()` is always the number of characters printed from the argument, which is then added to the `total_len` variable — the final return value of `ft_printf()`.

### Variadic Arguments Handling

To manage variable arguments, the `<stdarg.h>` library provides three essential macros:

- **`va_start`**: Initializes a `va_list` variable to point to the first optional argument passed to the function. It must be called before accessing any optional arguments.
  
- **`va_arg`**: Retrieves the next argument from the `va_list` of a specified type. Each call advances the `va_list` pointer to the next argument.

- **`va_end`**: Cleans up the `va_list` variable after all arguments have been accessed. It should be called before the function returns.

These functions allow to process an unknown number of arguments dynamically, based on the format specifiers encountered in the format string.
