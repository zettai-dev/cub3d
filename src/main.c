/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 23:31:17 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "cast.h"

int			main(int c, char **v)
{
	if (c != 2)
		return (1);
	init_scene(v[1]);
	if (g_error)
	{
		print_error();
		return (0);
	}
	init_window();
	if (g_error)
	{
		print_error();
		return (0);
	}
	print_scene();
	handle_keys(-1, 0);
	mlx_hook(g_window.win_ptr, 2, 1L << 0, handle_keys, 0);
	mlx_loop(g_window.mlx_ptr);
	return (0);
}
