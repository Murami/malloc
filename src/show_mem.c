/*
** show_mem.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Thu Feb  6 11:52:58 2014 anthony guerot
** Last update Sun Feb 16 18:01:08 2014 pinon
*/

#include "malloc.h"

void	show_alloc_mem()
{
  t_block*	curr;

  printf("break : %p\n", sbrk(0));
  curr = g_blocks_list.next;
  while (curr != &g_blocks_list)
    {
      printf("%p - %p : %d octets\n", curr->data,
	     curr->data + curr->size, curr->size);
      curr = curr->next;
    }
}
