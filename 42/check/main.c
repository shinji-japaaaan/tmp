/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:28:32 by sishizaw          #+#    #+#             */
/*   Updated: 2024/09/22 14:36:08 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_data *d)
{
	ft_memset(d->img_data, 0, WIDTH * HEIGHT * (d->bpp / 8));
	if (d->fractal_type == 0)
		draw_mandelbrot(d);
	else if (d->fractal_type == 1)
		draw_julia(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}

void	judge_fractal_type(t_data *d, char *fractal_name, char **argv)
{
	if (ft_strncmp(fractal_name, "mandelbrot", 10) == 0)
	{
		d->fractal_type = 0;
	}
	else if (ft_strncmp(fractal_name, "julia", 5) == 0)
	{
		d->fractal_type = 1;
		if (argv[2] && argv[3])
		{
			d->cr = ft_atof(argv[2]);
			d->ci = ft_atof(argv[3]);
			if (!validate_cr_ci(d->cr, d->ci))
				exit(1);
		}
		else
		{
			d->cr = -1;
			d->ci = 0.28;
		}
	}
}

void	set_up_fractal(t_data *d)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	d->img_ptr = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->img_data = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->line, &d->endian);
	d->zoom = 1.0;
	d->x_mo = 0.0;
	d->y_mo = 0.0;
	d->max_iter = 50;
}

int	compare(char *arg)
{
	if (ft_strncmp(arg, "mandelbrot", 10) == 0)
		return (1);
	else if (ft_strncmp(arg, "julia", 5) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc < 2 || argc > 4 || !(compare(argv[1])))
	{
		write(2, "Usage: ./fractol <mandelbrot/julia> [<cr> <ci>]\n", 48);
		return (1);
	}
	set_up_fractal(&d);
	judge_fractal_type(&d, argv[1], argv);
	draw_fractal(&d);
	mlx_key_hook(d.win_ptr, handle_key, &d);
	mlx_mouse_hook(d.win_ptr, handle_mouse, &d);
	mlx_hook(d.win_ptr, 17, 0, close_window, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
