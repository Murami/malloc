/*
** malloc.h in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Wed Feb  5 14:38:02 2014 anthony guerot
** Last update Wed Feb  5 14:39:55 2014 guerot_a
*/

#include <unistd.h>

/*
** TODO : shrink_heap
 */

#define FALSE 	0
#define TRUE	1

typedef struct		s_block
{
  struct s_block*	next;
  struct s_block*	prev;
  size_t		size;
  int			free;
  char			data[1];
}			t_block;

#define HEADER_SIZE	(sizeof(t_block) - 1)

extern t_block		blocks_list;
