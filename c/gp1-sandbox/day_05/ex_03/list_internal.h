#ifndef __LIST_INTERNAL__
#define __LIST_INTERNAL__

typedef struct s_list_node t_list_node;

typedef int (*compare)(void*, void*);
typedef void (*destroy)(void*);

typedef struct s_list t_list;

//add one t_list_node sized element to the list: list (which list), node (which node)
void add_element(t_list* list);

#endif
