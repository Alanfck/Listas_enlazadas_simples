/*Main de la prcatica 2 */ //García Núñez Rodrigo y Alan Yair Cortes Lopez
  
#include "FuncionesP2.h"            //Este programa hace una lista principal de alumnos, capáz de agregar y eliminar nodos.
#include <stdio.h>                  // A partir de esta lista principal, se crea un txt alumnos que contiene los datos de cada cada Alumno
#include <stdlib.h>                 // 
#include <string.h>

int main()
{

    int option;
    int opt, indi, cont = 0, contm = 0;
    int id;
    char Name[30];
    int Edad;
    char Licenciatura[50];
    char DivisionAC[30];
    ListaS *p;
    ListaS *L23;
    Nodo *alup;
    Nodo *aux;
    //Nodo *aux1;
    p = crear_ListaS();
    L23 = crear_ListaS();
    alup = crear_Nodo(crear_Alumno(1, "Alan Yair Cortes Lopez", 19, "Ingenieria en computacion", "CNI"));
    insertar_cabeza(p, alup);
    alup = crear_Nodo(crear_Alumno(2, "Rodrigo Garcia Nunez", 20, "Ingenieria en computacion", "CNI"));
    insertar_cabeza(p, alup);
    alup = crear_Nodo(crear_Alumno(3, "Pepe Montero Moya", 27, "Ingenieria en computacion", "CNI"));
    insertar_cabeza(p, alup);
    alup = crear_Nodo(crear_Alumno(4, "Ruben Garcia Alvarado", 20, "Ingenieria en computacion", "CNI"));
    insertar_cabeza(p, alup);
    cont = 4;
    do
    {
        printf("\n\n Buen dia!\n");
        printf(" 1- Agregar un alumno.\n");
        printf(" 2- Quitar un alumno.\n");
        printf(" 3- Vaciar la lista.\n");
        printf(" 4- Imprimir y actualizar la lista principal.\n"); //Imprime todos los nodos de la lista en consola y en el txt. Cada vez que se escoja la opcion 1,2,3 o 5, esta opción es capáz se actualizar el txt
        printf(" 5- Depurar alumnos menores de 23.\n"); //Elimina a los alumnos menores de 23 de la lista principal y los añade a la lista L23
        printf(" 6- Imprimir Lista de menores de 23.\n"); 
        printf(" 7- Verificacion de lista principal de alumnos.\n"); // Lee el txt generado en 4 y escribe lo leido en el txt salida
        printf(" 8- Salir o Terminar\n");
        printf(" Selecciona una Opcion: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            Nodo *alu;
            do
            { //el progarma pide datos del alumno que se va  ingresar
                printf("\n Ingresa los datos del alumno: ");
                printf("\n Matricula: ");
                scanf("%d", &id);
                fflush(stdin); //limpia el buffer de entrada
                printf(" Nombre: ");
                scanf("%[^\n]", &Name);
                fflush(stdin);
                printf(" Edad: ");
                scanf("%d", &Edad);
                fflush(stdin);
                printf(" Licenciatura: ");
                scanf("%[^\n]", &Licenciatura);
                fflush(stdin);
                printf(" Division Academica: ");
                scanf("%[^\n]", &DivisionAC);
                fflush(stdin);

                //se crear el nodo con los datos que dio el usuario sobre el nuevo alumno
                alu = crear_Nodo(crear_Alumno(id, Name, Edad, Licenciatura, DivisionAC));
                insertar_cabeza(p, alu); //el nodo creado se inserta en la cabeza de la lista
                cont++;
                printLista(p);
                printf("\n Deseas ingresar otro alumno? 1=Si 0=No");
                scanf("%d", &opt);

            } while (opt == 1);
            break;
        }
        case 2:
        {
            opt = 0;
            Nodo *aux;
            do
            {
                printf(" Escribe la Matricula del alumno a dar de baja: ");
                scanf("%d", &id);
                aux = buscaElemento1(p, id);
                if (aux == NULL)
                {
                    break;
                }
                aux = quitar_enmedio1(p, id); //en este caso, el apuntador aux no se utiliza más que para invocar a la funcion quitar_enmedio1
                cont--;
                printf("\n Deseas dar de baja a otro alumno? 1=Si, 0=No");
                scanf("%d", &opt);
            } while (opt == 1);
            break;
        }
        case 3:
        {
            vaciarLista(p);
            break;
        }
        case 4:
        {
            int indi = 0;
            Nodo *auxp;
            auxp = p->cabeza;
            printLista(p);
            if (isEmpty(*p) == 1)
            {
                break;
            }
            FILE *fp = fopen("alumnos.txt", "w"); //se abre o se crea un archivo en modo de lectura
            fprintf(fp, "Alumnos\n\n");
            do
            {
                //mientras qu el indicador sea menor que el contador, se imprmen los datos de cada nodo de la lista principal en el archivo
                fprintf(fp, "Matricula: %d\n", auxp->datos->Matricula);
                fprintf(fp, "Nombre: %s\n", auxp->datos->name);
                fprintf(fp, "Edad: %d\n", auxp->datos->edad);
                fprintf(fp, "Licenciatura: %s\n", auxp->datos->licenciatura);
                fprintf(fp, "Division Academica: %s\n\n", auxp->datos->divisionAC);
                indi++;
                auxp = auxp->sig; //auxp se actualiza para apuntar al siguiente nodo

            } while (indi < cont);
            free(auxp); //libera a auxp
            fflush(fp); //limpia el flujo de datos de fp
            fclose(fp); //cierra y actualiza el archivo
            printf("\n alumnos.txt generado con exito!");
            break;
        }
        case 5:
        {
            Nodo *alu23;
            Nodo *aux1;
            Nodo *aux2;
            aux1 = p->cabeza;
            /*if(cont==1 && aux1->datos->edad<23){
                depurar_23(aux, aux1, alu23, L23, p);
                contm++; 
                cont--;  
            }*/
            if(cont<=1 ){ //|| aux1->datos->edad>23
                printf(" Ya no hay alumnos menores de 23 registrados en la lista principal");
                
            }
            else{
            do
            {
                aux2 = aux1->sig; //aux2 toma el valor del nodo siguiente de aux1
                if (aux1->datos->edad < 23)
                {
                    //invocacion de depurar_23 - Funcionamiento explicado en FuncionesP2.c
                    depurar_23(aux, aux1, alu23, L23, p);
                    contm++; //el contador de la lista de alumnos menores incrementa en uno
                    cont--;  //el contador de la lista principal decrementa en uno
                }
                else
                {
                }
                aux1 = aux1->sig; //se actualiza aux1 para apuntar al siguiente nodo
                
            }  while (aux2->sig != NULL);

            if (aux2->datos->edad < 23) //como aux1 nunca llega al ultimo nodo, se llama a la funcion con aux2 para ver si es necesario depurar el ultimo nodo
            {
                depurar_23(aux, aux2, alu23, L23, p);
                contm++;
                cont--;
            }
            else
            {
            }
        }
            printf("\n Depuracion completa");
            //printLista(L23);
            //free(alu23);
            //free(aux1);
            //free(aux2);
            break;
        }
        case 6:
        {
            if (contm == 0) //si no hay alumnos en la lista de mennores de 23, sale del case
            {
                printf(" No hay alumnos menores de 23 registrados hasta ahora\n");
                break;
            }
            int indi = 0;
            Nodo *auxp;
            Nodo *auxp1;
            auxp = L23->cabeza;

            printLista(L23);
            FILE *fp = fopen("Menores.txt", "w"); //Se abre o se crea unn archivo en modo de escritura
            fprintf(fp, "Alumnos\n\n");
            do
            {
                //se imprimen en el archivo los datos que almacenan los nodos de la lista L23
                auxp1 = auxp->sig;
                fprintf(fp, "Matricula: %d\n", auxp->datos->Matricula);
                fprintf(fp, "Nombre: %s\n", auxp->datos->name);
                fprintf(fp, "Edad: %d\n", auxp->datos->edad);
                fprintf(fp, "Licenciatura: %s\n", auxp->datos->licenciatura);
                fprintf(fp, "Division Academica: %s\n\n", auxp->datos->divisionAC);
                auxp = auxp->sig;

            } while (auxp1 != NULL);
            //free(auxp);
            fflush(fp); // Se limpia el flujo de datos
            fclose(fp); // se cierra y actualiza el archivo
            printf("\n Menores.txt generado con exito!");
            break;
        }
        case 7:
        {
            FILE *fluj = fopen("salida.txt", "w");   // se abre un archivo en modo de escritura
            FILE *flujo = fopen("alumnos.txt", "r"); // se abre un archivo en modo de lectura
            if (flujo == NULL)
            {
                printf(" NO SE HA CREADO EL ARCHIVO A LEER\n");
                break;
            }
            char car;

            while (feof(flujo) == 0)
            {
                car = fgetc(flujo); // car obtiene un carcater que obtiene la funcion fgetc con el apuntador flujo
                fputc(car, fluj);   //se imprime el caracter en el archivo "salida.txt"
            }

            fflush(flujo); // limpieza de flujo de datos
            fclose(flujo); // se cierra el archivo de lectura
            fflush(fluj);  // limpieza de flujo de datos
            fclose(fluj);  // se cierra el archivo de escritura
            printf("\n salida.txt generado con exito!");
            break;
        }
        default:
        {
            break;
        }
        }
    } while (option != 8);
    printf("\n HASTA PRONTO!");
    free(p);
    free(L23);
    free(alup);
    free(aux);
    return 0;
}