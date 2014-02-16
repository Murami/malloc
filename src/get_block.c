/*
** get_block.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:35:44 2014 anthony guerot
** Last update Sun Feb 16 14:15:47 2014 pinon
*/

#include "malloc.h"

t_block*	get_block(void* data)
{
  t_block*	curr;

  curr = g_blocks_list.next;
  while (curr != &g_blocks_list)
    {
      if (curr->data == data)
	  return (curr);
      curr = curr->next;
    }
  return (NULL);
}
