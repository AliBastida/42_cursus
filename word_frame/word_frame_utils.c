#include "word_frame.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}


char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scp;

	len = ft_strlen(s1);
	scp = malloc(sizeof(char) * (len + 1));
	if (scp)
	{
		ft_memcpy(scp, s1, len + 1);
		return (scp);
	}
	return (NULL);
	free(scp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	i++;
	return (i);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize != 0)
	{
		while ((src[i] != '\0') && (i < (dstsize -1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	slen;

	slen = ft_strlen (s);
	if ((slen == 0) || (slen < start))
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	else if (len > slen - start)
		len = slen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)(s + start), len + 1);
	return (ptr);
}


int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && ((s[i + 1] == '\0') || (s[i + 1] == c)))
			word++;
	}
	return (word);
}

int	ft_strlenchar(const char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	return (i);
}

char	**ft_free(char **matrix)
{
	int	contador;

	contador = -1;
	if (!matrix)
		return (NULL);
	while (matrix[++contador])
		free (matrix[contador]);
	free (matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		n_word;
	int		len;
	int		i;
	char	**matrix;

	matrix = (char **) malloc (sizeof (char *) * (count_word(s, c) + 1));
	if (!matrix)
		return (NULL);
	i = -1;
	n_word = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_strlenchar(&s[i], c);
			matrix[n_word] = ft_substr(&s[i], 0, len);
			if (!matrix[n_word])
				return (ft_free (matrix));
			n_word++;
			i = i + len - 1;
		}
	}
	matrix[n_word] = NULL;
	return (matrix);
}
