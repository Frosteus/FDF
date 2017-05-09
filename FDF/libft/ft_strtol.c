/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 14:25:11 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 14:25:18 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_base(t_strtol *info, int base)
{
	while (ft_isspace(*info->s))
		info->s++;
	if (*info->s == '-')
	{
		info->neg = 1;
		info->s++;
	}
	else if (*info->s == '+')
		info->s++;
	if ((base == 0 || base == 16) && *info->s == '0' && (*(info->s + 1) == 'x'
	|| *(info->s + 1) == 'X'))
	{
		info->s += 2;
		base = 16;
	}
	else if ((base == 0 || base == 2) && *info->s == '0' &&
	(*(info->s + 1) == 'b' || *(info->s + 1) == 'B'))
	{
		info->s += 2;
		base = 2;
	}
	if (base == 0)
		base = (*info->s == '0' ? 8 : 10);
	return (base);
}

int		ft_convert(t_strtol *info, int base)
{
	if (ft_isdigit(*info->s))
	{
		info->c = *info->s;
		info->c -= '0';
	}
	else if (ft_isalpha(*info->s))
	{
		info->c = *info->s;
		info->c -= (ft_isupper(info->c) ? 'A' - 10 : 'a' - 10);
	}
	else
		return (1);
	if (info->c >= base)
		return (1);
	if (info->any < 0 || info->acc > info->cut
		|| (info->acc == info->cut && info->c > info->cutlim))
		info->any = -1;
	else
	{
		info->any = 1;
		info->acc *= base;
		info->acc += info->c;
	}
	info->s++;
	return (0);
}

long	ft_strtol(const char *str, char **end_p, int base)
{
	t_strtol info;

	info = (t_strtol){NULL, 0, 0, 0, 0, 0, 0};
	info.s = str;
	info.neg = 0;
	ft_check_base(&info, base);
	info.cut = info.neg ? -(unsigned long)LONG_MIN : LONG_MAX;
	info.cutlim = info.cut % (unsigned long)base;
	info.cut /= (unsigned long)base;
	info.acc = 0;
	info.any = 0;
	while (*info.s)
	{
		if (ft_convert(&info, base) == 1)
			break ;
	}
	if (info.any < 0)
		info.acc = (info.neg ? LONG_MIN : LONG_MAX);
	else if (info.neg)
		info.acc = -info.acc;
	if (end_p != 0)
		*end_p = (char *)(info.any ? info.s - 1 : str);
	return (info.acc);
}
