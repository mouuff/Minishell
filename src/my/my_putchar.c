/*
** my_putchar.c for my_putchar in /home/alies_a/rendu/Piscine_C_J03
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Sep 30 10:59:18 2015 Arnaud Alies
** Last update Mon Jan  4 20:28:20 2016 Arnaud Alies
*/

#include <unistd.h>

int	my_putchar(const char c)
{
  return (write(1, &c, 1));
}
