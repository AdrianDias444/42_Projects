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

- ft_printf.c
- ft_printf_utils.c

Alternatively, run:

make

to create the static library `libftprintf.a`.

To compile with a main file, use:

cc main.c libftprintf.a

## Resources

Various resources were used, including GeeksForGeeks and browser-based debuggers like PythonTutor.

## Algorithm Explanation

The printf function works by traversing and printing the string passed as the first parameter until it encounters a % character, followed by one of the supported format specifiers.

To identify these cases, we use ft_spec().

Each time we call ft_format(), we pass the current argument and its corresponding format specifier as parameters. Inside ft_format(), multiple if statements determine the current format.

The return value of ft_format() is always the number of characters printed from the argument, which is then added to the total_len variable — the final return value of ft_printf().
