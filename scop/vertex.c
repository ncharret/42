/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 20:47:29 by ncharret          #+#    #+#             */
/*   Updated: 2015/04/28 20:57:52 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_triangle(GLfloat *vtx)
{
	printf("T |   X  |   Y   |  Z  \n-----------------------\n");
	printf("1 | %.02f | % .02f | %.02f\n",
			vtx[0], vtx[1], vtx[2]);
	printf("2 | %.02f | % .02f | %.02f\n",
			vtx[3], vtx[4], vtx[5]);
	printf("3 | %.02f | % .02f | %.02f\n",
			vtx[6], vtx[7], vtx[8]);
}
