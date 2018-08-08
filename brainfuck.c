/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glatega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:14:15 by glatega           #+#    #+#             */
/*   Updated: 2018/08/08 20:17:02 by glatega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	brainfuck(char *str)
{
	char	*ptr;
	int		i;

	ptr = (char*)malloc(sizeof(char) * 2048);
	i = 0;
	while (i < 2048)
		ptr[i++] = 0;
	i = 0;
	while (*str)
	{
		*ptr += *str == '+' ? 1 : 0;
		*ptr -= *str == '-' ? 1 : 0;
		ptr += *str == '>' ? 1 : 0;
		ptr -= *str == '<' ? 1 : 0;
		if (*str == ']')
		{
			i = 1;
			while (i != 0)
			{
				str--;
				if (*str == ']')
					i++;
				if (*str == '[')
					i--;
			}
		}
		if (*str == '[' && !*ptr)
		{
            i = 1;
            while (i != 0)
            {
				str++;
                if (*str == '[')
                    i++;
                if (*str == ']')
                    i--;
            }
		}
		if (*str == '.')
			write(1, ptr, 1);
		str++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
