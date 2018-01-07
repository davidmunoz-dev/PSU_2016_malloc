/*
** malloc_tester.h for  in /home/hazer/Documents/tek2/Unix/PSU_2016_malloc/test_proj
**
** Made by hazer
** Login   <david.munoz@epitech.eu>
**
** Started on  Fri Feb  3 12:56:06 2017 hazer
** Last update Fri Feb 10 14:22:44 2017 hazer
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

extern void	*first_fit;

typedef struct __attribute__((__packed__))	s_block
{
  size_t                size;
  struct s_block	*next;
  struct s_block	*prev;
  int                   free;
  char                  data[1];
  void			*ptr_free;
}						t_block;

#define BLOCK_SIZE sizeof(t_block)
#define MALLOC_OK	0
#define	MALLOC_DIFF	1
#define	MALLOC_ERR	-1

/*		free.c		*/
t_block	*get_block(void *ptr);
int	valid_addr(void *ptr);
void	free(void *ptr);

void    *realloc(void *ptr, size_t size);

/*	show_alloc_mem.c	*/
void    show_alloc_mem();

/*	memory.c	*/
t_block *find_block(t_block **last, size_t size);
void    split_memory(t_block *block, size_t size);
t_block *extend_heap(t_block *last, size_t size);

/*	malloc.c	*/
t_block *init_malloc(size_t size);
t_block *empty_block(size_t size, t_block *last);
void	*malloc(size_t size);

#endif /* MALLOC_H_ */
