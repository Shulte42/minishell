/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:18:15 by shulte            #+#    #+#             */
/*   Updated: 2025/01/16 15:11:21 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

void    ft_parsing_loop(t_shell *data)
{
    if (ft_quote_checker(data->input))  
    {
        data->input = expand_envvar(data, data->input);
        ft_quote_handle(data);
        ft_tokenization(data);
    }
}

void    ft_input_analizes(t_shell *data)
{
    ft_parsing_loop(data);
}
