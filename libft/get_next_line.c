/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:13 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/15 12:09:28 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_str_length(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*error_str_line(char *s1, char *s2)
{
	char	*str;

	if (!s1 && s2)
	{
		str = ft_str_duplicate(s2);
		return (str);
	}
	else if (!s2 && s1)
	{
		str = ft_str_duplicate(s1);
		return (str);
	}
	return (NULL);
}

char	*ft_str_line(char *s1, char *s2)
{
	char	*str1;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (error_str_line(s1, s2));
	str1 = malloc(sizeof(char) * (ft_str_length(s1) + ft_str_length(s2)) + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str1[i] = s2[j];
		j++;
		i++;
	}
	if (s2[j] == '\n' && s2[j] != '\0')
		str1[i++] = s2[j++];
	return (str1[i] = '\0', str1);
}

char	*ft_str_duplicate(char *source)
{
	char	*dest;
	char	*src2;
	int		i;

	i = 0;
	src2 = (char *)source;
	dest = malloc(sizeof(char) * ft_str_length(source) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		dest[i] = src2[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*for_next_buffer(char *check)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check[i] != '\n' && check[i] != '\0')
		i++;
	if (check[i] == '\n')
		i++;
	while (check[i] != '\0')
	{
		check[j] = check[i];
		i++;
		j++;
	}
	check[j] = '\0';
	return (check);
}

int	check_if_n_inline(char *check)
{
	int	i;

	i = 0;
	while (check[i] != '\0')
	{
		if (check[i] == '\n')
			return (-1);
		i++;
	}
	return (1);
}

char	*free_stock(char *line, char *buffer)
{
	char	*stock;

	stock = NULL;
	if (!line)
		line = ft_str_duplicate("");
	stock = ft_str_duplicate(line);
	free(line);
	line = ft_str_line(stock, buffer);
	free(stock);
	return (line);
}

char	*reader_loop(ssize_t reader, int fd, char *buffer, char *line)
{
	while (reader > 0)
	{
		if (buffer[0] == '\0')
		{
			reader = read(fd, buffer, BUFFER_SIZE);
			buffer[reader] = '\0';
		}
		if (reader == 0 && buffer[0] == '\0')
			return (line);
		if (reader == -1)
			return (NULL);
		line = free_stock(line, buffer);
		if (!line || line[0] == '\0')
			return (free(line), line);
		if (check_if_n_inline(line) == -1)
			return (for_next_buffer(buffer), line);
		for_next_buffer(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*line;
	ssize_t		reader;

	line = NULL;
	reader = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = reader_loop(reader, fd, buffer, line);
	return (line);
}

// int main(void)
// {
// 	char *line;
// 	//
// 	/////////// text.txt /////////////////
// 	//
// 	char	*file = "tesxt.txt";
// 	int		fd = open(file, O_RDWR);
// 	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	close (fd);
// }

// int	main(void)
// {
// 	char *line;
// 	int i = 0;
// 	//
// 	/////////// text.txt /////////////////
// 	//
// 	char	*file = "test.txt";
// 	int		fd = open(file, O_RDWR);
// 	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 		free (line);
// 		i++;
// 	}
// 	printf("\ni : %d\n", i);
// 	close (fd);
// }
