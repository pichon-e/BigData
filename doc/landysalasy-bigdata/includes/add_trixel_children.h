#ifdef HTM_H_

# include "math_tool.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief inline function use by htm for setting a trixel
*\fun \b set_sub_trixel
*\param trixel Element to be set
*\param v0 Vertex 0 use for setting
*\param v1 Vertex 1 use for setting
*\param v2 Vertex 2 use for setting
*/
INLINE void set_sub_trixel(t_trixel *trixel, double *v0, double *v1, double *v2)
{
	math_set_vector(trixel->v0, v0);
	math_set_vector(trixel->v1, v1);
	math_set_vector(trixel->v2, v2);
}

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief inline function use by htm for divided space into trixel
*\fun \b divided_space
*\param trixel Element to be divided
*\param v0 Vertex 0 use for division
*\param v1 Vertex 1 use for division
*\param v2 Vertex 2 use for division
*/
INLINE void divided_space(t_trixel **trixel, double *v0, double *v1, double *v2)
{
	double w0[NBR_COORD];
	double w1[NBR_COORD];
	double w2[NBR_COORD];
	double v1_v2[NBR_COORD];
	double v0_v2[NBR_COORD];
	double v0_v1[NBR_COORD];

	math_add_vector(v1, v2, v1_v2);
	math_add_vector(v0, v2, v0_v2);
	math_add_vector(v0, v1, v0_v1);
	math_normalize(v1_v2, w0);
	math_normalize(v0_v2, w1);
	math_normalize(v0_v1, w2);
	set_sub_trixel(trixel[0], v0, w2, w1);
	set_sub_trixel(trixel[1], v1, w0, w2);
	set_sub_trixel(trixel[2], v2, w1, w0);
	set_sub_trixel(trixel[3], w0, w1, w2);
# ifdef DEBUG
	fprintf(stderr, "trixel[0]\nV0 [%f], [%f], [%f]\n", trixel[0]->v0[x], trixel[0]->v0[y], trixel[1]->v0[z]);
	fprintf(stderr, "V1 [%f], [%f], [%f]\n", trixel[0]->v1[x], trixel[0]->v1[y], trixel[0]->v1[z]);
	fprintf(stderr, "V2 [%f], [%f], [%f]\n", trixel[0]->v2[x], trixel[0]->v2[y], trixel[0]->v2[z]);
	fprintf(stderr, "trixel[1]\nV0 [%f], [%f], [%f]\n", trixel[1]->v0[x], trixel[1]->v0[y], trixel[1]->v0[z]);
	fprintf(stderr, "V1 [%f], [%f], [%f]\n", trixel[1]->v1[x], trixel[1]->v1[y], trixel[1]->v1[z]);
	fprintf(stderr, "V2 [%f], [%f], [%f]\n", trixel[1]->v2[x], trixel[1]->v2[y], trixel[1]->v2[z]);
	fprintf(stderr, "trixel[2]\nV0 [%f], [%f], [%f]\n", trixel[2]->v0[x], trixel[2]->v0[y], trixel[2]->v0[z]);
	fprintf(stderr, "V1 [%f], [%f], [%f]\n", trixel[2]->v1[x], trixel[2]->v1[y], trixel[2]->v1[z]);
	fprintf(stderr, "V2 [%f], [%f], [%f]\n", trixel[2]->v2[x], trixel[2]->v2[y], trixel[2]->v2[z]);
	fprintf(stderr, "trixel[3]\nV0 [%f], [%f], [%f]\n", trixel[3]->v0[x], trixel[3]->v0[y], trixel[3]->v0[z]);
	fprintf(stderr, "V1 [%f], [%f], [%f]\n", trixel[3]->v1[x], trixel[3]->v1[y], trixel[3]->v1[z]);
	fprintf(stderr, "V2 [%f], [%f], [%f]\n", trixel[3]->v2[x], trixel[3]->v2[y], trixel[3]->v2[z]);
# endif /*!DEBUG*/
}

#endif /*!HTM_H_*/