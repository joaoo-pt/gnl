#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// utils
size_t ft_strlen(char *str);
char *ft_strchr(char *str, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char *str, unsigned int start, size_t len);
char *ft_strdup(char *s);

// gnl
char *get_next_line(int fd);
char *read_file(int fd, char *storage);
char *extract_line(char *storage);
char *ft_clean(char *storage);

#endif