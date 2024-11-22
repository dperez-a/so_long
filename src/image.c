/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:44:25 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 11:44:27 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_img(t_game *game)
{
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, WALL,
			&game->map->img_width, &game->map->img_height);
	game->map->empty_img = mlx_xpm_file_to_image(game->mlx_ptr, EMPTY,
			&game->map->img_width, &game->map->img_height);
	game->map->c_img = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE, &game->map->img_width, &game->map->img_height);
	game->map->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&game->map->img_width, &game->map->img_height);
}
