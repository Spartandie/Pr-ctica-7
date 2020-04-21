#ifndef CLIST_H
#define CLIST_H

#include "node.h"
#include <stdbool.h>

typedef struct _clist clist;
struct _clist
{
    node *head;
    int cont;
};

clist *create_list();
void delete_list(clist *l);
//Funciones para agregar a la lista
bool add_init(clist *l, DATA data);
bool add_end(clist *l, DATA data);
bool add(clist *l, DATA data, int pos);

//Funcion para eliminar un dato
bool remove_data(clist *l, DATA data);
//Funciones para eliminar por posicion
DATA delete_init(clist *l);
DATA delete_end(clist *l);
DATA delete_data(clist *l, int pos);
//Funciones para buscar
int search_data(clist *, DATA data);
DATA search_pos(clist *l, int pos);
node *search_node(clist *l, DATA data);

//ultimo y pen
node *ultimo(clist *l);
node *penultimo(clist *l);
node *anterior(clist *l, int pos);
node *actual(clist *l, int pos);

//funcion para impriir
void print_list(clist *l);

bool is_empty(clist *l);
void empty(clist *l);
#endif