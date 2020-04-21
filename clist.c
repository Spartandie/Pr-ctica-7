#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
clist *create_list()
{
    clist *t;
    t=(clist*)malloc(sizeof(clist));
    t->head=NULL;
    t->cont=0;
    return t;
}
void delete_list(clist *l)
{
    if(!is_empty(l))
    {
        empty(l);
        free(l);
        l=NULL;
    }
    
}
//Funciones para agregar a la lista
bool add_init(clist *l, DATA data)
{
    if(l==NULL)return false;

    if(is_empty(l))
    {
        l->head=create_node(data);
        l->head->next=l->head;
        l->cont=1;
        return true;
    }
    node *nuevo=create_node(data);
    nuevo->next=l->head;        
    l->head=nuevo;
    node *ult=ultimo(l);
    ult->next=l->head;
    l->cont++;
    return true;
    
}
bool add_end(clist *l, DATA data)
{
    if(l==NULL)return false;
    if(is_empty(l))
    {
        l->head=create_node(data);
        l->head->next=l->head;
        l->cont=1;
        return true;
    }
    
    node *nuevo=create_node(data);
    node *fin=ultimo(l);
    fin->next=nuevo;
    nuevo->next=l->head;
    l->cont++;
    return true;
}
bool add(clist *l, DATA data, int pos)
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
bool remove_data(clist *l, DATA data)
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
    if(act==l->head)
    {
        delete_init(l);
        return true;
    }else
    {
        if(act==ultimo(l))
        {
            delete_end(l);
            return true;
        }
    }
    
    ant->next=act->next;
    act->next=NULL;
    delete_node(act);
    l->cont--;
    return true;
    
}
//Funciones para eliminar por posicion
DATA delete_init(clist *l)
{
    if(l==NULL)return -1;
    if(!is_empty(l))
    {
        node *t=l->head;
        int d=t->data;
        l->head=l->head->next;
        node *ult=ultimo(l);
        ult->next=l->head;
        t->next=NULL;
        delete_node(t);
        l->cont--;
        return d;
    }
    return -1;
}
DATA delete_end(clist *l){
    if(l==NULL)return -1;
    if(!is_empty(l))
    {
        node *ult=ultimo(l);
        node *t=penultimo(l);
        int d=ult->data;
        t->next=l->head;
        delete_node(ult);
        l->cont--;
        return d;
    }
    return -1;
}
DATA delete_data(clist *l, int pos)
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
int search_data(clist *l, DATA data)
{
    int pos;
    node *t;
    for(pos=0, t =l->head; data != t->data && t->next!=l->head; pos++,t=t->next);
    if(pos >=l->cont) return -1;
    return pos;
}
DATA search_pos(clist *l, int pos)
{
    node *t, *t1, *t2;
    int i;
    for(i=1, t=l->head; i<=pos;i++, t=t->next);
    if(t!=NULL)return t->data;
    return -1;
}
node *search_node(clist *l, DATA data)
{
    
}

//ultimo y pen
node *ultimo(clist *l)
{
    node *t=l->head;
    while (t->next!=l->head)
    {
        t=t->next;

    }
    return t;
    
}
node *penultimo(clist *l)
{
    node *t=l->head;
    while (t->next->next!=l->head)
    {
        t=t->next;
    }
    return t;
    
}
node *anterior(clist *l, int pos)
{
    node *t=l->head;
    int i=0;
    while (t->next!=l->head && i<pos-1)
    {
        t=t->next;
    }
    return t;
}
node *actual(clist *l, int pos)
{
    node *t=l->head;
    int i=0;
    while (t->next!=l->head && i<pos)
    {
        t=t->next;
    }
    return t;
    
}

//funcion para impriir
void print_list(clist *l)
{
    node *t=l->head;
    while (t->next!=l->head)
    {
        printf("Dato: %i\n", t->data);
        t=t->next;
    }

    

}

bool is_empty(clist *l)
{
    if(l->head==NULL)return true;
    return false;
}
void empty(clist *l)
{
    node *t=ultimo(l);
    node *ant;
    while (t!=NULL)
    {
        delete_node(t);
        ant=penultimo(l);
        ant->next=NULL;
        t=ultimo(l);
    }
    delete_node(l->head);
    l->cont=0;
}
