#ifndef __LIST__
#define __LIST__

#include <stdbool.h>

typedef struct s_list_node
{
	void*			data;
	struct s_list_node*	next;

} t_list_node;

typedef int (*compare)(void*, void*);
typedef void (*destroy)(void*);

typedef struct s_list
{
	int			size;
	struct s_list_node*	head;
	struct s_list_node*	tail;
	compare			compare;
	destroy			destroy;

} t_list;

t_list*		list_create(void);
void		list_init(t_list* list, int (*compare)(void*, void*), void (*destroy)(void*));
void		list_destroy(t_list** list);

void		list_insert_next(t_list* list, t_list_node* node, void* data);
void		list_remove_next(t_list* list, t_list_node* node, void** data);
bool		list_node_is_head(t_list const* list, t_list_node const* node);
bool		list_node_is_tail(t_list const* list, t_list_node const* node);
t_list_node*	list_head(t_list const* list);
t_list_node*	list_tail(t_list const* list);
unsigned int	list_size(t_list const* list);

void*		list_node_data(t_list_node const* node);
t_list_node*	list_node_next(t_list_node const* node);
void		list_foreach(t_list const* list, void(*action)(void*));
t_list*		list_merge(t_list* list1, t_list* list2);

#endif
