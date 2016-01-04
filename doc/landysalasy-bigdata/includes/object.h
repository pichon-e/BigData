#ifndef OBJECT_H_
# define OBJECT_H_

# include <stdint.h>
# include <xmmintrin.h>
# include "portability.h"

# define OBJECT_ALIGN 32
# define OBJECT_INFO_ALIGN 32

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Representing the object info data.
*\struct t_object_info object.h
*/
struct BEGIN_ALIGN(OBJECT_INFO_ALIGN) t_object_info
{
	long long id;
	double coord[3];
} END_ALIGN(OBJECT_INFO_ALIGN);

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Representing the object data.
*\struct t_object object.h
*/
struct BEGIN_ALIGN(OBJECT_ALIGN) t_object
{
	struct t_object *next;
	struct t_object *prev;
	void *trixel;
	struct t_object_info *info;
} END_ALIGN(OBJECT_ALIGN);

typedef struct t_object_info t_object_info;
typedef struct t_object t_object;

# define GET_INDEX_INFO(start, offset) (((size_t)offset - (size_t)start) / sizeof(t_object))
# define MALLOC_OBJECT(x) (t_object *)_aligned_malloc(sizeof(t_object) * x, OBJECT_ALIGN)
# define MALLOC_OBJECT_INFO(x) (t_object_info *)_aligned_malloc(sizeof(t_object_info) * x, OBJECT_INFO_ALIGN)
# define FREE_OBJECT(addr) _aligned_free(addr)
# define FREE_OBJECT_INFO(addr) FREE_OBJECT(addr)

#endif /*!OBJECT_H_*/