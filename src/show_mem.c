/*
** show_mem.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Thu Feb  6 11:52:58 2014 anthony guerot
** Last update Thu Feb  6 12:11:46 2014 guerot_a
*/

#include "malloc.h"

void	show_alloc_mem()
{
  t_block*	curr;

  curr = blocks_list.next;
  while (curr != &blocks_list)
    {
      printf("%p - %p : %d\n", curr->data, curr->data + curr->size, curr->size);
      curr = curr->next;
    }
}
