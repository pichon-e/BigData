#ifndef RUNNING_TREE_H_
# define RUNNING_TREE_H_

# include "portability.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Representing a data node use to support trixel to navigate in htm.
*\struct t_node running_tree.h
*/
struct BEGIN_ALIGN(NODE_ALIGN) t_node
{
	void *data;
	struct t_node *next;
	struct t_node *prev;
} END_ALIGN(NODE_ALIGN);

typedef struct t_node t_node;

#endif /*!RUNNING_TREE_H_*/