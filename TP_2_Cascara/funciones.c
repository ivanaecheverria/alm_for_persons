#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/** \brief Inicializa todos los estados de manera logica
 *
 * \param persona el array que se pasa como parametro
 * \param tam tamanio del array
 * \param valor el valor que tomaran los parametros inicializados
 * \return
 *
 */

 void inicializar (ePersona persona[], int tam, int valor)
 {
     int i;
     for(i=0;i<tam;i++)
     {
         persona[i].estado=valor;
     }
 }

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam el tamanio del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam tamanio del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if((lista[i].dni==dni)&&(lista[i].estado=1))
        {
            return i;
        }
    }
    return -1;

}
/** \brief Muestra los datos ingresados en el array de personas y los muestra de manera ordenada por el nombre
 *
 * \param lista[] ePersona el array de personas que se va a mostrar
 * \param tam int tamanio del array personas
 * \return void
 *
 */
void mostrarPersonas(ePersona lista[], int tam)
{
    ePersona listaAux;
    int i;
    int j;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
           if((lista[i].estado==1)&&(lista[j].estado==1))
                {
                    if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                    {
                        listaAux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=listaAux;

                    }
                }

        }
    }
    printf("************* PERSONAS INGRESADAS **************\n");

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            printf("Nombre: %s\n",lista[i].nombre);
            printf("Edad: %d\n",lista[i].edad);
            printf("D.N.I.: %ld\n\n",lista[i].dni);
            printf("__________________________________________\n");

        }

    }

}

/** \brief Se pide al usuario los datos de una persona para cargarlos al vector de persona
 *
 * \param lista[] ePersona array de personas en donde el usuario ingresa los datos
 * \param tam int tamanio del array de personas
 * \return void
 *
 */
void ingresarPersona(ePersona lista[], int tam)
{
    ePersona auxlista;
    int i;
    int flag=0;
    int hayLugar;
    hayLugar=obtenerEspacioLibre(lista,tam);
    int buscarDNI;

    for(i=0;i<1;i++)
    {
        if((hayLugar==-1)&&(flag==0))
        {

            printf("No Se pueden ingresar datos. Capacidad completa");
            system("pause");
        }
        else
        {
            printf("ALTA\n");
            fflush(stdin);
            printf("Ingrese nombre:\t\n");
            gets(auxlista.nombre);
            printf("Ingrese edad:\t\n");
            scanf("%d",&auxlista.edad);
            while((auxlista.edad<1)||(auxlista.edad>150))
                  {
                      printf("Edad inválida. Reingrese su edad:\n");
                        scanf("%d",&auxlista.edad);
                  }
            printf("Ingrese DNI:");
            fflush(stdin);
            scanf("%ld",&auxlista.dni);
            while((auxlista.dni<100000)||(auxlista.dni>99999999))
            {
                printf("DNI ingresado invalido. Intente nuevamente:\n");
                scanf("%ld",&auxlista.dni);
            }
            buscarDNI=buscarPorDni(lista,auxlista.dni,tam);

            if(buscarDNI!=-1)
                {
                    printf("Persona ya existe. Ingreso cancelado.\n");
                    system("pause");
                    break;

                }
                lista[hayLugar]=auxlista;
                lista[hayLugar].estado=1;

            }


        }
    }

/** \brief  Pide al usuario la variable DNI del array de personas y si coincide con una de las ingresadas anteriormente , da toda la estructura Persona de baja de manera logica
 *
 * \param lista[] ePersona array de personas a dar de baja
 * \param tam int tamanio del array de personas
 * \return void
 *
 */
void bajaPersonas(ePersona lista[],int tam)
{
    int i;
    int auxDNI;
    int buscarDNI;
    printf("Ingrese DNI de la persona a eliminar de la lista:\n");
    scanf("%d",&auxDNI);
    buscarDNI=buscarPorDni(lista,auxDNI,tam);

    for(i=0;i<tam;i++)
    {
        if(buscarDNI==-1)
        {
            printf("Persona no encontrada con DNI ingresado, intente nuevamente\n");
            system("pause");
            break;
        }
        else
        {
            lista[i].estado=0;
            printf("Persona dada de baja exitosamente");
            break;
        }
    }
}

/** \brief Muestra un grafico ordenado para representar estadisticamente el rango de edades del array personas ingresado
 *
 * \param lista[] ePersona array de personas a graficar
 * \param tam int tamanio del array
 * \return void
 *
 */
void imprimirGrafico(ePersona lista[], int tam)
{
    int i,menora19=0;
    int entre19y35=0;
    int mayorde35=0;
    int max=0;

        for(i=0;i<tam;i++)
            {
                if(lista[i].estado!=0)
                    {
                        if(lista[i].edad<19)
                            {
                                menora19++;
                            }
                        else
                            {
                            if((lista[i].edad>=19) && (lista[i].edad<35))
                            {
                                entre19y35++;
                            }
                                else
                                    {
                                        mayorde35++;
                                    }
                            }
                    }
            }
        if((menora19>=entre19y35) && (menora19>=mayorde35))
            {
                max=menora19;
            }
        else
            {
            if((entre19y35>=menora19)&&(entre19y35>=mayorde35))
            {
                max=entre19y35;
            }
            else
            {
                max=mayorde35;
            }
        }
    system("cls");
    for(i=max;i>0;i--)
    {
        if((i==menora19)&&(i==entre19y35)&&(i==mayorde35))
        {
            printf(" *     *     *\n");
            menora19--;
            entre19y35--;
            mayorde35--;
        }
        else
        {
            if((i==menora19)&&(i==mayorde35))
            {
                printf(" *           *\n");
                menora19--;
                mayorde35--;
            }
            if((i==entre19y35)&&(i==mayorde35))
            {
                printf("       *     *\n");
                entre19y35--;
                mayorde35--;
            }
            if((i==menora19)&&(i==entre19y35))
            {
                printf(" *      *     \n");
                menora19--;
                entre19y35--;
            }
            else
            {
                if(i==menora19)
                {
                    printf(" *           \n");
                    menora19--;
                }
                else
                {
                    if(i==entre19y35)
                    {
                        printf("       *     \n");
                        entre19y35--;
                    }
                    else
                    {
                        if(i==mayorde35)
                        {
                            printf("             *\n");
                            mayorde35--;
                        }
                    }
                }
            }
        }
    }
    printf("19<  19-35  >35\n");
    system("pause");
    fflush(stdin);
}
