#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Build the pool node into the htm context.
*\fun \b build_pool_node
*\param htm Data representing htm context.
*\return Start of the pool node, NULL if fail.
*/
t_node *build_pool_node(t_HTM *htm)
{
	uint32_t index;

	htm->open_node = NULL;
	htm->nbr_open_node = 0;
	htm->nbr_pool_node = pow(htm->depth, 4);
	if ((htm->pool_node = MALLOC_NODE(htm->nbr_pool_node)) == NULL)
		return (NULL);
	for (index = 0; index < htm->nbr_pool_node; ++index)
	{
		htm->pool_node[index].next = &htm->pool_node[(index + 1) % htm->nbr_pool_node];
		htm->pool_node[index].prev = &htm->pool_node[(index - 1) % htm->nbr_pool_node];
		htm->pool_node[index].data = NULL;
	}
	htm->pool_node[htm->nbr_pool_node - 1].next = NULL;
	htm->pool_node[0].prev = NULL;
	return (htm->pool_node);
}