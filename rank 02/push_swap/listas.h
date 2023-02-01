#include <stdio.h>
#include <stdlib.h> 

typedef struct s_master
{
    int numero;
}   t_master;



typedef struct s_list
{
    int             numero;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;