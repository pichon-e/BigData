#include "HTM.h"
#include "catalogue.h"

static uint8_t build_pool_trixel(long long nbr_object, t_HTM *htm)
{
	int index;

	if ((htm->pool_trixels = MALLOC_TRIXEL(nbr_object)) == NULL)
		return (0);
	for (index = 0; index < nbr_object; ++index)
	{
		htm->pool_trixels[index].child_trixel = NULL;
		htm->pool_trixels[index].nbr_object = 0;
		htm->pool_trixels[index].objects = NULL;
		init_trixel_coord(&htm->pool_trixels[index]);
	}
	htm->nbr_pool_object_use = 0;
	htm->nbr_pool_object = nbr_object;
	return (1);
}

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Use to build the htm context
*\fun \b build_HTM
*\param Htm data which contain the HTM context.
*\param Catalogue use to fill the htm.
*\return If fail 0, if 1 is good.
*/
uint8_t build_HTM(t_HTM *htm, t_catalogue *catalogue)
{
	if ((build_pool_trixel(100000, htm)) == 0)
		return (0);
	htm->depth = 4;
	htm->close_object = NULL;
	htm->nbr_close_object = 0;
	htm->open_object = catalogue->pool_object;
	htm->nbr_open_object = catalogue->nbr_element;
	build_octahedron(htm);
	return (1);
}