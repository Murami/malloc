/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Fri Feb  7 14:19:28 2014 guerot_a
*/

#include "malloc.h"

void*		realloc(void *ptr, size_t size)
{
  t_block*	block;
  int		old_size;

  dbg_start++;
  printf("\033[35;01mralloc of size [%10d] for %p", (int)size, ptr);
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
  if ((int)size < old_size)
    old_size = size;
  printf("-> %d <-|", old_size);
  printf("-> %d <-\033[00m \n", (int)size);
  block = malloc(size);
  memcpy(block->data, ptr, old_size);
  free(ptr);
  if (dbg_start > DBG_START)
    dump_block();
  return (block->data);
}
