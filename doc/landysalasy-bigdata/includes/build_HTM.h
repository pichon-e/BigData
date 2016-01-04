#ifdef HTM_H_

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief inline function use for init the building of one trixel
*\fun \b init_trixel_coord
*\param trixel Element to be init
*/
INLINE void init_trixel_coord(t_trixel *trixel)
{
	trixel->v0[x] = 0;
	trixel->v0[y] = 0;
	trixel->v0[z] = 0;
	trixel->v1[x] = 0;
	trixel->v1[y] = 0;
	trixel->v1[z] = 0;
	trixel->v2[x] = 0;
	trixel->v2[y] = 0;
	trixel->v2[z] = 0;
}

#endif /*!HTM_H_*/