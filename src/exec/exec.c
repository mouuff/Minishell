/*
** exec.c for exec in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:26:23 2016 Arnaud Alies
** Last update Wed Apr  6 14:08:56 2016 alies_a
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

int		launch_cmp(t_data *data,
			   t_cmp *cmp,
			   int *fd,
			   int in_fd)
{
  char		*bin_path;
  t_built	func;

  func = check_builtin(cmp->args);
  if (pipe_it(cmp, fd, in_fd))
    return (1);
  if (redirect(cmp))
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

  if ((code = run_builtin(data, cmp, &in_fd)) != -1)
    return (code);
  if (pipe(fd) == -1)
    return (1);
  if ((pid = rdr_fork(cmp)) == -1)
    return (1);
  if (pid == 0)
    {
      launch_cmp(data, cmp, fd, in_fd);
      exit(1);
    }
  close(fd[1]);
  if (cmp->next != NULL)
    launch_cmps(data, cmp->next, fd[0]);
  close(fd[0]);
  if (waitpid(pid, &status, 0) != -1)
    print_sig(status);
  return (0);
}
