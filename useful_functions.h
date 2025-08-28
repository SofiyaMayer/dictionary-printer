/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:04:17 by roiskusn          #+#    #+#             */
/*   Updated: 2025/08/24 22:17:28 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *string);
int		num_len(int number);
void	ft_putstr(char *string);
char	*get_the_line(char *string, char *input);
char	*skip_n_new_lines(char *string, int n);
char	*divide_dictionary(char *file);
char	*add_word_to_dict(char *file, char *dict);
char	**make_dictionary(char *file, int size);
char	*get_word(char *file);
void	print_word(char *file);
char	**create_dict(char *file, int n_new_lines, int size);
int		count_file_size(int fd);