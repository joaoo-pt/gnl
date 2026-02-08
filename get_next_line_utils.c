#include "get_next_line.h"


size_t ft_strlen(char *str)
{
    size_t len;

    len = 0;    
    if (!str)
        return 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strchr(char *str, int c)
{
    if (!str)
        return NULL;
    while (*str)
    {
        if (*str == (char)c)
            return ((char *)str);
        str++;
    }
    if (*str == (char)c)
        return ((char *)str);
    return NULL;
}

char *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;
    char *join;

    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!join)
        return (free(s1), NULL);
    i = -1;
    while (s1[++i])
        join[i] = s1[i];
    j = 0;
    while (s2[j])
        join[i++] = s2[j++];
    join[i] = '\0';
    return (free(s1), join);
}

char *ft_substr(char *str, unsigned int start, size_t len)
{
    char	*s;
	size_t	i;
	size_t	s_len;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		s[i] = str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char *ft_strdup(char *s)
{
    char *dest;
    size_t i;

    dest = malloc(ft_strlen((char *)s) + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (s[i])
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
