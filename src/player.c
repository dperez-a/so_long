/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-a <dperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:27 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/11/20 15:14:55 by dperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_player(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	get_players_cords(game);
	game->player->img_up = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_UP, &game->player->width, &game->player->height);
	game->player->img_down = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_DOWN, &game->player->width, &game->player->height);
	game->player->img_left = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_LEFT, &game->player->width, &game->player->height);
	game->player->img_right = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_RIGHT, &game->player->width, &game->player->height);
	game->player->img = game->player->img_left;
}

void	get_players_cords(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height / SS)
	{
		j = 0;
		while (j < game->map->width / SS)
		{
			if (game->map->matrix[i][j] == 'P')
			{
				game->player->count++;
				game->player->x = j;
				game->player->y = i;
			}
			if (game->map->matrix[i][j] == 'C')
				game->map->coins++;
			if (game->map->matrix[i][j] == 'E')
				game->map->exits++;
			j++;
		}
		i++;
	}
}

void	check_legal(t_game *game)
{
	if (game->map->matrix[(game->player->y - 1)][(game->player->x)] == '1')
		game->player->go_up = 0;
	else
		game->player->go_up = 1;
	if (game->map->matrix[(game->player->y + 1)][(game->player->x)] == '1')
		game->player->go_down = 0;
	else
		game->player->go_down = 1;
	if (game->map->matrix[(game->player->y)][(game->player->x - 1)] == '1')
		game->player->go_left = 0;
	else
		game->player->go_left = 1;
	if (game->map->matrix[(game->player->y)][(game->player->x + 1)] == '1')
		game->player->go_right = 0;
	else
		game->player->go_right = 1;
}

int	move_player(int keynum, t_game *game)
{
	if (keynum == 65307)
		exit_game(game, "You quit the game", 0);
	check_legal(game);
	if (keynum == 65362 || keynum == 119)
		move_up(game);
	if (keynum == 65364 || keynum == 115)
		move_down(game);
	if (keynum == 65361 || keynum == 97)
		move_left(game);
	if (keynum == 65363 || keynum == 100)
		move_right(game);
	return (0);
}
