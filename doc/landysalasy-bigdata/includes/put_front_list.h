#ifdef HTM_H_

# define GEN_FUNC_PUTFRONT_LIST(kind, type)						\
	void put_front_list_##kind##(t_HTM *htm, type *element)		\
	{															\
		if (htm->##kind## == NULL)								\
		{														\
			htm->nbr_##kind## += 1;								\
			htm->##kind## = element;							\
		}														\
		else													\
		{														\
			htm->nbr_##kind## += 1;								\
			type *old_root = htm->##kind##;						\
			htm->##kind## = element;							\
			htm->##kind##->next = old_root;						\
			htm->##kind##->next->prev = htm->##kind##;			\
		}														\
	}															\

# define GEN_PROTO_PUTFRONT_LIST(kind, type)					\
	void put_front_list_##kind##(t_HTM *htm, type *element);	\

GEN_PROTO_PUTFRONT_LIST(close_object, t_object);
GEN_PROTO_PUTFRONT_LIST(open_object, t_object);
GEN_PROTO_PUTFRONT_LIST(pool_node, t_node);

#endif /*!HTM_H_*/