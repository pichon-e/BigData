#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Put an object into the octahedron.
*\fun \b put_object_into_octahedron.
*\param htm Representing the htm context.
*\return 0 if fail, 1 if work.
*/
uint8_t put_object_into_octahedron(t_HTM *htm)
{
	uint32_t index;

	for (index = 0; index < NBR_FACE_OCTAHEDRON; ++index)
	{
		if (is_in_triangle(htm->open_object, &htm->octahedron[index], htm) == 1)
		{
			if ((put_object_into_trixel(htm->open_object, &htm->octahedron[index], htm)) == 0)
				return (0);
			return (1);
		}
	}
#ifdef DEBUG
	fprintf(stderr, "Error : The object %d\n[coord-x(%lf),\n coord-y(%lf),\n coord-z(%lf)]\n, is not present in any face of the octahedron.\n", htm->open_object->info->id, htm->open_object->info->coord[x], htm->open_object->info->coord[y], htm->open_object->info->coord[z]);
#endif /*!DEBUG*/
	return (0);
}