#include "../header.h"

int ft_is_a_string(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == ' ')
            return (0);
        i++;
    }
    return (1);
}