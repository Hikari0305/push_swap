/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:01:30 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/07 14:03:43 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (!args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	**prepare_arguments(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	char	**args;
	int		i;

	joined = ft_strdup("");
	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (free(joined), NULL);
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
	}
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}
