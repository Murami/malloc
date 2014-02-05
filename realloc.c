/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Wed Feb  5 14:41:08 2014 guerot_a
*/

#include "malloc.h"

static int	extand_block(t_block** block)
{
}

void*		realloc(void *ptr, size_t size)
{
  t_block*	 block;

  if (ptr == NULL)
    return (malloc(size));
  if (size == 0)
    free(ptr);
  block = get_block(block);
  if (extand_block(&block))
    return (block);
  _free(ptr);
  block = memcyp(malloc(size), ptr, block->size);
  return (block);
}
