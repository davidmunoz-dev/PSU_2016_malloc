/*
** my_realloc.c for  in /home/hazer/Documents/tek2/Unix/PSU_2016_malloc/src
**
** Made by hazer
** Login   <david.munoz@epitech.eu>
**
** Started on  Tue Feb  7 12:36:47 2017 hazer
** Last update Fri Feb 10 15:30:40 2017 hazer
*/

#include	<string.h>
#include	"my_malloc.h"
#include	<stdio.h>

void	*realloc(void *ptr, size_t size)
{
  t_block	*new_block;

  if (ptr == NULL)
    return (malloc(size) == NULL ? NULL : malloc(size));
  if (valid_addr(ptr) == MALLOC_OK)
    {
      if ((new_block = malloc(size)) == NULL)
  	return (NULL);
      memcpy(new_block, ptr, size);
      free(ptr);
      return (new_block);
    }
  return (NULL);
}
