/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:34 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:34 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWLINE_H
# define DRAWLINE_H

# include "cub3d.h"
# include "minimap.h"

void	drawline(mlx_image_t *image, t_vec2 p0, t_vec2 p1);
void	swap_point(t_vec2 *p0, t_vec2 *p1);

#endif
