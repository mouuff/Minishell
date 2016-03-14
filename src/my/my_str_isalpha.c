/*
** my_str_isalpha.c for my str is alpha in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan  6 22:50:55 2016 Arnaud Alies
** Last update Thu Jan  7 11:44:15 2016 Arnaud Alies
*/

int	my_char_isalpha(char c)
{
  if ((c >= 'A' && c <= 'Z') ||
      (c >= 'a' && c <= 'z') ||
      c == '_')
    return (1);
  return (0);
}

int     my_str_isalphanum(const char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    {
      if ((str[x] >= '0' && str[x] <= '9')
	  || my_char_isalpha(str[x]))
	x += 1;
      else
	return (0);
    }
  return (1);
}
