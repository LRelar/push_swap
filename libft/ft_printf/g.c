/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:31:08 by sstark            #+#    #+#             */
/*   Updated: 2019/10/31 19:18:25 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	g_edit(t_param *lst, t_list **ml)
{
	char *str;

	if (!ft_charinstr("gG", lst->type))
		return ;
	lst->precision = lst->precision == -1 ? 4 : lst->precision;
	pr_f(lst, ml);
	str = lst->str;
	while (*str != '.')
		str++;
	str += lst->precision;
	while (*str == '0')
	{
		if (*(str + 1) < '5' || *(str + 1) == '\0')
			lst->precision--;
		str--;
	}
	lst->type--;
}
