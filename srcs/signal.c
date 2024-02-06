

#include "../includes/minishell.h"

void	sigint_input(int code)
{
	(void)code;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signals.exit_status = 130;
}

void	sig_input(void)
{	
	g_signals.sigint = 0;
	g_signals.exit_status = 0;
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sigint_input);
}
