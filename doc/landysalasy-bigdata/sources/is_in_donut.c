#include "HTM.h"
#include "math_tool.h"



/* Reference : http://www.les-mathematiques.net/phorum/read.php?8,892567,893055*/
static uint8_t intersection_between_vec_and_circle(double *A, double *B, double *C, double R)
{
	double dx = B[x] - A[x];
	double dy = B[y] - A[y];
	double dz = B[z] - A[z];
	double a = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
	double b = 2 * (dx * (A[x] - C[x]) + dy * (A[y] - C[y]) + dz * (A[z] - C[z]));
	double c = pow(A[x] - C[x], 2) + pow(A[y] - C[y], 2) + pow(A[z] - C[z], 2) - pow(R, 2);
	double delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
		return (1);
	return (0);
}

static double calc_bounded(t_trixel *trixel, double *vb)
{
	double v1_v0xv2_v1[NBR_COORD];
	double v1_v0[NBR_COORD];
	double v2_v1[NBR_COORD];
	double result[NBR_COORD];

	math_dec_vector(trixel->v1, trixel->v0, v1_v0);
	math_dec_vector(trixel->v2, trixel->v1, v2_v1);
	math_cross_product(v1_v0, v2_v1, v1_v0xv2_v1);
	math_div_by_value(v1_v0xv2_v1, math_norm(v1_v0xv2_v1), result);
	math_set_vector(vb, result);
	return (math_dot(trixel->v0, result));
}

static enum result_donut is_into_triangle(t_object *object, t_trixel *trixel)
{
	double v0xv1[NBR_COORD];
	double v1xv2[NBR_COORD];
	double v2xv0[NBR_COORD];

	math_cross_product(trixel->v0, trixel->v1, v0xv1);
	math_cross_product(trixel->v1, trixel->v2, v1xv2);
	math_cross_product(trixel->v2, trixel->v0, v2xv0);
	if (math_dot(v0xv1, trixel->v0) >= 0 && math_dot(v1xv2, trixel->v1) >= 0 && math_dot(v2xv0, trixel->v2) >= 0)
		return (partial);
	return (outside);
}

static uint8_t is_intersect(t_object *object, t_trixel *trixel, double size_donuts, double *vb)
{
	double hypotenus_v = sqrt(pow(size_donuts, 2));
	double angle_v = 1.0 / hypotenus_v;
	double angle_b = math_angle_between_vec(trixel->v0, vb);
	double angle_vb = math_angle_between_vec(object->info->coord, vb);
	
	if (angle_vb < (angle_v + angle_b))
		return (1);
	return (0);
}

static uint8_t is_donut_is_in_triangle(t_object *object, t_trixel *trixel)
{
	double v0xv1[NBR_COORD];
	double v1xv2[NBR_COORD];
	double v2xv0[NBR_COORD];

	math_cross_product(trixel->v0, trixel->v1, v0xv1);
	math_cross_product(trixel->v1, trixel->v2, v1xv2);
	math_cross_product(trixel->v2, trixel->v0, v2xv0);
	if (!(math_dot(v0xv1, object->info->coord)) && !(math_dot(v1xv2, object->info->coord)) && !(math_dot(v2xv0, object->info->coord)))
		return (1);
	return (0);
}

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief test if the trixel is inside the donuts.
*\fun \b is_in_donut
*\param object The object use for the test.
*\param trixel The trixel use for the test.
*\param size_donuts Indicate the size of circle.
*\return If the trixel is inside, partiale or outside of the circle
*/
enum result_donut is_in_donut(t_object *object, t_trixel *trixel, double size_donut)
{
	uint8_t is_in = 0;
	double theta = 0;
	double vb[NBR_COORD];

	if (math_dot(object->info->coord, trixel->v0) > size_donut)
		is_in += 1;
	if (math_dot(object->info->coord, trixel->v1) > size_donut)
		is_in += 1;
	if (math_dot(object->info->coord, trixel->v2) > size_donut)
		is_in += 1;
	if (is_in == 3)
		return (full);
	else if (is_in > 0)
		return (partial);
	else
	{
		if (is_intersect(object, trixel, size_donut, vb) == 1)
		{
			if (intersection_between_vec_and_circle(trixel->v0, trixel->v1, object->info->coord, size_donut) == 1)
				return (partial);
			if (intersection_between_vec_and_circle(trixel->v1, trixel->v2, object->info->coord, size_donut) == 1)
				return (partial);
			if (intersection_between_vec_and_circle(trixel->v2, trixel->v0, object->info->coord, size_donut) == 1)
				return (partial);
			if (is_donut_is_in_triangle(object, trixel) == 1)
				return (partial);
			else
				return (outside);
		}
		else
			return (outside);
	}
}