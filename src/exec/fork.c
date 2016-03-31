/*
** fork.c for fork in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 31 18:04:22 2016 alies_a
** Last update Thu Mar 31 19:58:13 2016 alies_a
*/

#include <unistd.h>
#include "mysh.h"

int	rdrfork(const t_cmp *cmp)
{
  pid_t	pid;
  int	fd;

  fd = -1;
  if (cmp->next == NULL && (cmp->rd)[IN].type == '{')
    {
      if ((fd = std_input(cmp)) == -1)
	return (-1);
    }
  pid = fork();
  if (pid == 0 && fd != -1)
    {
      if (dup2(fd, 0) == -1)
	return (-1);
    }
  if (fd != -1)
    close(fd);
  return (pid);
}
