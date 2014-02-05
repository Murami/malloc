/*
** split_block.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc/src
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 17:07:18 2014 anthony guerot
** Last update Wed Feb  5 17:07:55 2014 guerot_a
*/

#include "malloc.h"

void		split_block(t_block* block, size_t size)
{
  t_block*	new_block;

  if (block->size <= HEADER_SIZE + size)
    return;
  new_block = block->data + size;
  new_block->prev = block;
  new_block->next = block->next;
  new_block->size = block->size - size;
  new_block->free = TRUE;
  block->next->prev = new_block;
  block->next = new_block;
  block->size = size;
}
