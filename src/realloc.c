/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Fri Feb  7 15:22:49 2014 guerot_a
*/

#include "malloc.h"

void*		realloc(void *ptr, size_t size)
{
  t_block*	block;
  int		old_size;

  dbg_start++;
  printf("\033[35;01mralloc of size [%10d] for %p\n", (int)size, ptr);
  if (ptr == NULL)
    return (malloc(size));
  if (size == 0)
    {
      printf("fuck\n");
      free(ptr);
      return (NULL);
    }
  block = get_block(ptr);
  if (block == NULL)
    {
      printf("warning: realloc invalid pointer\n");
      return (NULL);
    }
  old_size = block->size;
  if ((int)size < old_size)
    old_size = size;
  if ((block = malloc(size)) == NULL)
    {
      printf("ERR\n");
      return (NULL);
    }
  printf("WTF?!\n");
  memcpy(block->data, ptr, old_size);
  free(ptr);
  if (dbg_start > DBG_START)
    dump_block();
  return (block->data);
}
