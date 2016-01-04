#include <stdlib.h>
#include <stdio.h>
#include "object.h"
#include "math_tool.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Transform a string into usefull data.
*\fun \b landySalazyEstimator_get_data.
*\param expression String use for generate pertinant data.
*\param data Contain the data generate.
*/
void landySalazyEstimator_get_data(char *expression, t_object_info *data)
{
	static long long index = 0;
	static double alpha = 0.0;
	double beta = 0.0;

	int offset = (int)(index / 3);

	if ((index % 3) == 0)
	{
		data[offset].id = atoi(expression);
	}
	else if ((index % 3) == 1)
	{
		alpha = atof(expression);
	}
	else
	{
		beta = atof(expression);
		data[offset].coord[0] = cos(CONVERT_DEGREE_TO_RADIAN(alpha)) * cos(CONVERT_DEGREE_TO_RADIAN(beta));
		data[offset].coord[1] = sin(CONVERT_DEGREE_TO_RADIAN(alpha)) * cos(CONVERT_DEGREE_TO_RADIAN(beta));
		data[offset].coord[2] = sin(CONVERT_DEGREE_TO_RADIAN(beta));
	}
	index = index + 1;
}