#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

void	test_roundpow2(void);
void	test_strncpy(void);
void	test_resize_line(void);
void	test_resize_if_necessary(void);
void	test_init_if_necessary(void);
void	test_append_from_stream(void);
void	test_is_eol(void);
void	test_chunk_size(void);

#endif