/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:04:06 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/03 19:12:03 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_case(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, "Error\n", 6);
	write(2, str, i);
	return (1);
}

int	error_type(int ret)
{
	if (ret == 1)
		error_case("Problem with the parameters\n");
	if (ret == 2)
		error_case("Problem allocating memory for philosophers\n");
	if (ret == 3)
		error_case("Error when initializing semaphores\n");
	return (1);
}
