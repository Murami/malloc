/*
** dump_block.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 18:25:22 2014 anthony guerot
** Last update Fri Feb  7 14:09:22 2014 guerot_a
*/

#include <stdio.h>
#include "malloc.h"

void		dump_block()
{
  t_block*	curr;

  curr = blocks_list.next;
  printf("<------------------------->\n");
  while (curr != &blocks_list)
    {
      printf("*//----------\\\\*\n");
      printf("*              *\n");
      printf("*%14d*\n", (int)curr->size);
      printf("*%14p*\n", (void*)curr->prev);
      printf("*%14p*\n", (void*)curr->next);
      if (curr->free)
  	printf("*     FREE     *\n");
      else
  	printf("*     ALLO     *\n");
      printf("*              *\n");
      printf("*\\\\----------//*\n");
      curr = curr->next;
    }
  printf("<------------------------->\n");
}
