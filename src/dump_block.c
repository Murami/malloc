/*
** dump_block.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 18:25:22 2014 anthony guerot
** Last update Fri Feb  7 14:54:07 2014 pinon
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
      printf("size :%16d\t", (int)curr->size);
      printf("prev block:%16p\t", (void*)curr->prev);
      printf("prev data:%16p\t", curr->prev->data);
      printf("next block:%16p\t", (void*)curr->next);
      printf("next data:%16p\t", curr->next->data);
      if (curr->free)
  	printf("FREE\t");
      else
  	printf("ALLO\t");
      printf("\n");
      curr = curr->next;
    }
  printf("<------------------------->\n");
}
