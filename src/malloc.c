/*
** malloc.c for  in /home/pinon_a/rendu/PSU_2013_malloc/src
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Mon Feb  3 15:41:14 2014 pinon
** Last update Mon Feb  3 16:13:12 2014 pinon
*/

#include <stdio.h>
#include <unistd.h>

void	*malloc(size_t size)
{
  sbrk(size);
  printf("Torl\n\n\n");
  return (NULL);
}
