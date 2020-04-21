#ifndef NODE_H
#define NODE_H

typedef int DATA;
typedef struct _node node;
struct _node
{
    DATA data;
    node *next;
};
node *create_node(DATA);
void delete_node(node *n);



#endif