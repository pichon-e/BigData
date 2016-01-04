#include "HTM.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief free htm.
*\fun \b free_htm
*\param htm all data to free.
*/
void free_htm(t_HTM *htm)
{
	FREE_TRIXEL(htm->pool_trixels);
}