/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:06:01 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 23:02:54 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "useful_functions.h"
#include "read_file.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**dict_one;
	char	**dict_two;
	char	**dict_three;
	char	*whole_dict;

	i = 0;
	if (argc == 2)
	{
		whole_dict = read_dictionary_file();
		if (!whole_dict)
			return (1);
		dict_one = create_dict(whole_dict, 0, 19);
		dict_two = create_dict(whole_dict, 19, 8);
		dict_three = create_dict(whole_dict, 27, 13);
		// while (i < 13)
		// {
		// 	printf("%s\n", dict_three[i]);
		// 	i++;
		// }
		parse(argv[1], dict_one, dict_two, dict_three);
		free(whole_dict);
		free(dict_one);
		free(dict_two);
		free(dict_three);
	}
	return (0);
}