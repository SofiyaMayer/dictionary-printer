/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:39:11 by someyer           #+#    #+#             */
/*   Updated: 2025/08/24 14:39:12 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*divide_dictionary(char *file);
char	*add_word_to_dict(char *file, char *dict);
char	**make_dictionary(char *file, int size);
char	*get_word(char *file);
void	print_word(char *file);