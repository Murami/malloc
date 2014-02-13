/*
** malloc.h in /home/guerot_a/Documents/DepotsGit/PSU_2013_malloc/new_malloc/include
**
** Made by anthony guerot
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Feb  7 17:20:07 2014 anthony guerot
** Last update Fri Feb  7 17:55:43 2014 guerot_a
*/

typedef struct	s_block
{
  unsigned int	size;
  unsigned int	next_free_offset;
}		t_block;

#define ALLOC_THRESHOLD_MAX		10

#define MAX(a, b)			((a > b) ? a: b)
#define MIN(a, b)			((a < b) ? a: b)

extern t_block* blocks_lists[10] = {NULL};
