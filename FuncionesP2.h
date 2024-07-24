/*lista_simple.h*/                  //García Núñez Rodrigo
/*Prototipos y/o funciones*/
/*Estructuras principales*/

typedef struct Alumno {
    int Matricula;                 
    char name [30];
    int edad;
    char licenciatura [50];
    char divisionAC[30];
}Alumno;

typedef struct Nodo{
    Alumno *datos;
    struct Nodo *sig;
}Nodo;

typedef struct ListaS{
    Nodo *cabeza;
    //Nodo *cola;
}ListaS;



//FUNCIONES
Alumno* crear_Alumno(int ID, char NAME[20], int EDAD, char lic[50], char div[20]);
Nodo *crear_Nodo(Alumno *alumno);
ListaS *crear_ListaS();
int isEmpty(ListaS lista);
void insertar_cabeza(ListaS *lista, Nodo *aux);
void insertar_cola(ListaS *lista, Nodo *aux);
void insertar_enmedio(ListaS *lista, Nodo *anterior,Nodo *elemento);
Nodo * quitar_cabeza(ListaS *lista);
void quitar_cola(ListaS *lista);
void quitar_enmedio(ListaS *lista, Nodo *elemento);
Nodo* quitar_enmedio1(ListaS *lista, int ent);
Nodo* buscaElemento(ListaS *lista, Nodo *elemento);
Nodo* buscaElemento1(ListaS *lista, int ent);
//Nodo* buscaElemento(ListaS *lista, int ID);
void vaciarLista(ListaS *lista);
void printLista(ListaS *lista);
void depurar_23(Nodo *aux, Nodo *aux1, Nodo *alu23, ListaS *L23, ListaS *p);