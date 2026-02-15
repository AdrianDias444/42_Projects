/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:38 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:26:47 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_put_arg_in_stack(int nb, char**argv, t_stack *stack_A, int i)
{
	t_node	*current;

	nb = ft_atoi(argv[i]);
	current = ft_create_node(nb);
	ft_stack_push_back(stack_A, current);
	return (1);
}

void	ft_free_mat(char **mat)
{
	int	j;

	j = 0;
	while (mat[j])
	{
		free(mat[j]);
		j++;
	}
}

void	ft_parser(int argc, char **argv, t_stack *stack_A)
{
	int			i;
	int			j;
	long long	nb;
	char		**mat;

	i = 1;
	nb = 0;
	while (i < argc)
	{
		j = 0;
		if (ft_is_a_string(argv[i]) == 0)
		{
			mat = ft_split(argv[i], ' ');
			while (mat[j])
				j += ft_put_arg_in_stack(nb, mat, stack_A, j);
			ft_free_mat(mat);
		}
		else
			ft_put_arg_in_stack(nb, argv, stack_A, i);
		i++;
	}
}
