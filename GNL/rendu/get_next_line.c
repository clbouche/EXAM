#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen(char *line)
{
	int len = 0;
	while(line[len])
		len++;
	return (len);
}

char	*ft_copy(char *str, int rd)
{
	char *line;
	int i = 0;
	if (!(line = malloc(sizeof(char) * rd + 1)))
		return (NULL);
	while (i < rd)
	{
		line[i] = str[i];
		if (line[i] == '\n')
		{
			line[i + 1] = '\0';
			return (line);
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_memmove(char *s1, char *s2, int len)
{
	int i = 0;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
}

char 	*ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len1 = 0;
	int len2 = 0;
	char *line;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	if (!(line = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		line[i] = s1[i];
		i++;
	}
	while(j < len2)
	{
		line[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	line[i + j] = '\0';
	return (line);

}

void	fill_zero(char *str)
{
	int i = 0;
	while (i < BUFFER_SIZE)
		str[i++] = '\0';
}

char	*get_next_line(int fd)
{
	int rd;
	int len = 0;
	char *line;
	char *tmp = NULL;
	static char buf[BUFFER_SIZE];
	static int	rest = 0;

	if (rest != 0)
	{
		tmp = ft_copy(buf, rest);
		len = ft_strlen(tmp);
		rest = rest - len;
		ft_memmove(buf, buf + len, rest);
	}
	if (rest == 0)
	{
		fill_zero(buf);
		if ((rd = read(fd, buf, BUFFER_SIZE)) < 1)
            return tmp;
		line = ft_copy(buf, rd);
		len = ft_strlen(line);
		rest = rd - len;
		ft_memmove(buf, buf + len, rest);
		line = ft_strjoin(tmp, line);
		return(line);
	}
	return (tmp);
}

int	main(void)
{
	char	*line;
	int fd = open("file", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("read : %s\n", line);
		free(line);
	}
    printf("read 2 : %s\n", line);
	free(line);
    close (fd);
	return (EXIT_SUCCESS);
}
