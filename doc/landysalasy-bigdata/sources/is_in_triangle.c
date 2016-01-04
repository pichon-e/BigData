#include "HTM.h"
#include "math_tool.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief test if the object is inside the triangle.
*\fun \b is_in_triangle
*\param object Object Tthe object use for the test.
*\param trixel Trixel Tthe trixel use for the test.
*\param htm The htm context with all usefull data.
*\return 0 if test fail, 1 if test pass.
*/
uint8_t is_in_triangle(t_object *object, t_trixel *trixel, t_HTM *htm)
{
	double v0_v1[NBR_COORD];
	double v1_v2[NBR_COORD];
	double v2_v0[NBR_COORD];

	math_cross_product(trixel->v0, trixel->v1, v0_v1);
	math_cross_product(trixel->v1, trixel->v2, v1_v2);
	math_cross_product(trixel->v2, trixel->v0, v2_v0);
	if (math_dot(v0_v1, object->info->coord) > 0 && math_dot(v1_v2, object->info->coord) > 0 && math_dot(v2_v0, object->info->coord) > 0)
		return (1);
	return (0);
}