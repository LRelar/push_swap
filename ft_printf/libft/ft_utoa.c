/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:11:24 by sstark            #+#    #+#             */
/*   Updated: 2019/09/18 16:11:26 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_utoa(unsigned long long int n, char rez[21])
{
	int i;

	i = 20;
	while (n)
	{
		rez[i--] = n % 10;
		n /= 10;
	}
}
