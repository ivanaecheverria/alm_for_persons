#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"
#define CANT 20
int main()
{
    char seguir='s';
    int opcion=0;
    ePersona persona[CANT];
    inicializar(persona,CANT,0);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                ingresarPersona(persona,CANT);
                system("cls");
                break;
            case 2:
                system("cls");
                bajaPersonas(persona,CANT);
                system("cls");
                break;
            case 3:
                system("cls");
                mostrarPersonas(persona,CANT);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                imprimirGrafico(persona,CANT);
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
