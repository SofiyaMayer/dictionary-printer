/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:07:32 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 22:47:33 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *string)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (string[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int	num_len(int number)
{
	int	len;

	len = 0;
	while (number /= 10 != 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

//new line detection, after new line add counter.
char	*skip_n_new_lines(char *string, int n)
{
	int	counter;

	counter = 0;
	while (counter < n)
	{
		if (*string == '\n')
			counter++;
		string++;
	}
	return (string);
}

void	ft_putstr(char *string)
{
	int	len;

	len = ft_strlen(string);
	write (1, string, len);
	write (1, "\n", 1);
}

// // find the exact word. Should have the length
// char	*get_the_line(char *string, char *input)
// {
// 	int	i;
// 	int	lines_count;
// 	int	length;
// 	char	*word;

// 	i = 0;
// 	lines_count = 0;
// 	length = ft_strlen(input);

// 	// 0-9
// 	if (length == 1)
// 	{
// 		//*input - '0'
// 		skip_n_new_lines(string, *input - '0');
// 		// read the word on this line
		
// 	}
// 	// 10-19
// 	if (length == 2 && *input == '1')
// 	{
// 		// go to the line 10 + (*input - '0')
// 		skip_n_new_lines(string, 10);
// 		input++;
// 		skip_n_new_lines(string, *input - '0');
// 		// read the word on this line
		
// 	}
// 	// {20, 30, .., 90}
// 	if (length == 2 && *input != '1')
// 	{
// 		skip_n_new_lines(string, 20 + (*input - '2'));
// 		// read the word from this line
// 		input++;
// 		if (*input != '0')
// 		{
// 			// print a word at position (*input - '0') from dict {0, 1, .., 9}
// 		}
// 	}
// 	if (length == 3)
// 	{
// 		if (*input != '0')
// 		{
// 			// print a word at position (*input - '0') from dict {0, 1, .., 9}
// 			// print word at position corresponding to number '100'
// 			input++;
// 			if (*input == '0')
// 			{
// 				input++;
// 				// print a word at position (*input - '0') from dict {0, 1, ..., 9}
// 				// return ;
// 			}
// 			if (*input == '1')
// 			{
// 				input++;
// 				// print a word at position (*input - '0') from dict {10, 11, .., 19}
// 				// return ;
// 			}
// 			// print a word at position (*input - '2') from dict {20, 30, .., 90}
// 			input++;
// 			if (*input != '0')
// 			{
// 				// print a word at position (*input - '0') from dict {0, 1, .., 9}
// 			}
// 		}
// 		// go to the line 29 to look for "hundred", after that get length -1 and *string++;
// 		// and check the condition abo20)ve. Starts to remind recursion pattern.
// 	}
// 	// while new lines are not same as length
// 	while (lines_count < length)
// 	{
// 		if (string[i] == '\n')
// 			lines_count++;
// 		i++;// string++;
// 	}
// 	return (string);
// }

// // // test
// // int main(void)
// // {
// // 	ft_putstr("Bugaga");
// // }
