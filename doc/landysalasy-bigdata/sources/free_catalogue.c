#include "catalogue.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief free catalogue.
*\fun \b free_catalogue
*\param catalogue all data to free.
*/
void free_catalogue(t_catalogue *catalogue)
{
	FREE_OBJECT(catalogue->pool_object);
	FREE_OBJECT_INFO(catalogue->data);
	catalogue->nbr_element = 0;
}