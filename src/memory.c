/*
** memory.c for  in /home/hazer/Documents/tek2/PSU_2016_malloc/src
**
** Made by hazer
** Login   <david.munoz@epitech.eu>
**
** Started on  Wed Feb  1 10:03:33 2017 hazer
** Last update Fri Feb 10 14:43:28 2017 hazer
*/

#include "my_malloc.h"
#include <unistd.h>
#include <string.h>

t_block	*find_block(t_block **last, size_t size)
{
  t_block	*block = first_fit;

  while (block && !(block->free && block->size >= size))
    {
      *last = block;
      block = block->next;
    }
  return (block);
}

void	split_memory(t_block *block, size_t size)
{
  t_block	*new;

  new = (t_block*)(block->data + size);
  new->size = block->size - size - BLOCK_SIZE;
  new->next = block->next;
  new->prev = block;
  new->free = 1;
  block->size = size;
  block->next = new;
  new->ptr_free = new->data;
  if (new->next)
    new->next->prev = new;
}

t_block	*extend_heap(t_block *last, size_t size)
{
  t_block	*block;

  block = sbrk(0);
  if (sbrk(BLOCK_SIZE + size) == (void*) -1)
    return (NULL);
  block->size = size;
  block->next = NULL;
  block->prev = last;
  block->free = MALLOC_OK;
  block->ptr_free = block->data;
  if (last)
    last->next = block;
  return (block);
}
