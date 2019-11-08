#ifndef FT_MALLOC
# define FT_MALLOC
# include <sys/mman.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/resource.h>
# define TINY 32
# define SMALL 128
# define LARGE 1024

void    free(void *ptr);
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
void    show_alloc_mem();
#endif