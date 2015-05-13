/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 17:29:10 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/13 17:00:05 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_rotation_matrix(matrix result, float x, float y, float z)
{
	matrix mt1;
	matrix mt2;
	matrix mt3;

	//create_rx_matrix(result, x);
	create_rz_matrix(mt1, x);
	create_ry_matrix(mt2, y);
	multiply_matrix(mt3, mt1, mt2);
	create_rx_matrix(mt1, z);
	multiply_matrix(result, mt3, mt1);
}
void	draw_mesh(t_mesh mesh, GLuint *ModelMatrices, GLuint ProjectionMatrix, GLuint ViewMatrix)
{
	matrix mtx;
	matrix mt1;
	matrix mt2;
	t_camconfig cfg;

	cfg.near = 0.1;
	cfg.far = 100.f;
	cfg.fov = 45.f;
	cfg.ratio = 800.f/600.f;
	GLuint vtx[mesh.vertex_count];
	ft_memcpy(vtx, mesh.vtx, mesh.vertex_count * sizeof(GLfloat));
	//scale & position & rotation	
	create_scale_matrix(mt1, mesh.scale);
	create_translation_matrix(mesh.world_position, mtx);
	glUniformMatrix4fv(ModelMatrices[0], 1, GL_FALSE, &mt1[0][0]);
	glUniformMatrix4fv(ModelMatrices[1], 1, GL_FALSE, &mtx[0][0]);
	create_projection_matrix(mt1, cfg);
	glUniformMatrix4fv(ProjectionMatrix, 1, GL_FALSE, &mt1[0][0]);
	create_lookat_matrix(mtx, init_vector(0, 0, 2), init_vector(0, 0, 0), init_vector(0, 1, 0));
	glUniformMatrix4fv(ViewMatrix, 1, GL_FALSE, &mtx[0][0]);
	//colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(GLfloat), mesh.colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	//position
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(GLfloat), vtx, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//draw
	glDrawArrays(GL_TRIANGLES, 0, mesh.vertex_count);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
