#ifndef HTM_H_
# define HTM_H_

# define TRIXEL_ALIGN 32
# define NODE_ALIGN 32
# define HTM_ALIGN 32
# define NBR_VERTICES_OCTAHEDRON 6
# define NBR_FACE_OCTAHEDRON 8
# define NBR_CUTTING_FACE 4
# define DONUT_SIZE_UP 0.9
# define DONUT_SIZE_DOWN 0.8

enum VerticeOctahedron
{
	v0 = 0,
	v1,
	v2,
	v3,
	v4,
	v5
};

enum FaceOctahedron
{
	S0 = 0,
	S1,
	S2,
	S3,
	N0,
	N1,
	N2,
	N3
};

enum result_donut
{
	outside = 0,
	full,
	partial
};

# include <stdlib.h>
# include <stdint.h>
# include "object.h"
# include "portability.h"
# include "catalogue.h"
# include "math_tool.h"
# include "running_tree.h"

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Representing a trixel data.
*\struct t_trixel HTM.h
*/
struct BEGIN_ALIGN(TRIXEL_ALIGN) t_trixel
{
	double v0[NBR_COORD];
	double v1[NBR_COORD];
	double v2[NBR_COORD];
	struct t_trixel **child_trixel;
	struct t_object *objects;
	uint32_t nbr_object;
} END_ALIGN(TRIXEL_ALIGN);

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Representing the htm data.
*\struct t_HTM HTM.h
*/
struct BEGIN_ALIGN(HTM_ALIGN) t_HTM
{
	struct t_trixel octahedron[NBR_FACE_OCTAHEDRON];
	struct t_trixel *pool_trixels;

	long long nbr_pool_object;
	long long nbr_pool_object_use;
	
	struct t_object *open_object;
	long long nbr_open_object;
	
	struct t_object *close_object;
	long long nbr_close_object;
	
	struct t_node *open_node;
	uint32_t nbr_open_node;
	
	struct t_node *pool_node;
	uint32_t nbr_pool_node;
	
	uint8_t depth;
} END_ALIGN(HTM_ALIGN);

typedef struct t_trixel t_trixel;
typedef struct t_HTM t_HTM;

# define MALLOC_TRIXEL(x) (t_trixel *)_aligned_malloc(sizeof(t_trixel) * x, TRIXEL_ALIGN)
# define FREE_TRIXEL(addr) _aligned_free(addr)

# define MALLOC_HTM(x) (t_HTM *)_aligned_malloc(sizeof(t_HTM) * x, HTM_ALIGN)
# define FREE_HTM(addr) FREE_TRIXEL(addr)

# define MALLOC_NODE(x) (t_node *)_aligned_malloc(sizeof(t_node) * x, NODE_ALIGN)
# define FREE_NODE(addr) FREE_HTM(addr)

t_node *build_pool_node(t_HTM *htm);
uint8_t build_HTM(t_HTM *htm, t_catalogue *catalogue);
uint8_t build_octahedron(t_HTM *htm);
t_trixel *get_trixel_pool(t_HTM *htm);
uint8_t add_trixel_children(t_trixel *trixel, t_HTM *htm);
uint8_t is_in_triangle(t_object *object, t_trixel *trixel, t_HTM *htm);
uint8_t put_object_into_htm(t_HTM *htm);
uint8_t put_object_into_children(t_HTM *htm);
uint8_t put_object_into_octahedron(t_HTM *htm);
uint8_t put_object_into_trixel(t_object *object, t_trixel *dest_trixel, t_HTM *htm);
void set_surface_octahedron(t_trixel *trixel, double *v1, double *v2, double *v3);
void init_trixel_coord(t_trixel *trixel);
void set_sub_trixel(t_trixel *trixel, double *v0, double *v1, double *v2);
void decup_space(t_trixel **trixel, double *v0, double *v1, double *v2);
enum result_donut is_in_donut(t_object *object, t_trixel *trixel, double size_donuts);
long long running_tree(t_object *object, t_HTM *htm);
void free_htm(t_HTM *htm);

# include "put_back_list.h"
# include "pop_target_list.h"
# include "put_front_list.h"
# include "pop_front_list.h"
# include "build_octahedron.h"
# include "build_HTM.h"
# include "add_trixel_children.h"

#endif /*!HTM_H_*/