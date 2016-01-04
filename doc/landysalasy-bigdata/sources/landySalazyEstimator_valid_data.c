#include "log.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Valid data file.
*\fun \b landySalazyEstimator_valid_data.
*\param expression String use for generate pertinant data.
*\param data Contain the nbr of element handle.
*/
void landySalazyEstimator_valid_data(char *expression, long long *data)
{
	static long long nbr_element = 0;

	nbr_element = nbr_element + 1;
	*data = (nbr_element % 3) == 0 ? nbr_element : -1;
}

