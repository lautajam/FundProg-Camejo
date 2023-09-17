
#ifndef FERIA_H
#define FERIA_H

/*
    Pre: Recibe el array con los talles de las prendas y el tope (cuantas prendas hay)
    Post: Imprime el talle de la prenda n
*/
void mostrar_talle_prendas(char[], int*);

/*
    Pre: Recibe el array con los talles de las prendas y el tope (cuantas prendas hay)
    Post: Imprime por pantalla la cantidad de prendas de cada talle que hay
*/
void contar_talles(char[], int*);

/*
    Pre: Recibe el array con los talles de las prendas, el tope (cuantas prendas hay) y el talle que hay que agregar
    Post: Agrega en la primer posicion vacia el talle de prenda a agregar
*/
void agregar_remera(char[], int*, char);

#endif /* FERIA_H */