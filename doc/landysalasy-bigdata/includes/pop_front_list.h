#ifdef HTM_H_

# define GEN_FUNC_POPFRONT_LIST(kind, type)			\
	type *pop_front_list_##kind##(t_HTM *htm)		\
	{												\
		type *ret = htm->##kind##;					\
		if (htm->##kind## != NULL)					\
		{											\
			htm->##kind## = htm->##kind##->next;	\
			if (htm->##kind## != NULL)				\
				htm->##kind##->prev = NULL;			\
		}											\
		if (ret != NULL)							\
		{											\
			ret->next = NULL;						\
			ret->prev = NULL;						\
			ret->data = NULL;						\
		}											\
		htm->nbr_##kind## -= 1;						\
		return (ret);								\
	}												\

# define GEN_PROTO_POPFRONT_LIST(kind, type)		\
	type *pop_front_list_##kind##(t_HTM *htm);		\

GEN_PROTO_POPFRONT_LIST(pool_node, t_node);
GEN_PROTO_POPFRONT_LIST(open_node, t_node);

#endif /*!HTM_H_*/