#include <stdlib.h>
#include "list.h"
list *create_list()
{
    list *t;
    t=(list*)malloc(sizeof(list));
    t->head=NULL;
    t->cont=0;
    return t;
}
void delete_list(list *l)
{

   if(!is_empty(l))
    {
        empty(l);
        free(l);
        l=NULL;
    }
}
//Funciones para agregar a la lista
bool add_init(list *l, DATA data)
{
    if(l==NULL)return false;

    if(is_empty(l))
    {
        l->head=create_node(data);
        l->cont=1;
        return true;
    }
    node *nuevo=create_node(data);
    nuevo->next=l->head;        l->head=nuevo;
    l->cont++;
    return true;
    
}
bool add_end(list *l, DATA data)
{
    if(l==NULL)return false;
    if(is_empty(l))
    {
        l->head=create_node(data);
        l->cont=1;
        return true;
    }
    
    node *nuevo=create_node(data);
    node *fin=ultimo(l);
    fin->next=nuevo;
    l->cont++;
    return true;
}
bool add(list *l, DATA data, int pos)
{
    if(l==NULL) return false;
    if(pos==0  || is_empty(l))
    {
        add_init(l, data);
    }else
    { 
        if(pos==l->cont)
        {
            return add_end(l, data);
        }
        else
        {
            if(pos>0 && pos<l->cont)
            {
                node *act=actual(l, pos);
                node *ant=actual(l, pos);
                node *nuevo=create_node(data);
                ant->next=nuevo;
                nuevo->next=act;
                l->cont++;
                return true;
            }
            else
            {
                return false;
            }
            
        }
        
    }
    
}
//Funcion para eliminar un dato
bool remove_data(list *l, DATA data)
{
    if(l==NULL) return false;
    node *t=l->head;
    node *ant, *act;
    int i=0;
    while (t!=NULL)
    {
        if(t->data==data)
        {
            break;
        }
        t=t->next;i++;
    }
    ant=actual(l, i-1);
    act=actual(l, i);
    ant->next=act->next;
    act->next=NULL;
    delete_node(act);
    l->cont--;
    return true;
    
}
//Funciones para eliminar por posicion
DATA delete_init(list *l)
{
    if(l==NULL)return -1;
    if(!is_empty(l))
    {
        node *t=l->head;
        int d=t->data;
        l->head=l->head->next;
        t->next=NULL;
        delete_node(t);
        l->cont--;
        return d;
    }
    return -1;
}
DATA delete_end(list *l){
    if(l==NULL)return -1;
    if(!is_empty(l))
    {
        node *ult=ultimo(l);
        node *t=penultimo(l);
        int d=ult->data;
        t->next=NULL;
        delete_node(ult);
        l->cont--;
        return d;
    }
    return -1;
}
DATA delete_data(list *l, int pos)
{
    int d;
    if(l==NULL)return -1;
    if(pos==0)
    {
        return delete_init(l);
    }
    else
    {
        if (pos==l->cont-1)
        {
            return delete_end(l);
        }
        else
        {
            if (pos>0 && pos<l->cont-2)
            {
                node *ult=actual(l, pos);
                node *ant=actual(l, pos-1);
                ant->next=ult->next;
                ult->next=NULL;
                delete_node(ult);
                l->cont--;
                return d;
            }else
            {
                return-1;
            }
            
            
        }
        
        
    }
    
}
//Funciones para buscar
int search_data(list *l, DATA data)
{
    int pos;
    node *t;
    for(pos=0, t =l->head; data != t->data && t->next!=NULL; pos++,t=t->next);
    if(pos >=l->cont) return -1;
    return pos;
}
DATA search_pos(list *l, int pos)
{
    node *t, *t1, *t2;
    int i;
    for(i=1, t=l->head; i<=pos;i++, t=t->next);
    if(t!=NULL)return t->data;
    return -1;
}
node *search_node(list *l, DATA data)
{
    
}

//ultimo y pen
node *ultimo(list *l)
{
    node *t=l->head;
    while (t->next!=NULL)
    {
        t=t->next;

    }
    return t;
    
}
node *penultimo(list *l)
{
    node *t=l->head;
    while (t->next->next!=NULL)
    {
        t=t->next;
    }
    return t;
    
}
node *anterior(list *l, int pos)
{
    node *t=l->head;
    int i=0;
    while (t->next!=NULL && i<pos-1)
    {
        t=t->next;
    }
    return t;
}
node *actual(list *l, int pos)
{
    node *t=l->head;
    int i=0;
    while (t->next!=NULL && i<pos)
    {
        t=t->next;
    }
    return t;
    
}

//funcion para impriir
void print_list(list *l)
{
    node *t=l->head;
    while (t!=NULL)
    {
        printf("Dato: %i\n", t->data);
        t=t->next;
    }

    

}

bool is_empty(list *l)
{
    if(l->head==NULL)return true;
    return false;
}
void empty(list *l)
{
    node *t=ultimo(l);
    node *ant;
    while (t!=NULL)
    {
        ant=penultimo(l);
        delete_node(t);
        ant->next=NULL;
        t=ultimo(l);
    }
    
}