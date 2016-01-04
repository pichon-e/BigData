#ifdef HTM_H_

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief inline function use set all vertex in the octahedron
*\fun \b set_surface_octahedron
*\param trixel Element to be set
*\param v0 Element use for the setting
*\param v1 Element use for the setting
*\param v2 Element use for the setting
*/
INLINE void set_surface_octahedron(t_trixel *trixel, double *v0, double *v1, double *v2)
{
	int index;

	for (index = 0; index < NBR_COORD; ++index)
	{
		trixel->v0[index] = v0[index];
		trixel->v1[index] = v1[index];
		trixel->v2[index] = v2[index];
	}
}

#endif /*!HTM_H_*/