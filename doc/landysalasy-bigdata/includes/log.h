#ifndef LOG_H_
# define LOG_H_

# include <stdio.h>
# include "portability.h"

INLINE void log_info(char const *msg, void *data)
{
#  ifdef INFO
	if (data != NULL)
		fprintf(stderr, msg, data);
	else
		fprintf(stderr, msg);
#  endif /*!INFO*/
}

INLINE void log_debug(char const *msg, void *data)
{
#  ifdef DEBUG
	if (data != NULL)
		fprintf(stdout, msg, data);
	else
		fprintf(stderr, msg);
#  endif /*DEBUG*/
}

INLINE void log_warning(char const *msg, void *data)
{
#  ifdef WARNING
	if (data != NULL)
		fprintf(stderr, msg, data);
	else
		fprintf(stderr, msg);
#  endif /*!WARNING*/
}

INLINE void log_error(char const *msg, void *data)
{
#  ifdef ERROR
	if (data != NULL)
		fprintf(stderr, msg, data);
	else
		fprintf(stderr, msg);
#  endif /*!ERROR*/
}



#endif /*!LOG_H_*/