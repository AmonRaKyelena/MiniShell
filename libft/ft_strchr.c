

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cc;

	if (s == NULL)
		return (NULL);
	cc = (unsigned char)c;
	i = 0;
	while (s[i])
		if (s[i++] == cc)
			return ((char *)&s[--i]);
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}
