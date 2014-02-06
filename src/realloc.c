/*
** realloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:28:13 2014 anthony guerot
** Last update Thu Feb  6 15:13:35 2014 guerot_a
*/

#include "malloc.h"

static void	merge_block_range(t_block* start, t_block* end)
{
  t_block*	curr;
  int		size;

  curr = start;
  size = -HEADER_SIZE;
  while (curr != end)
    {
      size += curr->size + HEADER_SIZE;
      curr = curr->next;
    }
  if (size <= 0)
    return;
  start->size = size;
  start->next = end;
  end->prev = start;
}

/*static*/ int	extand_block(t_block* block, int size)
{
  t_block*	curr;
  int		extanded_size;

  curr = block;
  extanded_size = -HEADER_SIZE;
  while (curr->next->free)
    {
      extanded_size += curr->size + HEADER_SIZE;
      if (extanded_size >= size)
	{
	  merge_block_range(block, curr->next);
	  split_block(block, size);
	  return (TRUE);
	}
      curr = curr->next;
    }
  return (FALSE);
}

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
  if ((int)size > old_size)
    old_size = size;
  memcpy(block->data, ptr, old_size);
  free(ptr);
  return (block);
}
