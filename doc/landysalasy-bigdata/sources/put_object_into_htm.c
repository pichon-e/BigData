#include <stdlib.h>
#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Put an object into the htm.
*\fun \b put_object_into_htm.
*\param htm Representing the htm context.
*\return 0 if fail, 1 if work.
*/
uint8_t put_object_into_htm(t_HTM *htm)
{
	if (htm->nbr_open_object > 0)
	{
		if (htm->open_object->trixel == NULL)
		{
			if (put_object_into_octahedron(htm) == 0)
				return (0);
		}
		else
		{
			if (put_object_into_children(htm) == 0)
				return (0);
		}
		return (1);
	}
	return (0);
}