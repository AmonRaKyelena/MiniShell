

#include "../includes/minishell.h"

void	init_oldpwd(t_mini *mini)
{
	t_var	*oldpwd;
	t_var	*pwd;

	oldpwd = find_variable("OLDPWD", mini, 100000);
	if (oldpwd && oldpwd->value)
		free(oldpwd->value);
	pwd = find_variable("PWD", mini, 100000);
	if (pwd)
		oldpwd->value = ft_strdup(pwd->value);
}

t_mini	*init_mini(char **env)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->variables = init_var();
	mini->env = save_env(env);
	increase_shlvl(mini);
	init_oldpwd(mini);
	mini->hist_file = get_hist_file_name(mini);
	mini->hd_file = get_hd_file_name(mini);
	mini->history = NULL;
	mini->start_tock = NULL;
	mini->cmd_line = NULL;
	mini->exit_status = 0;
	mini->ret = 0;
	mini->no_exec = 0;
	mini->err_msg = NULL;
	reset_fds(mini);
	mini->stdin = dup(STDIN);
	mini->stdout = dup(STDOUT);
	return (mini);
}
