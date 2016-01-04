#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Put an object into the trixel targeted.
*\fun \b put_object_into_trixel.
*\param object Element which we have to put into the trixel.
*\param dest_trixel Trixel of destination for the handle object.
*\param htm Representing the htm context.
*\return 0 if fail, 1 if work.
*/
uint8_t put_object_into_trixel(t_object *object, t_trixel *dest_trixel, t_HTM *htm)
{
	t_object *tmp;

	if (dest_trixel->nbr_object == 0)
	{
		pop_target_list_open_object(htm, object);
		put_front_list_close_object(htm, object);
		dest_trixel->objects = object;
	}
	else
	{
		if (dest_trixel->objects != NULL)
		{
			if (add_trixel_children(dest_trixel, htm) == 0)
				return (0);
			tmp = dest_trixel->objects;
			dest_trixel->objects = NULL;
			pop_target_list_close_object(htm, tmp);
			put_front_list_open_object(htm, tmp);
		}
	}
	object->trixel = dest_trixel;
	dest_trixel->nbr_object = dest_trixel->nbr_object + 1;
	return (1);
}
