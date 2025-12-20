_This project has been created as part of the 42 curriculum by addias._

## Description
This project consists of reimplment the function printf, using `<stdarg>` library for use variable arguments. This function support this kind of formats `%(c,s,d,i,u,p,x,X,%)`

## Instructions
Compile with standart flags(-Wall -Wextra -Werror) my `ft_printf.c` and  `ft_printf_utils.c`, or just use command make, for create `libftprintf.a` for compile with the main file, `CC ft_printf.c libftprintf.a` and compare the output of the original printf with my function.

## Resources
Various resources were used, including `GeeksForGeeks` and browser-based debuggers like `PythonTutor`.

### Algorithm Explanations
The printf function work traversing and printing the string that we put as the first parameter of the function, until we discover a `%` character and the next one is one of the format that our function support. And for identify this cases we use `ft_spec()`. Every single time we call function `ft_format()` we pass has parameter the current argument for we print and the format for this parameter. In format function we have multiples `if` for identify which is the current format. The return of `ft_format()` is always that number of characteres that we print from argument and that will be incremented in `total_len` variable (the return of `ft_printf()`) 
