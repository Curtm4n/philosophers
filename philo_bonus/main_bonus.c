/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:51:41 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/04 14:06:01 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philo(int ac, char **av)
{
	t_data	data;
	int		ret;

	memset(&data, 0, sizeof(t_data));
	ret = init_struct(&data, ac, av);
	if (ret)
		return (error_type(ret));
	ret = start_simulation(&data);
	if (ret)
		return (error_case("Error in the simulation\n"));
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		return (ft_philo(ac - 1, av + 1));
	else
		return (error_case("Not the good amount of arguments\n"));
	return (0);
}
