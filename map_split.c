/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:17:00 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/09/29 15:33:57 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*ft_strndup(char *s1, int n)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * n);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, (char *)s1, n);
	return (s2);
}

int	countwords(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while ((char)s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char	**freesplits(char **split, int k)
{
	if (split[k] == NULL)
	{
		while (k >= 0)
		{
			free(split[k]);
			k--;
		}
		free(split);
		return (NULL);
	}
	return (split);
}

char	**fillmatrix(char *s, char c, char **split)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			split[k] = ft_strndup(s + j, i - j + 1);
			if (freesplits(split, k) == NULL)
				return (NULL);
			k++;
		}
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char *s, char c)
{
	char	**split;

	split = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = fillmatrix(s, c, split);
	if (split == NULL)
		return (NULL);
	return (split);
}
