#include "HTM.h"
#include "math_tool.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Add new trixels into the trixel parameter.
*\fun \b Add_trixel_children
*\param Trixel the trixel father which we add new trixels.
*\param Htm data which contain the HTM context.
*\return 0 if fail, 1 if is good.
*/
uint8_t add_trixel_children(t_trixel *trixel, t_HTM *htm)
{
	uint32_t index;

	if ((trixel->child_trixel = (t_trixel **)malloc(sizeof(*trixel->child_trixel) * NBR_CUTTING_FACE)) == NULL)
		return (0);
	for (index = 0; index < NBR_CUTTING_FACE; ++index)
	{
		if ((trixel->child_trixel[index] = get_trixel_pool(htm)) == NULL)
			return (0);
		trixel->child_trixel[index]->child_trixel = NULL;
		trixel->child_trixel[index]->nbr_object = 0;
		trixel->child_trixel[index]->objects = NULL;
	}
	divided_space(trixel->child_trixel, trixel->v0, trixel->v1, trixel->v2);
	return (1);
}