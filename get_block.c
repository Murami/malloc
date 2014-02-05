/*
** get_block.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:35:44 2014 anthony guerot
** Last update Wed Feb  5 14:36:04 2014 guerot_a
*/

#include "malloc.h"

t_block*	get_block(void* data)
{
  t_block*	curr;

  curr = &block->next;
  while (curr != blocks_list)
    {
      if (curr->data == data)
	return (curr);
      curr = curr->next;
    }
  return (NULL);
}
