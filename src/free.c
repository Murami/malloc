/*
** free.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:29:40 2014 anthony guerot
*/

#include "malloc.h"

static void	merge_block(t_block *block)
{
  t_block*	curr;
  int		size;

  curr = block;
  while (curr->prev->free == TRUE)
    curr = curr->prev;
  block = curr;
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

void		free(void *ptr)
{
  t_block*	block;

  dbg_start++;
  printf("\033[30;01mfree of %p", ptr);
  printf("\033[00m\n");
  /* dump_block(); */
  /* printf("\n\n"); */

  if (ptr == NULL)
    return;
  block = get_block(ptr);
  if (block == NULL)
    {
      printf("warning: free invalid pointer\n");
      return;
    }
  block->free = TRUE;
  merge_block(block);
  if (dbg_start > DBG_START)
    dump_block();
}
