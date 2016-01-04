#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Put an object into the children of the first trixel in open list.
*\fun \b put_object_into_children.
*\param htm Representing the htm context.
*\return 0 if fail, 1 if work.
*/
uint8_t put_object_into_children(t_HTM *htm)
{
	uint32_t index;
	t_trixel *trixel = (t_trixel *)htm->open_object->trixel;

	if (trixel->child_trixel != NULL)
	{
		for (index = 0; index < NBR_CUTTING_FACE; ++index)
		{
			if (is_in_triangle(htm->open_object, trixel->child_trixel[index], htm) == 1)
			{
				if ((put_object_into_trixel(htm->open_object, trixel->child_trixel[index], htm)) == 0)
					return (0);
				return (1);
			}
		}
#ifdef DEBUG
		fprintf(stderr, "Error : The object is not present in any face of the trixel.\n", htm->open_object->info->coord[x], htm->open_object->info->coord[y]);
		fprintf(stderr, "The location of object [%f] [%f].\n", htm->open_object->info->coord[x], htm->open_object->info->coord[y]);
#endif /*!DEBUG*/
		return (0);
	}
	fprintf(stderr, "finish\n");
	return (0);
}