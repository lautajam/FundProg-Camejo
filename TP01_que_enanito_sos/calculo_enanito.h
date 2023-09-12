#ifndef CALCULO_ENANITO_H
#define CALCULO_ENANITO_H

/*
Pre:  Se recibe una referencia a una variable de tipo char que va a contener la inicial del enanito.
Post: Se calculará la inicial del enanito en base al puntaje obtenido. 
      Se modificará el valor de la variable inicial_enanito por referencia.
        G: Gruñón
        D: Dormilón
        S: Sabio
        F: Feliz
*/
void calcular_enanito(char* inicial_enanito);

#endif /* CALCULO_ENANITO_H */