/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:41:32 by sishizaw          #+#    #+#             */
/*   Updated: 2024/09/22 13:44:53 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_cr_ci(double cr, double ci)
{
	if (cr < -2.0 || cr > 2.0 || ci < -2.0 || ci > 2.0)
	{
		write(1, "Error: cr and ci must be between -2.0 and 2.0.\n", 48);
		return (0);
	}
	return (1);
}

double	ft_atof_integer(const char **str, int *sign)
{
	double	result;

	result = 0;
	*sign = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		if (result > (1.7e+308 - (**str - '0')) / 10)
		{
			write(1, "Error: Value out of range for a double.\n", 39);
			exit(1);
		}
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	ft_atof_fraction(const char **str)
{
	double	fraction;
	int		divisor;

	fraction = 0;
	divisor = 1;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			fraction = fraction * 10 + (**str - '0');
			divisor *= 10;
			(*str)++;
		}
	}
	return (fraction / divisor);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;

	result = ft_atof_integer(&str, &sign);
	result += ft_atof_fraction(&str);
	result *= sign;
	return (result);
}

