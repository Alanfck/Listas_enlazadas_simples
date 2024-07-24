/*plista_simple.c* todas funciones*/ //García Núñez Rodrigo y Alan Yair Cortes Lopez
/*Librerias*/
#include "FuncionesP2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funciones y/o procedimientos*/

Alumno *crear_Alumno(int ID, char NAME[30], int EDAD, char lic[50], char div[30])  //en esta funcion se llena la estructura que contiene los datos del alumno
{
    Alumno *aux = (Alumno *)malloc(sizeof(Alumno));
    aux->Matricula = ID;
    strcpy(aux->name, NAME);
    aux->edad = EDAD;
    strcpy(aux->licenciatura, lic);
    strcpy(aux->divisionAC, div);
    return (aux);   //retorna un apuntador de tipo Alumno
}

Nodo *crear_Nodo(Alumno *alumno)       // se crea el nodo que contendrá la estructura Alumno
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));  // crea un auxiliar de tipo nodo con memoria dinamica
    aux->datos = alumno;     // el apuntador datos apunta a donde apunta el apuntador alumno
    aux->sig = NULL;      // hacemos que el apuntador sig apunte a NULL
    return (aux);
}

ListaS *crear_ListaS()
{
    ListaS *aux = (ListaS *)malloc(sizeof(ListaS)); //reserva memoria de forma dinamica para una lista
    aux->cabeza = NULL;
    return (aux);   //regresa un apuntador de tipo null
}

int isEmpty(ListaS lista)
{
    if (lista.cabeza == NULL)
    {
        //printf("\n Lista Vacia funcion isEmpty\n");  si la cabeza apunta a null, entonces significa que la lista está vacía
        return (1);
    }
    else
    {
        //printf("\n La Lista No Esta Vacia funcion isEmpty \n"); si no, entonces quiere decir que no está vacía
        return (0);
    }
}

void insertar_cabeza(ListaS *lista, Nodo *aux) 
{
    if (isEmpty(*lista) == 1)  //si está vacía, entonces el apuntador cabeza, apunta a aux. sig seguiría apuntando a NULL
    {
        lista->cabeza = aux;
    }
    else
    {
        aux->sig = lista->cabeza;  // sig apunta al nodo al que apunta la cabeza
        lista->cabeza = aux;  // el apuntador cabeza, ahora apunta a aux
    }
}

void insertar_cola(ListaS *lista, Nodo *aux)
{
    Nodo *cola;
    cola = lista->cabeza;       // cola apunta a cabeza
    if (isEmpty(*lista) == 1)    //si la lista está vacía, entonces se inserta el nodo en la cabeza 
    {
        insertar_cabeza(lista, aux);
    }
    else
    {
        while (cola->sig != NULL)
        {
            cola = cola->sig;     //el ciclo recorre todos los nodos hasta que que sig sea NULL
        }
        cola->sig = aux; //sig ahora apunta a aux
        cola = aux;     //cola ahora apunta  aux
    }
}

void insertar_enmedio(ListaS *lista, Nodo *anterior, Nodo *elemento)
{
    if (isEmpty(*lista) == 1)    
    {
        lista->cabeza = elemento;
    }
    else
    {
        elemento->sig = anterior->sig;
        anterior->sig = elemento;
    }
}

Nodo *quitar_cabeza(ListaS *lista)
{
    Nodo *aux = NULL;
    Nodo *aux1;
    if (!isEmpty(*lista))
    {
        aux = lista->cabeza;
        lista->cabeza = lista->cabeza->sig;
        aux1 = aux;
        //free(aux);
    }
    else
    {
        //printf("\n La lista esta vacia  estoy dentro del procedimiento quitar cabeza  \n");
    }
    return (aux1);
}

void quitar_cola(ListaS *lista)
{
    Nodo *cola;
    Nodo *anterior;
    if (isEmpty(*lista) == 1)
    {
        //printf("\n La pila esta vacia estoy dentro del procedimiento quitar cola \n");
    }
    else
    {
        if (lista->cabeza->sig == NULL)
        {
            lista->cabeza = NULL;
            //printf("\n  Memoria liberada estoy dentro del procedimiento quitar cola\n");
        }
        else
        {
            cola = lista->cabeza;
            while (cola->sig != NULL)
            {
                anterior = cola;
                cola = cola->sig;
            }
            anterior->sig = NULL;
            free(cola);
            //cola=NULL;
        }
    }
}

void quitar_enmedio(ListaS *lista, Nodo *elemento)
{
    Nodo *anterior;
    Nodo *borrar;
    if (isEmpty(*lista) == 1)
    {
        //printf("\n La pila esta vacia estoy dentro del procedimiento quitar enmedio \n");
    }
    else
    {
        borrar = buscaElemento(lista, elemento); //pendiente
        if (lista->cabeza == borrar)
        {
            printf("holi");
            quitar_cabeza(lista);
        }
        else
        {
            anterior = lista->cabeza;
            while (anterior->sig != borrar)
            {
                anterior = anterior->sig;
            }
            anterior->sig = borrar->sig;
            free(borrar);
            //printf("\nid=%d",anterior->datos->id);
        }
    }
}

Nodo *quitar_enmedio1(ListaS *lista, int ent)
{
    Nodo *anterior;
    Nodo *borrar;
    Nodo *aux;
    if (isEmpty(*lista) == 1)
    {
        //printf("\n La pila esta vacia estoy dentro del procedimiento quitar enmedio \n");
    }
    else
    {
        borrar = buscaElemento1(lista, ent); //pendiente
        if (lista->cabeza == borrar)
        {
            aux = quitar_cabeza(lista);
        }
        else
        {
            anterior = lista->cabeza;
            while (anterior->sig != borrar)
            {
                anterior = anterior->sig;
            }
            anterior->sig = borrar->sig;
            aux = borrar;
            //free(borrar);
            //printf("\nid=%d",anterior->datos->id);
        }
    }
    return (aux);
}

Nodo *buscaElemento(ListaS *lista, Nodo *elemento)
{
    Nodo *aux = lista->cabeza;
    Alumno *alu;
    if (!isEmpty(*lista))
    {
        //while(aux->datos->id != ID)
        while (aux->datos->Matricula != elemento->datos->Matricula)
        {
            if (aux->sig != NULL)
            {
                aux = aux->sig;
            }
            else
            {
                printf("\nEl elemento con ID = %d no se encuentra en la lista\n", elemento->datos->Matricula);
                //printf("\nEl elemento con ID = %d no se encuentra en la lista\n",ID);

                aux = NULL;
                return (aux);
                break;
            }
        }
        //if(aux->datos->id == ID)
        if (aux->datos->Matricula == elemento->datos->Matricula)
        {
            printf("\nEl elemento con ID = %d si esta en la lista\n", elemento->datos->Matricula);
            //printf("\nEl elemento con ID = %d si esta en la lista\n",ID);
            return (aux);
        }
    }
    else
    {
        printf("\n EL ELEMENTO NO SE ENCUENTRA LA LISTA NO TIENE NADA \n");
        return (NULL);
    }
}

Nodo *buscaElemento1(ListaS *lista, int ent)
{
    Nodo *aux = lista->cabeza;
    Alumno *alu;
    if (!isEmpty(*lista))
    {
        //while(aux->datos->id != ID)
        while (aux->datos->Matricula != ent)
        {
            if (aux->sig != NULL)
            {
                aux = aux->sig;
            }
            else
            {
                printf("\n El Alumno con matricula = %d no se encuentra en la lista", ent);
                aux = NULL;
                return (aux);
                //break;
            }
        }
        //if(aux->datos->id == ID)
        if (aux->datos->Matricula == ent)
        {
            printf("\n El Alumno con matricula = %d si esta en la lista", ent);
            return (aux);
        }
    }
    else
    {
        printf("\n  LA LISTA NO TIENE NADA");
        return (NULL);
    }
}

void vaciarLista(ListaS *lista)
{
    Nodo *aux = lista->cabeza;
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)
        {
            aux = aux->sig;
            quitar_cabeza(lista);
        }
    }
    else
    {
        printf("\n LISTA SIN NADA PROCEDIMIENTO VACIAR LISTA \n");
    }
    free(aux);
}

void printLista(ListaS *lista)
{
    Nodo *aux = lista->cabeza;
    Alumno *alu;
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)
        {
            alu = aux->datos;
            printf("\n Matricula es: %d", alu->Matricula);
            printf("\n Nombre es: %s", alu->name);
            printf("\n Edad es: %d ", alu->edad);
            printf("\n Licenciatura: %s", alu->licenciatura);
            printf("\n Division academica: %s\n", alu->divisionAC);
            aux = aux->sig;
        }
    }
    else
    {
        printf("\n LISTA SIN NADA \n");
    }
}


// Esta funció  recibe 3 apuntadores de tipo nodo y 2 de tipo ListaS
// El nodo aux apunta al nodo que se quita de la lista principal, de modo que aux1 sirve para mandar la referencia del nodo a buscar y eliminar de la lista
// alu23 apunta al nodo creado con los datos recuperados por aux del nodo eliminado de la lista principal
// L23 es un apuntador de la lista de alumnos menores de 23 de modo que al insertar cabeza, este indica en qué lista insertar el nodo
void depurar_23(Nodo *aux, Nodo *aux1, Nodo *alu23, ListaS *L23, ListaS *p) 
{
    aux = quitar_enmedio1(p, aux1->datos->Matricula);
    alu23 = crear_Nodo(crear_Alumno(aux->datos->Matricula, aux->datos->name, aux->datos->edad, aux->datos->licenciatura, aux->datos->divisionAC));
    insertar_cabeza(L23, alu23);
}

