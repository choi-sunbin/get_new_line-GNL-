#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *dest, int check);
char	*ft_strdup(char *s);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		new_line_check(char *s);
char	*new_line_copy(char *s);
char	*fd_read(char **save_buf, int fd);
int		gnl_make_line(char **save_buf, char **line, int fd);
int		get_next_line(int fd, char **line);

#endif