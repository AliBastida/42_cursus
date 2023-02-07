#include "listas.h"

t_list  *ft_new_node()
{
    t_list  *nodo;

    nodo = malloc(sizeof(t_list));
    nodo->next = NULL;

    return (nodo);
}




int main()
{

    /* ESTRUCTUCTURAS */
    /* SIN MALLOC */
    // struct s_master estructura1;
    // t_master        estructura2;

    // estructura1.numero = 2;
    // estructura2.numero = 4;

    // printf("N1 == (%i)\n", estructura1.numero);
    // printf("N2 == (%i)\n", estructura2.numero);


    // /* MALLOC */

    // struct s_master *estructura3;
    // t_master        *estructura4;

    // estructura3 = malloc(sizeof(struct s_master));
    // estructura4 = malloc(sizeof(t_master));

    // estructura3->numero = 8;
    // estructura4->numero = 9;

    // printf("N3 == (%i)\n", estructura3->numero);
    // printf("N4 == (%i)\n", estructura4->numero);

    /* LISTAS */

    t_list  *nodo1;
    t_list  *nodo2;
    t_list  *nodo3;


    printf("DIR == (%p)\n", nodo1);

    nodo1 = ft_new_node();
    nodo2 = ft_new_node();
    nodo3 = ft_new_node();

    printf("DIR == (%p)\n", nodo1);

    nodo1->next = nodo2;
    nodo2->next = nodo3;

    nodo1->numero = 1;
    nodo2->numero = 2;
    nodo3->numero = 3;


    t_list *aux;
    aux = nodo1;

    while(aux)
    {
        printf("NUMERO == (%i)\n", aux->numero);
        aux = aux->next;
    }






    return (0);
}