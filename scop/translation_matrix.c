/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:37:49 by ncharret          #+#    #+#             */
/*   Updated: 2015/04/28 19:55:51 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void create_translation_matrix(t_vector vtc, matrix mtx)
{
	mtx[0][0] = 1; mtx[0][1] = 0; mtx[0][2] = 0; mtx[0][3] = vtc.x;
	mtx[1][0] = 0; mtx[1][1] = 1; mtx[1][2] = 0; mtx[1][3] = vtc.y;
	mtx[2][0] = 0; mtx[2][1] = 0; mtx[2][2] = 1; mtx[2][3] = vtc.z;
	mtx[3][0] = 0; mtx[3][1] = 0; mtx[3][2] = 0; mtx[3][3] = 1;
}