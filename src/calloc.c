/*
** calloc.c in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Feb  7 15:36:45 2014 anthony guerot
** Last update Fri Feb  7 15:40:23 2014 guerot_a
*/

#include "malloc.h"

void	*calloc(size_t nmenb, size_t size)
{
  return (malloc(nmenb * size));
}
