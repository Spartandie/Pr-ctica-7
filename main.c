#include<stdio.h>
#include<stdlib.h>
#include "clist.h"

int main()
{
    clist *l;
    l=create_list();
    add_init(l, 3);
    delete_list(l);
    return 0;
}