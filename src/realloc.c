/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Thu Feb 13 18:13:56 2014 guerot_a
*/

#include "malloc.h"

void*		realloc(void *ptr, size_t size)
{
  size_t	min_size;
  void*		new;
  t_block*	block;

  block = (void*)((char*)ptr - HEADER_SIZE);
  if (ptr == NULL)
    return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  min_size = block->size;
  min_size = (min_size > size) ? size : min_size;
  free(ptr);
  new = malloc(size);
  if (new == NULL)
    return (NULL);
  return (memmove(new, ptr, min_size));
}
