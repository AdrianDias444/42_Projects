#include "../header.h"

t_node *ft_to_stackA(int n, int i, t_node *prev)
{
    t_node *stackA;

    stackA = malloc(sizeof(t_node));
    if(!stackA)
        return(NULL);

    stackA -> nb = n;
    stackA -> index = i;
    stackA -> final_index = 0;
    stackA -> next = NULL;
    
    if(prev != NULL)
        prev->next = stackA;
    return(stackA);
}