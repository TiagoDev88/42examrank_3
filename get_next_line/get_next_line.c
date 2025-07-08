#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	char *new = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char *rd_ln(char *s)
{
	int i = 0;
	int j = 0;

	while(s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	char *new = malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	while (j < i)
	{
		new[j] = s[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char *up_ln(char *s)
{
	int i = 0;
	int j = 0;

	while(s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	int len = ft_strlen(s);
	char *new = malloc(sizeof(char) * (len - i) + 1);
	if (!new)
		return (free(s), NULL);
	while (i < len)
	{
		new[j] = s[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(s);
	return (new);
}

int ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char *stash;
	int rdbytes = 1;
	char *tmp;
	char *line;
	char *buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while(!ft_strchr(stash, '\n') && rdbytes > 0)
	{
		rdbytes = read(fd, buf, BUFFER_SIZE);
		if (rdbytes < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		if (rdbytes == 0)
			break;
		buf[rdbytes] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
		{
			free(buf);
			free(tmp);
			return (NULL);
		}
		stash = tmp;
	}
	free(buf);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = rd_ln(stash);
	stash = up_ln(stash);
	return (line);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int fd = open("t.txt", O_RDONLY);

// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// char *s = readline("ola");
// 	// printf("%s\n", s);
// }