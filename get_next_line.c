/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:43:41 by jcavadas          #+#    #+#             */
/*   Updated: 2024/04/17 14:27:12 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_from_fd(int fd, char **stash, char buffer)
{
	int	bytes;
	
	bytes = read(fd, buffer, BUFFER_SIZE);

}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(stash, '/n') == NULL && bytes > 0)
		bytes = read_from_fd(fd, &stash, buffer);
	free(buffer);
	/*
	vai estar a dar read do fd para o buffer, e vai passando para a stash (variavel estatica). vai ao mesmo tempo verificando se tem um /n no stash 
	so precisa de estar a ir fazendo isto uma vez pois quando ele tiver um /n ja tem a linha para sair 
	a funcao que vai ter la o read vai devolver o que o read devolve, que e um int, por isso depois vai se ter de verificar se devolveu -1 (erro do read) 
	*/

}
