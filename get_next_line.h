/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:33:05 by ameteori          #+#    #+#             */
/*   Updated: 2022/01/20 16:21:56 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1 

size_t		ft_strlen(const char *str);
char		*ft_strchr1(const char *ostatok, char c);
char		*ft_strjoin1(char *ostatok, char *buff);
char		*ft_dup_line(char *ostatok);
char		*new_ost(char *ostatok);
char		*read_ostatok(int fd, char *ostatok);
char		*get_next_line(int fd);

#endif