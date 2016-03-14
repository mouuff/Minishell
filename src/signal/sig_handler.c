/*
** sig_handler.c for sig handler in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan  6 17:03:37 2016 Arnaud Alies
** Last update Sun Jan 24 15:58:34 2016 alies_a
*/

#include <signal.h>
#include "my.h"

void    keyboard_interrupt(int sig)
{
  if (sig == SIGINT)
    my_putstr("\n$>");
}

void	do_void(int sig)
{
  (void)sig;
}
