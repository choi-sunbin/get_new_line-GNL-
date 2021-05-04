#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_read_fd(char **temp, int fd, ssize_t ret);
int		get_next_line(int fd, char **line);
int		ft_check_fd(char *s);
int		ft_make_line(char **temp, char **line, int fd);
size_t	ft_strlcat(char *dest, char *src, size_t size);

#endif