/*
** my_puterr.c for my put err in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 14 14:36:50 2016 Arnaud Alies
** Last update Thu Jan 14 14:37:19 2016 Arnaud Alies
*/

#include <unistd.h>
#include "my.h"

int     my_puterr(const char *str)
{
  return (write(2, str, my_strlen(str)));
}
