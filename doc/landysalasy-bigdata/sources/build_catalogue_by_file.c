#include "catalogue.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Build a catalogue with the file indicate in parameter
*\fun \b Build_catalogue_by_file
*\param file_name file name use for contain all data of the file targeted.
*\param catalogue Data we use to contain the file data.
*\return 0 If fail, 1 if is good.
*/
uint8_t build_catalogue_by_file(char const *file_name, t_catalogue *catalogue)
{
	if (load_data(file_name, &landySalazyEstimator_valid_data, &catalogue->nbr_element) == 0)
		return (0);
	if (catalogue->nbr_element != INVALID_DATA)
	{
		if ((catalogue->data = MALLOC_OBJECT_INFO((size_t)catalogue->nbr_element)) == NULL)
			return (0);
		load_data(file_name, &landySalazyEstimator_get_data, catalogue->data);
		catalogue->nbr_element = catalogue->nbr_element / 3;
	}
	catalogue->pool_object = NULL;
	return (1);
}