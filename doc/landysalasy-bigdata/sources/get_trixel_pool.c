#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Get one element from the trixel pool in htm.
*\fun \b get_trixel_pool
*\param htm Representing htm context.
*\return The next valid element into the trixel pool0
*/
t_trixel *get_trixel_pool(t_HTM *htm)
{
	if (htm->nbr_pool_object_use > htm->nbr_pool_object)
	{
		fprintf(stderr, "Error: No more memory in the pool.\n");
		return (NULL);
	}
	struct t_trixel *get = &htm->pool_trixels[htm->nbr_pool_object_use];
	htm->nbr_pool_object_use = htm->nbr_pool_object_use + 1;
	return (get);
}