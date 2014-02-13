/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Thu Feb 13 16:21:07 2014 guerot_a
*/

#include "malloc.h"

void*		realloc(void *ptr, size_t size)
{
  size_t	min_size;
  t_block*	block;

  printf("realloc\n");
  if (ptr == NULL)
    return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  min_size = ((t_block*)ptr)->size;
  min_size = (min_size > size) ? size : min_size;
  free(ptr);
  block = malloc(size);
  if (block == NULL)
    return (NULL);
  return (memmove(block, ptr, min_size));
}
