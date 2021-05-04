#include "get_next_line.h"

int		new_line_check(char *s)
{
	int		loop;

	loop = 0;
	if (s == NULL)
		return (0);
	while (s[loop] != '\0')
	{
		if (s[loop] == '\n')
			return (1);
		loop++;
	}
	return (0);
}

char	*new_line_copy(char *s)
{
	char	*str;
	int		len;
	int		loop;

	len = 0;
	loop = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (loop < len)
	{
		str[loop] = s[loop];
		loop++;
	}
	str[loop] = '\0';
	return (str);
}

char	*fd_read(char **save_buf, int fd)
{
	char	*buf;
	ssize_t	read_len;

	read_len = 1;
	while (read_len > 0)
	{
		buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
		{
			free(save_buf[fd]);
			return (NULL);
		}
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(buf);
			free(save_buf[fd]);
			return (NULL);
		}
		buf[read_len] = 0;
		save_buf[fd] = ft_strjoin(save_buf[fd], buf);
		if (save_buf[fd] == NULL)
			return (NULL);
		if (new_line_check(save_buf[fd]))
			break ;
	}
	return (save_buf[fd]);
}

int		gnl_make_line(char **save_buf, char **line, int fd)
{
	int		loop;

	loop = 0;
	while (save_buf[fd][loop] != '\n' && save_buf[fd][loop] != '\0')
		loop++;
	if (save_buf[fd][loop] == '\n')
	{
		if(!(*line = new_line_copy(save_buf[fd])))
		{
			free(save_buf[fd]);
			return (-1);
		}
		save_buf[fd] = ft_strdup(ft_strchr(save_buf[fd], '\n') + 1);
		if (save_buf[fd] == NULL)
			return (-1);
		return (1);
	}
	*line = ft_strdup(save_buf[fd]);
	free(save_buf[fd]);
	if (*line == NULL)
		return (-1);
	save_buf[fd] = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save_buf[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0 )
		return (-1);
	if (save_buf[fd] == NULL)
		save_buf[fd] = ft_strdup("");
	if (save_buf[fd] == NULL)
		return (-1);
	save_buf[fd] = fd_read(save_buf, fd);
	if (save_buf[fd] == NULL)
		return (-1);
	return (gnl_make_line(save_buf, line, fd));
}