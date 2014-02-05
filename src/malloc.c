/*
** malloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:18:13 2014 anthony guerot
** Last update Wed Feb  5 16:43:21 2014 pinon
*/

#include "malloc.h"

t_block		blocks_list = {&blocks_list, &blocks_list, 0, FALSE, {0}};

size_t		align_size(size_t size)
{
  size_t new;
  
  new = 2;
  while (new < size)
    new = new << 1;
  return (new);
}

static void	split_block(t_block* block, size_t size)
{
  t_block*	new_block;

  if (block->size <= HEADER_SIZE + size)
    return;
  new_block = (t_block*)(block->data + size);
  new_block->prev = block;
  new_block->next = block->next;
  new_block->size = block->size - size;
  new_block->free = TRUE;
  block->next->prev = new_block;
  block->next = new_block;
  block->size = size;
}

static t_block*	get_first_fit(size_t size)
{
  t_block*	curr;

  curr = blocks_list.next;
  while (curr != &blocks_list)
    {
      if (curr->size >= size)
	return (curr);
      curr = curr->next;
    }
  return (NULL);
}

static t_block*	new_alloc(size_t size)
{
  t_block*	block;
  size_t	aligned_size;

  if (size == 0)
    return (NULL);
  aligned_size = align_size(size + HEADER_SIZE);
  block = (t_block*)(sbrk((intptr_t)aligned_size));
  block->size = aligned_size - HEADER_SIZE;
  block->free = TRUE;
  block->next = &block_list;
  block->prev = blocks_list.prev;
  blocks_list.prev = block;
  block->prev->next = block;
  return (block);
}

void*		malloc(size_t size)
{
  t_block*	block;

  block = get_first_fit(size);
  if (block == NULL)
    block = new_alloc(size);
  block->free = FALSE;
  split_block(block, size);
  return (block->data);
}
