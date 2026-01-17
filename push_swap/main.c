#include "header.h"


int main()
{
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;
    t_node *fourth_node;
    t_node *fifth_node;
    t_node *sixth_node;
    t_node *seven_node;
    t_node *eight_node;

    t_stack stack_A;
    t_stack stack_B;

    ft_stack_init(&stack_A);
    ft_stack_init(&stack_B);

    first_node = ft_create_node(5);
    second_node = ft_create_node(1);
    third_node = ft_create_node(13);
    fourth_node = ft_create_node(2);

    fifth_node = ft_create_node(9);
    sixth_node = ft_create_node(21);
    seven_node = ft_create_node(6);
    eight_node = ft_create_node(3);


    ft_stack_push_back(&stack_A, first_node);
    ft_stack_push_back(&stack_A, second_node);
    ft_stack_push_back(&stack_A, third_node);
    ft_stack_push_back(&stack_A, fourth_node);

    ft_stack_push_back(&stack_B, sixth_node);
    ft_stack_push_back(&stack_B, fifth_node);
    ft_stack_push_back(&stack_B, seven_node);
    ft_stack_push_back(&stack_B, eight_node);

    printf("\nStack A\n");
    ft_print_stack(&stack_A);

    printf("\nStack B\n");
    ft_print_stack(&stack_B);

    printf("\nFind place is %d", ft_find_place(&stack_B, second_node));

}