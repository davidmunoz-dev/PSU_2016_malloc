/*
** my_malloc.c for my_malloc in /home/durand_4/projets/psu/PSU_2016_malloc
**
** Made by Loïc Durand
** Login   <durand_4@epitech.net>
**
** Started on  Fri Jan 27 09:07:50 2017 Loïc Durand
** Last update Fri Feb 10 11:49:07 2017 hazer
*/

#include <stdio.h>
#include <string.h>
#include "my_malloc.h"

void	*first_fit = NULL;

t_block	*empty_block(size_t size, t_block *last)
{
  t_block	*block;

  block = find_block(&last, size);
  if (block)
    {
      if (block->size - size >= (BLOCK_SIZE + sizeof(int)))
	split_memory(block, size);
      block->free = 0;
    }
  else
    block = extend_heap(last, size);
  return (block);
}

void	*malloc(size_t size)
{
  size_t	align_size;
  t_block	*block;
  t_block	*last;

  if (size <= 0)
    return (NULL);
  align_size = ((((size - 1) / 4) * 4) + 4);
  if (first_fit == NULL)
    {
      if ((block = extend_heap(NULL, size)) == NULL)
	return (NULL);
      first_fit = block;
    }
  else
    {
      last = first_fit;
      if ((block = empty_block(align_size, last)) == NULL)
	return (NULL);
    }
  return (block->data);
}
