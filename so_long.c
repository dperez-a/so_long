/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-a <dperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:13 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/11/22 11:26:13 by dperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	update(t_game *game)
{
	if (!game)
		exit(0);
	if (game->enemy->count)
		move_enemy(game);
	animate_enemy(game, game->enemy->dir);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
	return (0);
}

int	ft_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit (0);
	return (0);
}

void	init_game(t_game *game)
{
	init_img(game);
	init_player(game);
	init_enemy(game);
	check_map(game);
	draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_putstr_fd("Error : ./so_long <map_path>\n", 1);
	check_path(argv[1]);
	game = ft_calloc(1, sizeof(t_game));
	game->mlx_ptr = mlx_init();
	if (!init_map(game, argv[1]))
		exit_game(game, "Error: Invalid map\n", 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width,
			game->map->height + SS * 2, "so_long");
	init_game(game);
	mlx_key_hook(game->win_ptr, move_player, game);
	mlx_loop_hook(game->mlx_ptr, update, game);
	mlx_hook(game->win_ptr, 17, 0, ft_destroy_window, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
