#include "get_next_line.h"

char	*read_file(int fd, char *storage)
{
	char	*buf;
	int		bytes_read;

	if (ft_strchr(storage, '\n'))
		return (storage);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(storage), NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), free(storage), NULL);

		if (bytes_read == 0)
			break ; 
		buf[bytes_read] = '\0';
		storage = ft_strjoin(storage, buf);
		if (!storage)
			return (free(buf), NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (storage);
}

char *extract_line(char *storage)
{
    size_t i;

    i = 0;
    if (!storage || !storage[i])
        return (NULL);
    while (storage[i] && storage[i] != '\n')
        i++;
    if (storage[i] == '\n')
        i++;
    return(ft_substr(storage, 0, i));
}

char *ft_clean(char *storage)
{
    size_t i;
    char *rest;
    
    i = 0;
    if (!storage)
        return (NULL);
    while (storage[i] && storage[i] != '\n')
        i++;
    if (!storage[i])
    {
        free(storage);
        return (NULL);
    }
    rest = ft_substr(storage, i + 1, ft_strlen(storage) - i);
    free(storage);
    return(rest);
}

char *get_next_line(int fd)
{
    static char *storage;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    storage = read_file(fd, storage);
    if (!storage)
        return (NULL);
    line = extract_line(storage);
    if (!line)
    {
        free(storage);
        storage = NULL;
        return (NULL);    
        }
    storage = ft_clean(storage);
    return (line);
}