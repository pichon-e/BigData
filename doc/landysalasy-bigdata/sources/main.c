#include <stdlib.h>
#include "log.h"
#include "catalogue.h"
#include "object.h"
#include "HTM.h"

static long long count_pair_by_point(t_HTM *htm)
{
	t_object *tmp = htm->close_object;
	long long nbr_pair = 0;

	while (tmp != NULL)
	{
		nbr_pair += running_tree(tmp, htm);
		tmp = tmp->next;
	}
	return (nbr_pair);
}

static t_catalogue *append_tow_catalogue(t_catalogue *catalogue, t_catalogue *NN, t_catalogue *NR)
{
	catalogue->data = NULL;
	catalogue->nbr_element = NN->nbr_element + NR->nbr_element;
	if (build_pool_object_by_append_catalogue(catalogue, NN, NR) == 0)
		return (NULL);
	return (catalogue);
}

static uint8_t generate_random_catalogue(t_catalogue *NN, long long *pair_rr, long long *pair_nr)
{
	BEGIN_ALIGN(CATALOGUE_ALIGN) t_catalogue END_ALIGN(CATALOGUE_ALIGN) NR;
	BEGIN_ALIGN(CATALOGUE_ALIGN) t_catalogue END_ALIGN(CATALOGUE_ALIGN) RR;
	BEGIN_ALIGN(HTM_ALIGN) t_HTM htmNR END_ALIGN(HTM_ALIGN);
	BEGIN_ALIGN(HTM_ALIGN) t_HTM htmRR END_ALIGN(HTM_ALIGN);

	uint8_t index = 0;
	while (index < 100.0)
	{
		srand(time(NULL));
		if (build_catalogue_by_random(NN->nbr_element, &RR) == 0)
			return (0);
		if ((build_pool_object(&RR)) == 0)
			return (0);
		build_HTM(&htmRR, &RR);
		while (put_object_into_htm(&htmRR) == 1);
		*pair_rr += count_pair_by_point(&htmRR);
		fprintf(stderr, "NR ->%d\n", *pair_rr);
		if ((append_tow_catalogue(&NR, NN, &RR)) == NULL)
			return (0);
		build_HTM(&htmNR, &NR);
		while (put_object_into_htm(&htmNR) == 1);
		*pair_nr += count_pair_by_point(&htmNR);
		fprintf(stderr, "NF ->%d\n", *pair_nr);
		free_htm(&htmRR);
		free_htm(&htmNR);
		free_catalogue(&NR);
		index = index + 1;
	}
	return (1);
}

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief The program start here
*/
int main(int argc, char **argv)
{
	BEGIN_ALIGN(CATALOGUE_ALIGN) t_catalogue END_ALIGN(CATALOGUE_ALIGN) NN;
	BEGIN_ALIGN(HTM_ALIGN) t_HTM htmNN END_ALIGN(HTM_ALIGN);
	long long pair_nn = 0;
	long long pair_rr = 0;
	long long pair_nr = 0;
	double result = 0.0;

	if (build_catalogue_by_file(PATH_DATA_FILE, &NN) == 0)
		return (0);
	if (build_pool_object(&NN) == 0)
		return (0);
	build_HTM(&htmNN, &NN);
	while (put_object_into_htm(&htmNN) == 1);
	pair_nn = count_pair_by_point(&htmNN);
	printf("->%d\n", pair_nn);
	if (generate_random_catalogue(&NN, &pair_rr, &pair_nr) == 0)
		return (0);
	pair_nr = pair_nr / 100;
	pair_rr = pair_rr / 100;
	result = (double)(pair_nn - (2 * pair_nr) + pair_rr) / (double)pair_rr;
	printf("result = %lf", result);
	free_htm(&htmNN);
	free_catalogue(&NN);
	return (0);
}