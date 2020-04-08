#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"

enum			e_error
{
	BAD_SUBSTITUTION = 1,
	COMMAND_NOT_FOUND = 127,
};

enum			e_cmd
{
	ERROR = -1,		// error with the given command
	NOCMD,			// nothing given - only spaces
	MSH,			// "./executable" or msh "executable"
	ECHO,
	ECHON,			// with option -n
	ENV,
	CD,				// absolute or relative path
	PWD,			// like in bash
	EXPORT,			// like in bash
	UNSET,			// like in bash
	EXIT,			// like in bash
};

typedef struct	s_cmd
{
	char	*line;
	int		i; // pos
	int		cmd;
	t_list	*args;
	t_list	*env;
	t_list	*vars;
	int		fd_output;
	int		fd_append;
	int		fd_input;
	int		exit_status;
	char	*error;
}				t_cmd;

/*
 * CMD
 */

void	ft_echo(t_cmd *cmd, int fd);
void	ft_cd(t_cmd *cmd, int res);
void	ft_pwd(t_cmd *cmd, int fd);
void	ft_export(t_cmd *cmd);
void	ft_unset(t_cmd *cmd);
void	put_cmd(t_cmd *cmd);
void	ft_reset_cmd(t_cmd *cmd);

/*
 * DUP
 */

char	*ft_vardup(char *str, t_list *list, unsigned int size);
char	*ft_translate(t_cmd *cmd);
char*	ft_minidup(t_cmd *cmd);
// char*	ft_weakdup(t_cmd *cmd);
// char*	ft_strongdup(t_cmd *cmd);
char*	ft_basicdup(t_cmd *cmd);

/*
 * ENV
 */

t_list	*ft_lstenv(char **envp);
void	ft_putenv(t_list *env, int fd);
int 	ft_var_to_lst(t_list *lst, const char *var);

/*
 * GET
 */

// ft_get_topipe(t_cmd *cmd);
// ft_get_frompipe(t_cmd *cmd);
void	ft_get_exe(t_cmd *cmd);
void	ft_get_var(t_cmd *cmd);
// ft_get_redir(t_cmd *cmd);
void	ft_get_echo(t_cmd *cmd);
void	ft_get_cmd(t_cmd *cmd);
void	ft_get_arg(t_cmd *cmd);

/*
 * IS_TYPE
 */

int		ft_isvar_call(t_cmd *cmd);
int		ft_ispath(char *line);
int		ft_isvar(char *line);

/*
 * PROMPT
 */

void	ft_reset_cmd(t_cmd *cmd);
void	ft_puterror(t_cmd *cmd);
void	apply_cmd(t_cmd *cmd);
void	ft_parsing_cmd(t_cmd *cmd);
int		ft_prompt(char *name, t_cmd *cmd);

/*
 * REDIR
 */

void	ft_get_append(t_cmd *cmd);
void	ft_get_output(t_cmd *cmd);
void	ft_get_input(t_cmd *cmd);
void	ft_get_redir(t_cmd *cmd);

#endif
