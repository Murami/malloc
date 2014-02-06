/*
** malloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:18:13 2014 anthony guerot
** Last update Thu Feb  6 09:46:16 2014 guerot_a
*/

#include "malloc.h"

t_block		blocks_list = {&blocks_list, &blocks_list, 0, FALSE, {0}};

size_t		align_size(size_t size)
{
  size_t new;

  new = 2;
  while (new <= size)
    new = new << 1;
  return (new);
}

static t_block*	get_first_fit(int size)
{
  t_block*	curr;

  curr = blocks_list.next;
  while (curr != &blocks_list)
    {
      if (curr->size >= size && curr->free)
	{
	  /* printf("First fit for size : %d\n", size); */
	  /* printf("Block of size : %d\n", curr->size); */
	  return (curr);
	}
      curr = curr->next;
    }
  return (NULL);
}

static t_block*	new_alloc(size_t size)
{
  t_block*	block;
  size_t	aligned_size;

  /* printf("New alloc:\n"); */
  if (size == 0)
    return (NULL);
  aligned_size = align_size(size + HEADER_SIZE);
  /* printf("Aligned size : %d\n", (int)aligned_size); */
  block = (t_block*)(sbrk((intptr_t)aligned_size));
  block->size = aligned_size - HEADER_SIZE;
  block->free = TRUE;
  block->next = &blocks_list;
  block->prev = blocks_list.prev;
  blocks_list.prev = block;
  block->prev->next = block;
  return (block);
}

void*		malloc(size_t size)
{
  t_block*	block;

  printf("malloc of %d\n", (int)size);
  block = get_first_fit(size);
  if (block == NULL)
    block = new_alloc(size);
  block->free = FALSE;
  split_block(block, size);
  /* printf("Data returned\n--------\n"); */
  /* printf("\n\n"); */
  /* dump_block(); */
  /* printf("\n\n"); */
  return (block->data);
}
