/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:01:28 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/14 12:57:30 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MALLOC_FAILED "Malloc failed"
# define MLX_INITIALIZE "mlx init failed"
# define MLX_WINDOWS "Windows failed"

# define NBR_AC "missing args, or too much arg"
# define MAP "map failed"

# define MAP_ITEM "MISSING ITEM in map"
# define MAP_FORMAT "map format WRONG"
# define MAP_WALLS "MISSING WALLS"
# define MAP_EXITS  "too much or too few exit"
# define MAP_COINS  "NO COINS"
# define MAP_PLAYER "where is the player HUH?"

# define FLOODFILL "you cant get all coins"

# define FILE_EXTENSION "Extension must be .ber"
# define FILE_OPEN "Cant open file map"
# define FILE_EMPTY "map empty"

# define MLX_WALL "cant open wall img"
# define MLX_FLOOR "cant open floor img"
# define MLX_PLAYER "cant open player img"
# define MLX_COINS "cant open coins img"
# define MLX_EXIT "cant open exit img"

#endif
