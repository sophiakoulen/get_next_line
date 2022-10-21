#include "get_next_line.h"

int		gnl_ispow2(unsigned int n)
{
	return (!(n & (n - 1)));
}

void	gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (!dst && !src)
		return ;
	p_dst = dst;
	p_src = src;
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
}

void	*gnl_realloc(void *ptr, size_t s)
{
	void	*new_ptr;

	new_ptr = malloc(s);
	if (!new_ptr)
		return (0);
	if (ptr)
	{
		gnl_memcpy(new_ptr, ptr, s);
		free(ptr);
	}
	return (new_ptr);
}