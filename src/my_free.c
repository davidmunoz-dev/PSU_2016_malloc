/*
** my_free.c for  in /home/hazer/Documents/tek2/Unix/PSU_2016_malloc/src
**
** Made by hazer
** Login   <david.munoz@epitech.eu>
**
** Started on  Tue Feb  7 12:45:59 2017 hazer
** Last update Fri Feb 10 15:33:24 2017 hazer
*/

#include "my_malloc.h"

t_block	*get_block(void *ptr)
{
  char	*tmp;

  tmp = ptr;
  tmp -= BLOCK_SIZE;
  return (ptr = tmp);
}

int	valid_addr(void *ptr)
{
  if (first_fit)
    if (ptr > first_fit && ptr < sbrk(0))
      return (ptr == (get_block(ptr))->ptr_free);
  return (MALLOC_OK);
}

void	free(void *ptr)
{
  t_block	*block;

  if (valid_addr(ptr) != 0)
    {
      block = get_block(ptr);
      block->free = 1;
    }
}
