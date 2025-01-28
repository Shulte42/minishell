/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:18:15 by shulte            #+#    #+#             */
/*   Updated: 2025/01/14 14:29:07 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

void    ft_parsing_loop(t_shell *data)
{
    if (ft_quote_checker(data->input))
    {
        data->input = expand_envvar(data, data->input);
        ft_tokenization(data);
    }
}

void    ft_input_analizes(t_shell *data)
{
    ft_parsing_loop(data);
}
