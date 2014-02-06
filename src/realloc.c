/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Thu Feb  6 16:00:47 2014 pinon
*/

#include "malloc.h"

void*		realloc(void *ptr, size_t size)
{
  t_block*	block;
  int		old_size;

  printf("\033[35;01mralloc of size [%10d] for %p\033[00m\n", (int)size, ptr);
  if (ptr == NULL)
    return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  block = get_block(ptr);
  if (block == NULL)
    return (NULL);
  /* if (extand_block(block, size)) */
  /*   return (block); */
  old_size = block->size;
  block = malloc(size);
  if ((int)size < old_size)
    old_size = size;
  memcpy(block->data, ptr, old_size);
  free(ptr);
  return (block->data);
}
