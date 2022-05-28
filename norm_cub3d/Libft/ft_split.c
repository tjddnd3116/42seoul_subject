/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:36:24 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:07:43 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sep_cnt(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static void	ft_free(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

static void	ft_putin(char const *s, char *arr, int from, int i)
{
	int	index;

	index = 0;
	while (from < i)
	{
		arr[index] = s[from];
		index++;
		from++;
	}
	arr[index] = '\0';
}

static void	ft_sep(char const *s, char c, char **arr)
{
	int	index;
	int	i;
	int	from;

	index = 0;
	i = 0;
	from = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			from = i - 1;
			while (s[i] && s[i] != c)
				i++;
			arr[index] = (char *)malloc((i - from + 1) * sizeof(char));
			if (!arr[index])
			{
				ft_free(arr);
				return ;
			}
			ft_putin(s, arr[index], from, i);
			index++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	sep_cnt;

	if (s == NULL)
		return (NULL);
	sep_cnt = ft_sep_cnt(s, c);
	arr = (char **)malloc((sep_cnt + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_sep(s, c, arr);
	if (arr == NULL)
		return (NULL);
	arr[sep_cnt] = NULL;
	return (arr);
}
