/*
** prefork.c for before forking in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 29 14:53:36 2016 alies_a
** Last update Tue Mar 29 20:03:02 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

int		prefork(t_data *data,
			t_cmp *cmp,
			int *in_fd)
{
  t_built	func;
  int		code;
  int		fd[2];

  if (cmp->next == NULL && (func = check_builtin(cmp->args)) != NULL)
    {
      if (fd_backup(fd))
	return (E_MALLOC);
      if (pipeit(cmp, NULL, *in_fd))
	return (E_MALLOC);
      if (redirect(cmp))
	return (E_MALLOC);
      if ((code = func(data, my_array_len(cmp->args), cmp->args)) != E_PASS)
	return (code);
      if (fd_rollback(fd))
	return (E_MALLOC);
      return (E_SKIP);
    }
  return (E_PASS);
}
