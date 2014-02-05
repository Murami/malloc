/*
** raise.c for  in /home/pinon_a/rendu/PSU_2013_malloc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Wed Feb  5 17:27:13 2014 pinon
** Last update Wed Feb  5 17:46:44 2014 pinon
*/

#include <stdio.h>
#include <stdlib.h>

void	_raise(char *msg, char *file, unsigned int line)
{
  fprintf(stderr, "%s: %u: %s\n", file, line, msg);
  abort();
}
