/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:18:15 by shulte            #+#    #+#             */
/*   Updated: 2025/01/08 14:26:12 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

void    ft_parsing_loop(t_shell *shell)
{
    ft_quote_checker(shell->input);
        ft_tokenization(shell);
}

void    ft_input_analizes(t_shell *shell)
{
    ft_parsing_loop(shell);
}