/*
** prefork.c for before forking in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 29 14:53:36 2016 alies_a
** Last update Sun Apr  3 12:57:41 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int	set_fds(t_cmp *cmp, int *in_fd)
{
  int		fd;

  if (pipe_it(cmp, NULL, *in_fd))
    return (1);
  if (redirect(cmp))
    return (1);
  if ((cmp->rd)[IN].type == '{')
    {
      if ((fd = std_input(cmp)) == -1)
	return (1);
      close(fd);
    }
  return (0);
}

int		run_builtin(t_data *data,
			    t_cmp *cmp,
			    int *in_fd)
{
  t_built	func;
  int		code;
  int		fd[2];

  if (cmp->next == NULL && (func = check_builtin(cmp->args)) != NULL)
    {
      if (fd_backup(fd))
	return (1);
      if (set_fds(cmp, in_fd))
	{
	  fd_rollback(fd);
	  return (1);
	}
      if ((code = func(data, my_array_len(cmp->args), cmp->args)) != 0)
	{
	  if (fd_rollback(fd))
	    return (1);
	  return (code);
	}
      if (fd_rollback(fd))
	return (1);
      return (0);
    }
  return (-1);
}
