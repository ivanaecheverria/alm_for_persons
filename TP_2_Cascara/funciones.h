#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}ePersona;

void inicializar(ePersona[],int,int);
int obtenerEspacioLibre(ePersona[],int);
int buscarPorDni(ePersona[],int,int);
void mostrarPersonas(ePersona[], int);
void bajaPersonas(ePersona[],int);
void ingresarPersona(ePersona [], int);
void imprimirGrafico(ePersona [], int);
#endif // FUNCIONES_H_INCLUDED
