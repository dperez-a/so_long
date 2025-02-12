/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:45:06 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 11:45:08 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	animate_enemy(t_game *game, int dir)
{
	int	i;

	i = 0;
	while (i < 10000000)
		i++;
	if (dir)
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
				ENEMY_RIGHT,
				&game->map->img_width, &game->map->img_height);
	}
	else
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
				ENEMY_LEFT,
				&game->map->img_width, &game->map->img_height);
	}
}
