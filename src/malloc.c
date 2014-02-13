/*
** malloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:18:13 2014 anthony guerot
** Last update Thu Feb 13 17:52:00 2014 pinon
*/

#include "malloc.h"

t_block		blocks_list	= {&blocks_list, &blocks_list, 0, FALSE, {0}};
int		dbg_start	= 0;
pthread_mutex_t	mutex		= PTHREAD_MUTEX_INITIALIZER;

size_t		align_size(size_t size)
{
  size = (size / getpagesize() + 1) * getpagesize();
  return (size);
}

static t_block*	get_first_fit(int size)
{
  t_block*	curr;

  curr = blocks_list.next;
  while (curr != &blocks_list)
    {
      if (curr->size >= size && curr->free == TRUE)
	{
	  /* printf(" first fit"); */
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

  /* printf(" new alloc"); */
  if (size == 0)
    return (NULL);
  aligned_size = align_size(size + HEADER_SIZE);
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

  pthread_mutex_lock(&mutex);
  dbg_start++;
  block = get_first_fit(size);
  if (block == NULL)
    block = new_alloc(size);
  if (block == NULL)
    {
      pthread_mutex_unlock(&mutex);
      return (NULL);
    }
  block->free = FALSE;
  split_block(block, size);
  if (dbg_start > DBG_START)
    dump_block();
  pthread_mutex_unlock(&mutex);
  return (block->data);
}
