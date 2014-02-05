/*
** malloc.h in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:38:02 2014 anthony guerot
** Last update Wed Feb  5 18:05:35 2014 pinon
*/

#define _BSD_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
** TODO : shrink_heap
 */

#define FALSE 	0
#define TRUE	1

#define raise(msg) (_raise(msg, __FILE__, __LINE__))

typedef struct		s_block
{
  struct s_block*	next;
  struct s_block*	prev;
  size_t		size;
  int			free;
  char			data[1];
}			t_block;

#define HEADER_SIZE	((int)(sizeof(t_block) - 1))

extern t_block		blocks_list;

t_block*	get_block(void *data);
void		_free(void *ptr);
void		split_block(t_block *block, size_t size);
void		_raise(char*, char*, unsigned int);

void		free(void *ptr);
void*		malloc(size_t size);
void*		realloc(void *ptr, size_t size);
