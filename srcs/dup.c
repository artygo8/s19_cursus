#include "minishell.h"

int		ft_isvar_call(t_cmd *cmd)
{
	int i;

	i = cmd->i;
	if (cmd->line[i - 1] == '\\' || ft_isspace(cmd->line[i + 1]) || !(cmd->line[i + 1]))
		return (0);
	if (!ft_strncmp(&(cmd->line[cmd->i]), "${}", 3))
	{
		cmd->exit_status = BAD_SUBSTITUTION;
		return (0);
	}
	if (!ft_strncmp(&(cmd->line[cmd->i]), "${", 2))
	{
		i += 2;
		while (ft_isalnum(cmd->line[i]))
			i++;
		if (cmd->line[i] != '}')
		{
			cmd->exit_status = BAD_SUBSTITUTION;
			return (0);
		}
	}
	return (1);
}

char	*ft_vardup(char *str, t_list *list, unsigned int size)
{
	char *dup;

	dup = NULL;
	while (list)
	{
		if (list->content && !ft_strncmp(list->content, str, size))
			return (ft_strdup(&(((char*)list->content)[size + 1])));
		list = list->next;
	}
	return (dup);
}

char	*ft_translate(t_cmd *cmd) // gets the current variable back
{
	char	*res;
	t_list	*tmp;
	int		size;

	size = 0;
	cmd->i++; //for the $
	if (cmd->line[cmd->i] == '{')
		cmd->i++;
	while (ft_isalnum(cmd->line[cmd->i + size]))
		size++;
	if (!(res = ft_vardup(&(cmd->line[cmd->i]), cmd->env, size)))
	 	res = ft_vardup(&(cmd->line[cmd->i]), cmd->var, size);
	if (res)
		cmd->i += size;
	return (res);
}

char*	ft_basicdup(t_cmd *cmd)
{
	char	tmp[1000];
	char	*var;
	int		j;

	ft_bzero(tmp, 1000);
	j = 0;
	if (cmd->line[cmd->i] == '$' && ft_isvar_call(cmd))
	{
		var = ft_translate(cmd);
		ft_strlcat(tmp, var, 1000);
		free(var);
	}
	else if (!cmd->i)
		tmp[j++] = cmd->line[cmd->i++]; //the first letter was already approved by the caller
	while (cmd->line[cmd->i] && ((!ft_isspace(cmd->line[cmd->i])
		&& !ft_isinset(cmd->line[cmd->i], "'\"|;<>$"))
		|| cmd->line[cmd->i - 1] == '\\'))
	{
		if (cmd->line[cmd->i] == '\\' && cmd->line[cmd->i + 1] == '\\')
			tmp[j++] = cmd->line[cmd->i++];
		else if (cmd->line[cmd->i] != '\\')
			tmp[j++] = cmd->line[cmd->i];
		cmd->i++;
	}
	return (ft_strdup(tmp));
}

// char*	ft_weakdup(t_cmd *cmd)
// {
// }
//
// char*	ft_strongdup(t_cmd *cmd)
// {
// }

char*	ft_minidup(t_cmd *cmd)
{
	char *var;
	char *tmp;
	char *tmp2;

	var = NULL;
	while (cmd->line[cmd->i] && !ft_isspace(cmd->line[cmd->i])
		&& !ft_isinset(cmd->line[cmd->i], "'\"|;<>"))
	{
		tmp = var;
		// if (cmd->line[cmd->i] == '\'')
		// 	tmp2 = ft_strongdup(cmd);
		// else if (cmd->line[cmd->i] == '\"')
		// 	tmp2 = ft_weakdup(cmd);
		// else
		tmp2 = ft_basicdup(cmd);
		if (cmd->exit_status != 0 && !cmd->error) // THIS IS VERY IMPORTANT I NEED TO DO LIKE THAT EVERY TIME
			cmd->error = ft_strdup(tmp2);
		var = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	return (var);
}
