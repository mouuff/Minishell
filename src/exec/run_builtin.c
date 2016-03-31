/*
** prefork.c for before forking in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 29 14:53:36 2016 alies_a
** Last update Thu Mar 31 20:23:53 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

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
      if (pipeit(cmp, NULL, *in_fd))
	return (1);
      if (redirect(cmp))
	return (1);
      if ((code = func(data, my_array_len(cmp->args), cmp->args)) != 0)
	return (code);
      if (fd_rollback(fd))
	return (1);
      return (0);
    }
  return (-1);
}
