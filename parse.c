/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:08:26 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 23:39:14 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "useful_functions.h"

void	ft_putstr_no_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_triple(char *triple, char **dict0, char **dict20, char **dict100)
{
	if (triple[0] != '0' || triple[1] != '0' || triple[2] != '0')
	{
		if (triple[0] != '0')
		{
			ft_putstr_no_newline(dict0[triple[0] - '0' - 1]);
			write(1, " ", 1);
			ft_putstr_no_newline(dict100[0]);
			if (triple[1] != '0' || triple[2] != '0')
				write(1, " ", 1);
		}
		if (triple[1] == '0' && triple[2] != '0')
			ft_putstr_no_newline(dict0[triple[2] - '0' - 1]);
		else if (triple[1] == '1')
			ft_putstr_no_newline(dict0[10 + triple[2] - '0' - 1]);
		else if (triple[1] != '0')
		{
			ft_putstr_no_newline(dict20[triple[1] - '2']);
			if (triple[2] != '0')
			{
				write(1, " ", 1);
				ft_putstr_no_newline(dict0[triple[2] - '0' - 1]);
			}
		}
	}
}

void	copy_triple(char *input, char *triple, int i)
{
	int	len;

	len = ft_strlen(input);
	if (i == 0 && len % 3 == 1)
	{
		triple[0] = '0';
		triple[1] = '0';
		triple[2] = input[i];
	}
	else if (i == 0 && len % 3 == 2)
	{
		triple[0] = '0';
		triple[1] = input[i];
		triple[2] = input[i + 1];
	}
	else
	{
		if (i < len)
			triple[0] = input[i];
		else
			triple[0] = '0';
		if (i + 1 < len)
			triple[1] = input[i + 1];
		else
			triple[1] = '0';
		if (i + 2 < len)
			triple[2] = input[i + 2];
		else
			triple[2] = '0';
	}
}

int	calculate_next_position(int i, int flag, int length)
{
	if ((flag == 0) && (length % 3 != 0))
		return (i + (length % 3));
	else
		return (i + 3);
}

int	check_digits(int length, char *input, char **dict0)
{
	int	numbertriple;

	(void)dict0;  // Suppress unused parameter warning
	if (length == 1 && input[0] == '0')
	{
		write(1, "zero", 4);
		return (0);
	}
	if (length % 3 == 0)
		numbertriple = length / 3 - 1;
	else
		numbertriple = length / 3;
	return (numbertriple);
}

void	process_triple_group(char *input, char **dict0, char **dict20, char **dict100, int *i, int *has_printed, int numbertriple, int flag, int length)
{
	char	triple[3];

	copy_triple(input, triple, *i);
	if (triple[0] != '0' || triple[1] != '0' || triple[2] != '0')
	{
		if (*has_printed)
			write(1, " ", 1);
		print_triple(triple, dict0, dict20, dict100);
		if (numbertriple > 0)
		{
			write(1, " ", 1);
			ft_putstr_no_newline(dict100[numbertriple]);
		}
		*has_printed = 1;
	}
	*i = calculate_next_position(*i, flag, length);
}

void	parse(char *input, char **dict0, char **dict20, char **dict100)
{
	int		i;
	int		length;
	int		numbertriple;
	char	triple[3];
	int		has_printed;

	i = 0;
	has_printed = 0;
	length = ft_strlen(input);
	numbertriple = check_digits(length, input, dict0);
	while (numbertriple > 0)
	{
		process_triple_group(input, dict0, dict20, dict100, &i, &has_printed, numbertriple, (i > 0), length);
		numbertriple--;
	}
	copy_triple(input, triple, i);
	if (triple[0] != '0' || triple[1] != '0' || triple[2] != '0')
	{
		if (has_printed)
			write(1, " ", 1);
		print_triple(triple, dict0, dict20, dict100);
	}
	write(1, "\n", 1);
}
