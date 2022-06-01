/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 04:18:54 by amounadi          #+#    #+#             */
/*   Updated: 2022/06/01 15:17:08 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	equal_place(char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (s[i] == '=')
			return (i);
	return (i);
}

void	copy_data_env(char **ev)
{
	blt_export(ev, &g_glob.env, 1, 3);
	blt_export(ev, &g_glob.local, 1, 2);
}

char	**list_to_str(t_list *head)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(ft_lstsize(head) + 1, sizeof(char *));
	while (head)
	{
		str[i] = ft_strjoin_freed(ft_strdup(head->key), "=", 1);
		str[i] = ft_strjoin_freed(str[i], head->value, 1);
		head = head->next;
		i++;
	}
	return (str);
}

void	ft_sort_arry(char **env)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (env && env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
