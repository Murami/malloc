/*
** malloc.h for  in /home/pinon_a/rendu/PSU_2013_malloc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Thu Feb 13 15:43:31 2014 pinon
** Last update Thu Feb 13 15:49:04 2014 guerot_a
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

#define DBG_START	99999999

#define raise(msg) (_raise(msg, __FILE__, __LINE__))

typedef struct __attribute__((packed))	s_block
{
  struct s_block*	next;
  struct s_block*	prev;
  int			size;
  int			free;
  char			data[1];
}			t_block;

#define HEADER_SIZE	((int)(sizeof(t_block) - 1))

extern int		dbg_start;
extern t_block		blocks_list;

t_block*	get_block(void *data);
void		_free(void *ptr);
void		split_block(t_block *block, int size);
void		_raise(char*, char*, unsigned int);
void		dump_block();

void		free(void *ptr);
void*		malloc(size_t size);
void*		realloc(void *ptr, size_t size);
void*		calloc(size_t nmenb, size_t size);
