#ifdef HTM_H_

# define GEN_FUNC_PUTBACK_LIST(kind, type)						\
	void put_back_list_##kind##(t_HTM *htm, type *element)		\
	{															\
		type *tmp;												\
																\
		if (htm->##kind## == NULL)								\
		{														\
				htm->##kind## = element;						\
				htm->##kind##->next = NULL;						\
				htm->##kind##->prev = NULL;						\
		}														\
		else													\
		{														\
			tmp = htm->##kind##;								\
			while (tmp->next != NULL)							\
				tmp = tmp->next;								\
			element->next = NULL;								\
			element->prev = tmp;								\
			tmp->next = element;								\
		}														\
		htm->nbr_##kind## += 1;									\
	}															\

# define GEN_PROTO_PUTBACK_LIST(kind, type)						\
	void put_back_list_##kind##(t_HTM *htm, type *element);		\

GEN_PROTO_PUTBACK_LIST(open_node, t_node);

#endif /*!HTM_H_*/