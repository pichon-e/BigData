#ifndef MATH_TOOL_H_
# define MATH_TOOL_H_

# include <math.h>
# include "object.h"
# include "portability.h"

enum TriCoord
{
	x = 0,
	y,
	z
};

# define NBR_COORD 3
# define CONVERT_DEGREE_TO_RADIAN(x) (3.141592 * (x) / 180.0)

INLINE double math_norm(double *u)
{
	return (sqrt(pow(u[x], 2) + pow(u[y], 2) + pow(u[z], 2)));
}

INLINE void math_normalize(double *u, double *w)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		w[index] = u[index] / math_norm(u);
}

INLINE double math_dot(double *u, double *v)
{
	return (u[x] * v[x] + u[y] * v[y] + u[z] * v[z]);
}

INLINE void math_vector(double *u, double *v, double *r)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		r[index] = v[index] - u[index];
}

INLINE void math_add_vector(double *u, double *v, double *w)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		w[index] = u[index] + v[index];
}

INLINE void math_dec_vector(double *u, double *v, double *w)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		w[index] = u[index] - v[index];
}

INLINE void math_mult_vector(double *u, double *v, double *w)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		w[index] = u[index] * v[index];
}

INLINE void math_mult_by_value(double *u, double v, double *w)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		w[index] = u[index] * v;
}

INLINE void math_div_by_value(double *u, double v, double *w)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		w[index] = u[index] / v;
}


INLINE void math_set_vector(double *u, double *v)
{
	uint8_t index;

	for (index = 0; index < NBR_COORD; ++index)
		u[index] = v[index];
}

INLINE void math_cross_product(double *u, double *v, double *r)
{
	r[x] = u[y] * v[z] - u[z] * v[y];
	r[y] = u[z] * v[x] - u[x] * v[z];
	r[z] = u[x] * v[y] - u[y] * v[x];
}

INLINE double math_angle_between_vec(double *u, double *v)
{
	return (acos(math_dot(u, v) / (math_norm(u) * math_norm(v))));
}
#endif /*!MATH_TOOL_H_*/