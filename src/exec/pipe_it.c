/*
** pipeit.c for pipe in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar 28 13:29:52 2016 alies_a
** Last update Thu Mar 31 20:33:56 2016 alies_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int	pipe_it(const t_cmp *cmp,
		int *fd,
		int in_fd)
{
  if (fd != NULL)
    {
      if (close(fd[0]) == -1)
	return (1);
      if (cmp->next != NULL)
	{
	  if (dup2(fd[1], 1) == -1)
	    return (1);
	  if (close(fd[1]) == -1)
	    return (1);
	}
    }
  if (cmp->prev != NULL)
    {
      if (dup2(in_fd, 0) == -1)
	return (1);
      if (close(in_fd) == -1)
	return (1);
    }
  return (0);
}
