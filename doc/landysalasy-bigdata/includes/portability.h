#ifndef PORTABILITY_H_
# define PORTABILITY_H_

# ifdef WIN32
#  define INLINE __inline
#  define BEGIN_ALIGN(x) __declspec(align(x))
#  define END_ALIGN(x)
# else
#  define INLINE inline
#  define BEGIN_ALIGN(x)
#  define END_ALIGN(x) __attribute__((aligned(x)))
# endif

#endif /*!PROTABILITY*/