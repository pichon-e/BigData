#include "HTM.h"

static uint8_t is_in_donut_2_point(double *p1, double *c)
{
	double d[NBR_COORD];
	double size_d;
	size_t index;
	math_vector(p1, c, d);
	size_d = math_norm(d);
	if (size_d <= DONUT_SIZE_UP && size_d >= DONUT_SIZE_DOWN)
		return (1);
	return (0);
}

static void load_child_in_open_element(t_trixel *trixel, t_HTM *htm)
{
	uint8_t index;
	t_node *value;

	for (index = 0; index < NBR_CUTTING_FACE; ++index)
	{
		value = pop_front_list_pool_node(htm);
		if (value != NULL)
		{
			value->data = trixel->child_trixel[index];
			put_back_list_open_node(htm, value);
		}
	}
}

static long long running_face_of_hexadron(t_object *object, t_trixel *trixel, t_HTM *htm)
{
	long long nbr_pair = 0;
	enum result_donut ret;
	enum result_donut ret2;
	t_node *value;
	t_node *to_free;

	if ((to_free = build_pool_node(htm)) == NULL)
		return (-1);
	value = pop_front_list_pool_node(htm);
	if (value == NULL)
		return (-1);
	value->data = trixel;
	put_back_list_open_node(htm, value);
	while (htm->nbr_open_node > 0)
	{
		if ((ret = is_in_donut(object, htm->open_node->data, DONUT_SIZE_UP)) != outside &&
			is_in_donut(object, htm->open_node->data, DONUT_SIZE_DOWN) != full)
		{
			if (ret == full)
				nbr_pair = nbr_pair + ((t_trixel *)htm->open_node->data)->nbr_object;
			else if (((t_trixel *)htm->open_node->data)->child_trixel == NULL)
			{
				if (((t_trixel *)htm->open_node->data)->objects != NULL)
					nbr_pair += is_in_donut_2_point(((t_trixel *)htm->open_node->data)->objects[0].info->coord, object->info->coord);
			}
			else
				load_child_in_open_element(htm->open_node->data, htm);
		}
		value = pop_front_list_open_node(htm);
		if (value == NULL)
			return (-1);
		put_front_list_pool_node(htm, value);
	}
	FREE_NODE(to_free);
	return (nbr_pair);
}

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Running the tree and find the nbr of pair.
*\fun \b running_tree.
*\param object Element use for make pair.
*\param htm Representing the htm context.
*\return Nbr of pair found by correlation.
*/
long long running_tree(t_object *object, t_HTM *htm)
{
	uint8_t index;
	long long nbr_pair = 0;

	for (index = 0; index < NBR_FACE_OCTAHEDRON; ++index)
		nbr_pair += running_face_of_hexadron(object, &htm->octahedron[index], htm);
	return (nbr_pair);
}