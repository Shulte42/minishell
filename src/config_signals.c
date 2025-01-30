/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:30:09 by shulte            #+#    #+#             */
/*   Updated: 2025/01/30 10:31:13 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

void	handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

// void    config_signals(void)
// {
// 	struct sigaction	sigint;

// 	sigemptyset(&sigint.sa_mask);
// 	sigint.sa_handler = SIG_IGN;
// 	sigint.sa_flags = 0;
// 	handle_sigint();
// 	sigaction(SIGINT, &sigint, NULL);
// }