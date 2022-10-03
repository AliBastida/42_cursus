#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef WORD_FRAME_H
#define WORD_FRAME_H

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		count_word(char const *s, char c);
int		ft_strlenchar(const char *s, char c);
char	**ft_free(char **matrix);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
