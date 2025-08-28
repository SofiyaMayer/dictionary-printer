/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:20:41 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 22:53:14 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_functions.h"
#include "core_functions.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	count_file_size(int fd)
{
	char	buffer[1];
	int		total_bytes;
	int		bytes_read;

	total_bytes = 0;
	bytes_read = read(fd, buffer, 1);
	while (bytes_read > 0)
	{
		total_bytes++;
		bytes_read = read(fd, buffer, 1);
	}
	return (total_bytes);
}

char	*read_dictionary_file(void)
{
	int		fd;
	int		file_size;
	char	*whole_dict;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_size = count_file_size(fd);
	close(fd);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);
	whole_dict = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!whole_dict)
	{
		close(fd);
		return (NULL);
	}
	read(fd, whole_dict, file_size);
	whole_dict[file_size] = '\0';
	close(fd);
	return (whole_dict);
}
