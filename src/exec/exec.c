/*
** exec.c for exec in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:26:23 2016 Arnaud Alies
** Last update Sun Jan 24 13:44:09 2016 alies_a
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

int	my_exec(t_data *data, char **args)
{
  char	*bin_path;
  pid_t	pid;
  int	status;

  if ((bin_path = get_exec(data, args)) == NULL)
    return (E_PASS);
  pid = fork();
  if (pid == 0)
    {
      if (execve(bin_path, args, data->env) == -1)
	return (E_EXIT);
    }
  else
    {
      free(bin_path);
      if (wait(&status) != -1)
	print_sig(status);
    }
  return (E_PASS);
}
