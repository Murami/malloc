/*
** free.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:29:40 2014 anthony guerot
** Last update Wed Feb  5 19:27:14 2014 guerot_a
*/

#include "malloc.h"

/*static*/ void	merge_block(t_block *block)
{
  t_block*	curr;
  int		size;

  while (curr->prev->free == TRUE)
    curr = curr->prev;
  size = -HEADER_SIZE;
  while (curr->free == TRUE)
    {
      size += curr->size + HEADER_SIZE;
      curr = curr->next;
    }
  if (size <= 0)
    return;
  block->size = size;
  block->next = curr;
  curr->prev = block;
}

void		_free(void *ptr)
{
  t_block*	block;

  /* printf("<----free---->\n"); */
  if (ptr == NULL)
    return;
  block = get_block(ptr);
  if (block == NULL)
    raise("Invalid Pointer");
  /* printf("free a block of : %d\n", block->size); */
  block->free = TRUE;
  /* merge_block(block); */
}

void		free(void *ptr)
{
  _free(ptr);
  /* printf("\n\n"); */
  /* dump_block(); */
  /* printf("\n\n"); */
}
