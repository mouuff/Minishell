/*
** sig.c for sig in /home/alies/rendu/PSU_2015_minishell1/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan 11 11:19:28 2016 Arnaud Alies
** Last update Wed Apr  6 14:33:13 2016 alies_a
*/

#include <unistd.h>
#include <signal.h>
#include "mysh.h"

void	set_handlers()
{
  if (isatty(STDIN_FILENO))
    {
      signal(SIGINT, keyboard_interrupt);
      signal(SIGTSTP, do_void);
      signal(SIGQUIT, do_void);
    }
}

void	unset_handlers()
{
  signal(SIGINT, SIG_DFL);
  signal(SIGTSTP, SIG_DFL);
  signal(SIGQUIT, SIG_DFL);
}
