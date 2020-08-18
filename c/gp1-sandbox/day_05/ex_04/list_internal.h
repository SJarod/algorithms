#ifndef __LIST_INTERNAL__
#define __LIST_INTERNAL__

typedef struct s_list_node t_list_node;

typedef int (*compare)(void*, void*);
typedef void (*destroy)(void*);

typedef struct s_list t_list;

#endif
