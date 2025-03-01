/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/27 22:29:58 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "cast.h"

static void	args_error(void)
{
	g_error |= ARGS_ERROR;
	game_over();
}

static int	x_pressed(void *params)
{
	(void)params;
	game_over();
	return (0);
}

static int	check_extension(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (s[--len] == 'b' && s[--len] == 'u' &&
			s[--len] == 'c' && s[--len] == '.');
}

int			main(int c, char **v)
{
	if (c < 2 || c > 3)
		args_error();
	if (!check_extension(v[1]))
		args_error();
	if (c == 3 && ft_strncmp(v[2], "--save", 7))
		args_error();
	if (c == 3)
		g_scene.save = 1;
	init_scene(v[1]);
	if (g_error)
		game_over();
	init_window();
	if (g_error)
		game_over();
	handle_keys(-1, 0);
	mlx_hook(g_window.win_ptr, 2, 1, handle_keys, 0);
	mlx_hook(g_window.win_ptr, 17, 0, x_pressed, 0);
	mlx_loop(g_window.mlx_ptr);
	return (0);
}
