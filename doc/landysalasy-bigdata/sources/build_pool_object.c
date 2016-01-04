#include <stdint.h>
#include <stdlib.h>
#include "object.h"
#include "catalogue.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Build the pool object with the data from the catalogue.
*\fun \b build_pool_object
*\param catalogue Contain all data use to build the pool.
*\return 0 if fail, 1 if is good.
*/
uint8_t build_pool_object(t_catalogue *catalogue)
{
	long long index;

	if ((catalogue->pool_object = MALLOC_OBJECT(catalogue->nbr_element)) == NULL)
		return (0);
	for (index = 0; index <catalogue->nbr_element; ++index)
	{
		catalogue->pool_object[index].next = &catalogue->pool_object[(index + 1) % catalogue->nbr_element];
		catalogue->pool_object[index].prev = &catalogue->pool_object[(index - 1) % catalogue->nbr_element];
		catalogue->pool_object[index].trixel = NULL;
		catalogue->pool_object[index].info = &catalogue->data[index];
	}
	catalogue->pool_object[catalogue->nbr_element - 1].next = NULL;
	catalogue->pool_object[0].prev = NULL;
	return (1);
}

uint8_t build_pool_object_by_append_catalogue(t_catalogue *catalogue, t_catalogue *NN, t_catalogue *NR)
{
	uint32_t index = 0;

	if ((catalogue->pool_object = MALLOC_OBJECT(catalogue->nbr_element)) == NULL)
	{
		fprintf(stderr, "Error: the nbr element is too high for allocation [%d]\n", catalogue->nbr_element);
		return (0);
	}
	for (uint32_t index_nn = 0; index_nn < NN->nbr_element; ++index_nn)
	{
		catalogue->pool_object[index].next = &catalogue->pool_object[(index + 1) % catalogue->nbr_element];
		catalogue->pool_object[index].prev = &catalogue->pool_object[(index - 1) % catalogue->nbr_element];
		catalogue->pool_object[index].trixel = NULL;
		catalogue->pool_object[index].info = &NN->data[index_nn];
		++index;
	}
	for (uint32_t index_nr = 0; index_nr < NR->nbr_element; ++index_nr)
	{
		catalogue->pool_object[index].next = &catalogue->pool_object[(index + 1) % catalogue->nbr_element];
		catalogue->pool_object[index].prev = &catalogue->pool_object[(index - 1) % catalogue->nbr_element];
		catalogue->pool_object[index].trixel = NULL;
		catalogue->pool_object[index].info = &NR->data[index_nr];
		++index;
	}
	catalogue->pool_object[catalogue->nbr_element - 1].next = NULL;
	catalogue->pool_object[0].prev = NULL;
	return (1);
}