
#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  10
#endif  

# include <unistd.h>
# include <limits.h>

char *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int	ft_strlen(const char *str);
char	*ft_strdup(const char *src);

#endif
