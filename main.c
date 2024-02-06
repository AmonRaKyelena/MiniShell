

#include "includes/minishell.h"

t_sig	g_signals;

int	main(int ac, char **av, char **env)
{
	t_mini	*mini;

	(void)av;
	(void)ac;
	mini = init_mini(env);
	init_error(mini);
	loop_read(mini, NULL);
	return (free_minishell(mini));
}
