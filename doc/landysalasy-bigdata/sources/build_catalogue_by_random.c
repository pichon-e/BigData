#include "catalogue.h"
#include "math_tool.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Build a catalogue with random data
*\fun \c build_catalogue_by_random
*\param nbr_element Number of value wanted.
*\param catalogue Data we use to contain the random data.
*\return 0 If fail, 1 if is good.
*/
uint8_t build_catalogue_by_random(long long nbr_element, t_catalogue *catalogue)
{
	if ((catalogue->data = MALLOC_OBJECT_INFO(nbr_element)) == NULL)
	{
		fprintf(stderr, "Error: fail to allocate [%d] element for the catalogue random.\n", nbr_element);
		return (0);
	}
	for (long long index = 0; index < nbr_element; ++index)
	{
		catalogue->data[index].coord[0] = cos(CONVERT_DEGREE_TO_RADIAN(rand() % 2000 - 1000)) * cos(CONVERT_DEGREE_TO_RADIAN(rand() % 2000 - 1000));
		catalogue->data[index].coord[1] = sin(CONVERT_DEGREE_TO_RADIAN(rand() % 2000 - 1000)) * cos(CONVERT_DEGREE_TO_RADIAN(rand() % 2000 - 1000));
		catalogue->data[index].coord[2] = sin(CONVERT_DEGREE_TO_RADIAN(rand() % 2000 - 1000));
		catalogue->data[index].id = index;
	}
	catalogue->pool_object = NULL;
	catalogue->nbr_element = nbr_element;
	return (1);
}