/*
** free.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:29:40 2014 anthony guerot
** Last update Wed Feb  5 14:30:50 2014 guerot_a
*/

#include "malloc.h"

static void	merge_block(t_block *block)
{
  t_block*	curr;

  while (curr->prev->free == TRUE)
    curr = curr->prev;
  block->size = 0;
  while (curr->next->free == TRUE)
    {
      block->size += curr->size + HEADER_SIZE;
      curr = curr->next;
    }
  block->size -= HEADER_SIZE;
  block->next = curr;
  curr->prev = block;
}

void		_free(void *ptr)
{
  t_block*	block;

  if (ptr == NULL)
    return;
  block = get_block(ptr);
  if (block == NULL)
    raise("Invalid Pointer");
  block->free = TRUE;
  merge_block(block);
}

void		free(void *ptr)
{
  _free(ptr);
}
