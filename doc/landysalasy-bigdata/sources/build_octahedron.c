#include <stdlib.h>
#include "HTM.h"

static double vertices[NBR_VERTICES_OCTAHEDRON][NBR_COORD] =
{
	{0, 0, 1},
	{1, 0, 0},
	{0, 1, 0},
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, -1}
};

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Build the octahedron into the htm.
*\fun \b build_octahedron
*\param htm Context use which containt the octahedron.
*\return 0 If fail, 1 if is good.
*/
uint8_t build_octahedron(t_HTM *htm)
{
	uint32_t index;

	for (index = 0; index < NBR_FACE_OCTAHEDRON; ++index)
	{
		htm->octahedron[index].child_trixel = NULL;
		htm->octahedron[index].nbr_object = 0;
		htm->octahedron[index].objects = NULL;
	}
	set_surface_octahedron(&htm->octahedron[S0], vertices[v1], vertices[v5], vertices[v2]);
	set_surface_octahedron(&htm->octahedron[S1], vertices[v2], vertices[v5], vertices[v3]);
	set_surface_octahedron(&htm->octahedron[S2], vertices[v3], vertices[v5], vertices[v4]);
	set_surface_octahedron(&htm->octahedron[S3], vertices[v4], vertices[v5], vertices[v1]);
	set_surface_octahedron(&htm->octahedron[N0], vertices[v1], vertices[v0], vertices[v4]);
	set_surface_octahedron(&htm->octahedron[N1], vertices[v4], vertices[v0], vertices[v3]);
	set_surface_octahedron(&htm->octahedron[N2], vertices[v3], vertices[v0], vertices[v2]);
	set_surface_octahedron(&htm->octahedron[N3], vertices[v2], vertices[v0], vertices[v1]);
	return (1);
}