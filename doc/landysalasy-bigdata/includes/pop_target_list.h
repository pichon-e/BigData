#ifdef HTM_H_

# define GEN_FUNC_POPTARGET_LIST(kind, type)					\
	void pop_target_list_##kind##(t_HTM *htm, type *element)	\
	{															\
		t_object *after = element->next;						\
		t_object *before = element->prev;						\
																\
		htm->nbr_##kind## -= 1;									\
		if (element == htm->##kind##)							\
		{														\
			htm->##kind## = element->next;						\
		}														\
		else													\
		{														\
			if (before != NULL)									\
				before->next = after;							\
			if (after != NULL)									\
				after->prev = before;							\
		}														\
		element->next = NULL;									\
		element->prev = NULL;									\
	}															\

# define GEN_PROTO_POPTARGET_LIST(kind, type)					\
	void pop_target_list_##kind##(t_HTM *htm, type *element);	\

GEN_PROTO_POPTARGET_LIST(close_object, t_object);
GEN_PROTO_POPTARGET_LIST(open_object, t_object);

#endif /*HTM_H_*/