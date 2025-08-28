/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:03:55 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 23:01:36 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "useful_functions.h"

void	print_word(char *file)
{
	int	i;

	i = 0;
	file = get_word(file);
	while (file[i] != '\n' && file[i] != '\0')
	{
		write (1, &file[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

/*	Function to get pointer on the next word from file.
	It skips all unnessecary chars before word (including ':').	*/
char	*get_word(char *file)
{
	int	i;

	i = 0;
	while (*file != ':')
	{
		file++;
	}
	while (!(*file >= 'a' && *file <= 'z')
			|| (*file >= 'A' && *file <= 'Z'))
	{
		file++;
	}
	return (file);
}

// previous version of make_dictionary
char	*divide_dictionary(char *file)
{
	int		i;
	int		counter;
	char	*dict_until_nineteen;

	i = 0;
	counter = 0;
	while (counter < 20)
	{
		if (file[i] == '\n')
			counter++;
		i++;
	}
	dict_until_nineteen = (char *)malloc(sizeof(char) * (i + 1));
	if (!dict_until_nineteen)
		return (NULL);
	counter = 0;
	while (counter < i)
	{
		dict_until_nineteen[counter] = file[counter];
		counter++;
	}
	dict_until_nineteen[i] = '\0';
	return (dict_until_nineteen);
}

/* 	Function to add a word from file to dictionary.
	Used in function make_dicitonary(char *file, int size). */
char	*add_word_to_dict(char *file, char *dict)
{
	int	i;

	i = 0;
	file = get_word(file);
	while (file[i] != '\n' && file[i] != '\0')
	{
		dict[i] = file[i];
		i++;
	}
	return (dict);
}

/* Function to make a dictionary (2D array) of certain size */
char	**make_dictionary(char *file, int size)
{
	char	**dict;
	int		i;
	int		counter;

	i = 0;
	dict = (char **)malloc(size * sizeof(char *));
	while (i < size)
	{
		dict[i] = (char *)malloc(10 * sizeof(char));
		i++;
	}
	counter = 0;
	while (counter < size)
	{
		add_word_to_dict(get_word(file), dict[counter]);
		file = skip_n_new_lines(file, 1);
		counter++;
	}
	return (dict);
}
