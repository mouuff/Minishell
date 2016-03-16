/*
** mysh.h for mysh in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 14:09:57 2016 Arnaud Alies
** Last update Wed Mar 16 16:43:10 2016 alies_a
*/

#ifndef MYSH_H_
#define MYSH_H_

#define IS_ERR(x) ((x > 0 ? 1 : 0))

typedef struct s_data
{
  char **env;
  char *oldpwd;
} t_data;

typedef struct s_func
{
  int (*func)(t_data *data, int ac, char **av);
  const char *name;
} t_func;

typedef struct t_signal
{
  int signal;
  const char *name;
} t_signal;

typedef enum e_exit_code
  {
    E_SKIP	= -2,
    E_PASS	= -1,
    E_EXIT	= 1,
    E_MALLOC	= 2
  } t_exit_code;

void    clean_str(char **s);
void	clean_array(char ***array);

int     init_data(t_data *data, char **env);
void	free_data(t_data *data);
void    keyboard_interrupt(int sig);
void    do_void(int sig);
int     compute_line(t_data *data, char *line);

/*
** Builtins
*/

int     check_builtin(t_data *data, char **args);
int     b_setenv(t_data *data, int ac, char **av);
int     b_unsetenv(t_data *data, int ac, char **av);
int     b_env(t_data *data, int ac, char **av);
int     b_exit(t_data *data, int ac, char **av);
int     b_cd(t_data *data, int ac, char **av);
int     b_doge(t_data *data, int ac, char **av);

/*
** Environement
*/

const char *get_env(t_data *data, const char *name);
int     find_env(t_data *data, const char *name);
int     my_setenv(t_data *data, char **args);
int     parse_setenv(char **args);
int     my_unsetenv(t_data *data, char **args);

/*
** Execution
*/

char    *get_exec(t_data *data, char **args);
int     my_exec(t_data *data, char **args);

/*
** Parsing
*/

typedef struct s_parse
{
  int (*func)(const char *line);
  char type;
} t_parse;

typedef struct s_token
{
  char type;
  char *str;
  struct s_token *next;
  struct s_token *prev;
} t_token;

typedef enum e_token_code
  {
    T_PIPE	= -1,
    T_QUOTE	= -2
  } t_token_code;

int	is_delimiter(char c);

int	tok_default(const char *line);
int	tok_str(const char *line);
int	tok_right_simple(const char *line);
int	tok_left_simple(const char *line);

t_token	*tokenize(const char *line);

/*
** Misc
*/

void    set_handlers();
void    unset_handlers();

int	pre_check(char *str);
int     parse(char **args);

int	isdir(const char *path);
int	isfile(const char *path);
int	is_something(const char *path);
int     is_true_path(const char *str);

char    **str_to_arg(const char *str);

#endif
