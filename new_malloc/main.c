/*
** main.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc/new_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Feb  7 22:19:08 2014 anthony guerot
** Last update Fri Feb  7 22:41:57 2014 guerot_a
*/

#define _USE_BSD

#include <unistd.h>
#include <stdio.h>

/* #define align_pagesize(a)	(a-1 / getpagesize() + 1) * getpagesize() */

int	main()
{
  int	n = 4096;

  n = align_pagesize(n);
  printf("size : %d\n", n);
  printf("page size : %d\n", getpagesize());
  printf("%p\n", sbrk(0));
  printf("%p\n", sbrk(3));
  printf("%p\n", sbrk(0));
  printf("%p\n", sbrk(3));
  printf("%p\n", sbrk(0));
}
