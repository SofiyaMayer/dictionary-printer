/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:19:17 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 23:22:31 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_functions.h"
#include "core_functions.h"

char	**create_dict(char *file, int first_line, int size)
{
	char	**dict;

	if (first_line > 0)
	{
		file = skip_n_new_lines(file, first_line);
		file = divide_dictionary(file);
	}
	dict = make_dictionary(file, size);
	return (dict);
}
