/*
** mysh.h for mysh in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 14:09:57 2016 Arnaud Alies
** Last update Thu Mar 17 11:40:18 2016 alies_a
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

typedef struct s_token
{
  char type;
  char *str;
  struct s_token *next;
  struct s_token *prev;
} t_token;

typedef struct s_cmd
{
  char *args;
  char *input_file;
  char input_type;
  char *output_file;
  char output_type;
  struct s_cmd *prev;
  struct s_cmd *next;
} t_cmd;

typedef struct s_parse
{
  int (*detect)(const char *line);
  int (*recomp)(const t_token *tok, t_cmd **cmd);
  char type;
} t_parse;

int     cmp_left_simple(const t_token *tok, t_cmd **cmd);
int     cmp_right_simple(const t_token *tok, t_cmd **cmd);
int     cmp_str(const t_token *tok, t_cmd **cmd);
int     cmp_pipe(const t_token *tok, t_cmd **cmd);
t_cmd   *new_cmd();
t_cmd	*recompose(const t_token *tok);

int	is_delimiter(char c);

int	tok_default(const char *line);
int	tok_str(const char *line);
int	tok_right_simple(const char *line);
int	tok_left_simple(const char *line);
int     tok_pipe(const char *line);

t_token	*tokenize(const char *line);
void	tokens_free(t_token **start);

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
