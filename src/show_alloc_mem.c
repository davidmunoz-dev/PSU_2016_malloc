/*
** show_alloc_mem.c for  in /home/hazer/Documents/tek2/Unix/PSU_2016_malloc/src
**
** Made by hazer
** Login   <david.munoz@epitech.eu>
**
** Started on  Fri Feb  3 10:14:23 2017 hazer
** Last update Fri Feb 10 14:43:06 2017 hazer
*/

#include "my_malloc.h"
#include <unistd.h>
#include <stdio.h>

void		show_alloc_mem()
{
  t_block       *block;

  block = first_fit;
  printf("break : %p\n", sbrk(0));
  if (block == NULL)
    printf("No memory\n");
  else
    {
      while (block)
	{
	  if (block->free == MALLOC_OK)
	    printf("%p - %p : %zu bytes\n", (void *)block->data,
		   (void *)(block->data + block->size), block->size);
	  block = block->next;
	}
    }
}
