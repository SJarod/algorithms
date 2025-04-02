#ifndef __LIST__
#define __LIST__

typedef struct s_list_node
{
	void*			data;
	struct	s_list_node*	next;

} t_list_node;

typedef int (*compare)(void*, void*);
typedef void (*destroy)(void*);

typedef struct s_list
{
	int			size;
	struct	s_list_node*	head;
	struct	s_list_node*	tail;
	compare			compare;
	destroy			destroy;

} t_list;

t_list* list_create(void);
void list_init(t_list* list, int (*compare)(void*, void*), void (*destroy)(void*));
void list_destroy(t_list** list);

#endif
