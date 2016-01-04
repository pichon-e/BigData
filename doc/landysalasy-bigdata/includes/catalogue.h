#ifndef CATALOGUE_H_
# define CATALOGUE_H_

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <time.h>
# include "log.h"
# include "object.h"
# include "portability.h"

# define CATALOGUE_ALIGN 32
# define SIZE_BUFFER 500
# define SEPARATOR " \n,\t"
# define NBR_DATA_RANDOM 10000000
# define PATH_DATA_FILE "../data.txt"
# define INVALID_DATA -1

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Representing a data catalogue.
*\struct t_catalogue catalogue.h
*/
struct BEGIN_ALIGN(CATALOGUE_ALIGN) t_catalogue
{
	t_object *pool_object;
	t_object_info *data;
	long long nbr_element;
} END_ALIGN(CATALOGUE_ALIGN);

typedef struct t_catalogue t_catalogue;

# define MALLOC_CATALOGUE(x) (t_catalogue *)_aligned_malloc(sizeof(t_catalogue) * x, CATALOGUE_ALIGN);
# define FREE_CATALOGUE(addr) _aligned_free(addr)

uint8_t load_data(char const *file_name, void (*handler)(char *, void *), void *data);
void landySalazyEstimator_valid_data(char *expression, void *data);
void landySalazyEstimator_get_data(char *expression, void *data);
uint8_t build_catalogue_by_file(char const *file_name, t_catalogue *catalogue);
void free_catalogue(t_catalogue *catalogue);
uint8_t build_pool_object(t_catalogue *catalogue);
uint8_t build_catalogue_by_random(long long nbr_element, t_catalogue *catalogue);
uint8_t build_pool_object_by_append_catalogue(t_catalogue *catalogue, t_catalogue *NN, t_catalogue *NR);

#endif /*!CATALOGUE_H_*/