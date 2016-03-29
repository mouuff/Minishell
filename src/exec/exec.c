/*
** exec.c for exec in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:26:23 2016 Arnaud Alies
** Last update Tue Mar 29 20:33:19 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "mysh.h"

t_signal signals[] =
  {{SIGFPE, "Floating exception\n"},
   {SIGILL, "Illegal instruction\n"},
   {SIGSEGV, "Segmentation fault\n"},
   {SIGBUS, "Bus error\n"},
   {SIGABRT, "Abort\n"},
   {SIGTRAP, "Trace/BPT trap\n"},
   {SIGSYS, "Bad system call\n"},
   {SIGTERM, "Terminated\n"},
   {SIGINT, "\n"},
   {SIGQUIT, "Quit\n"},
   {SIGKILL, "Killed\n"},
   {SIGHUP, "Hangup\n"},
   {0, NULL}};

int	print_sig(int status)
{
  int	sig;
  int	x;

  if (!WIFSIGNALED(status))
    return (0);
  sig = WTERMSIG(status);
  x = 0;
  while (signals[x].signal != 0)
    {
      if (sig == signals[x].signal)
	{
	  my_puterr(signals[x].name);
	  return (1);
	}
      x += 1;
    }
  return (0);
}
/*
int	forked(t_data *data, t_cmp *cmp, int fds)
{
  char	*bin_path;
  int	code;

  if (IS_ERR((code = check_builtin(data, expr))))
    return (code);
  if (code == E_SKIP)
    {
      if ((bin_path = get_exec(data, cmp->args)) == NULL)
	return (E_PASS);
      close(fd[0]);
      if (cmp->next != NULL)
	dup2(fd[1], 1);
      if (cmp->prev != NULL)
	dup2(in_fd, 0);
      redirect(cmp);
      if (execve(bin_path, cmp->args, data->env) == -1)
	return (E_KILL);
    }
  return (0);
}
*/

int		launch_cmp(t_data *data,
			   t_cmp *cmp,
			   int *fd,
			   int in_fd)
{
  char		*bin_path;
  t_built	func;

  func = check_builtin(cmp->args);
  if (redirect(cmp))
    return (1);
  if (pipeit(cmp, fd, in_fd))
    return (1);
  if (func != NULL)
    func(data, my_array_len(cmp->args), cmp->args);
  else
    {
      if ((bin_path = get_exec(data, cmp->args)) == NULL)
	return (1);
      if (execve(bin_path, cmp->args, data->env) == -1)
	return (1);
    }
  return (0);
}

int     launch_cmps(t_data *data, t_cmp *cmp, int in_fd)
{
  int	fd[2];
  pid_t	pid;
  int   status;
  int	code;

  if ((code = prefork(data, cmp, &in_fd)) != E_PASS)
    return (code);
  if (pipe(fd) == -1)
    return (E_MALLOC);
  pid = fork();
  if (pid == 0)
    {
      launch_cmp(data, cmp, fd, in_fd);
      exit(1);
    }
  else
    {
      close(fd[1]);
      if (cmp->next != NULL)
	launch_cmps(data, cmp->next, fd[0]);
      close(fd[0]);
      if (waitpid(pid, &status, 0) != -1)
	print_sig(status);
    }
  return (E_PASS);
}
