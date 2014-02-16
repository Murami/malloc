/*
** malloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:18:13 2014 anthony guerot
** Last update Sun Feb 16 18:11:01 2014 pinon
*/

#include "malloc.h"

t_block		g_blocks_list	= {&g_blocks_list, &g_blocks_list, 0, FALSE, {0}};
pthread_mutex_t	g_mutex		= PTHREAD_MUTEX_INITIALIZER;

size_t		align_size(size_t size)
{
  size = (size / getpagesize() + 1) * getpagesize();
  return (size);
}

static t_block*	get_first_fit(int size)
{
  t_block*	curr;

  curr = g_blocks_list.next;
  while (curr != &g_blocks_list)
    {
      if (curr->size >= size && curr->free == TRUE)
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
  block->next = &g_blocks_list;
  block->prev = g_blocks_list.prev;
  g_blocks_list.prev = block;
  block->prev->next = block;
  return (block);
}

void*		malloc(size_t size)
{
  t_block*	block;

  pthread_mutex_lock(&g_mutex);
  block = get_first_fit(size);
  if (block == NULL)
    block = new_alloc(size);
  if (block == NULL)
    {
      pthread_mutex_unlock(&g_mutex);
      return (NULL);
    }
  block->free = FALSE;
  split_block(block, size);
  pthread_mutex_unlock(&g_mutex);
  return (block->data);
}
