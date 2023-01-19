/*3 EXAMEN       2CV3
Perez Muñoz Kevin Isaac     

El siguiente programa lee 50 datos de 50 atletas de 7 diferenctes paises que se guardaran en una arreglo de estructuras.

Despues guardaremos esos 50 datos en 3 arboles binarios diferentes, uno que guarda a los atletas con medallas de ORO
otro con las medallas de PLATA y otro con las de BRONCE.
La inserccion en sus respectivos arboles tendran la condicion de ingresarse en orden alfabetico.
Para comprobar el orden alfabetico se utilizo el recorrido inOrden que de acuerdo con la configuracion de nuestra inserccion
deberia de mostrar el arreglo ordenando alfabeticamente.

Despues tendremos 2 funciones que nos ayudan a buscar un atleta entre estos arboles, solo deberemos ingresar Nombre y Nacionalidad.
Si el jugador existe, tambien se mostrar todos los atletas con la misma nacionalidad y su total de medallas consiguidas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 50


typedef struct atleta{
    char nombre[25];
    char pais[20];
    //char medalla[10];
    int medalla;    //1 ORO 2 PLATA 3 BRONCE
    //int status;     //Nos servira para controlar las impresiones de los atletas de la misma nacionalidad/
}Atleta;


//Estructura para manipular los NODOS DEL ARBOL
typedef struct nodo{
    Atleta datos;
    struct nodo* izq;
    struct nodo* der;
}Nodo;


void insertarNodo(Nodo** ptrArbol, Atleta valores);
void inOrden(Nodo* ptrArbol);  //(izq, raiz, der)
int buscar(Nodo* ptrArbol, char nombreF[], char paisF[]);
void inOrden2(Nodo* ptrArbol, char paisF[], int *acumPtsF);


int main(){
    Atleta arreglo_Atl[TAMANIO];  //Declaro un arreglo de estructuras donde estara toda nuestra data;
    int i;








    //Ingreso los datos uno por uno porque no pude hacerlo atraves de un archivo externo txt :C
//US
//Jordan US ORO
    strcpy(arreglo_Atl[0].nombre, "Jordan");
    strcpy(arreglo_Atl[0].pais, "US");
    arreglo_Atl[0].medalla = 1;
//LeBron  US ORO
    strcpy(arreglo_Atl[1].nombre, "LeBron");
    strcpy(arreglo_Atl[1].pais, "US");
    arreglo_Atl[1].medalla = 1;
//Kevin Durant, US, ORO
    strcpy(arreglo_Atl[2].nombre, "Kevin");
    strcpy(arreglo_Atl[2].pais, "US");
    arreglo_Atl[2].medalla = 1;
//Kobe Bryant, US, ORO
    strcpy(arreglo_Atl[3].nombre, "Kobe");
    strcpy(arreglo_Atl[3].pais, "US");
    arreglo_Atl[3].medalla = 1;
//Chris Paul, US, ORO
    strcpy(arreglo_Atl[4].nombre, "Chris");
    strcpy(arreglo_Atl[4].pais, "US");
    arreglo_Atl[4].medalla = 1;
//Tim Duncan, US, PLATA
    strcpy(arreglo_Atl[5].nombre, "Duncan");
    strcpy(arreglo_Atl[5].pais, "US");
    arreglo_Atl[5].medalla = 2;
//Kyrie Irving, US, BRONCE
    strcpy(arreglo_Atl[6].nombre, "Kyrie");
    strcpy(arreglo_Atl[6].pais, "US");
    arreglo_Atl[6].medalla = 2;
//Davin Booker, US, BRONCE
    strcpy(arreglo_Atl[7].nombre, "Booker");
    strcpy(arreglo_Atl[7].pais, "US");
    arreglo_Atl[7].medalla = 3;


//MEXICO
//Hugo Sanchez, MEXICO, ORO
    strcpy(arreglo_Atl[8].nombre, "Hugo");
    strcpy(arreglo_Atl[8].pais, "MEXICO");
    arreglo_Atl[8].medalla = 1;
//Oribe, MEXICO, ORO
    strcpy(arreglo_Atl[9].nombre, "Oribe");
    strcpy(arreglo_Atl[9].pais, "MEXICO");
    arreglo_Atl[9].medalla = 1;
//Ochoa, MEXICO, PLATA
    strcpy(arreglo_Atl[10].nombre, "Ochoa");
    strcpy(arreglo_Atl[10].pais, "MEXICO");
    arreglo_Atl[10].medalla = 2;
//Tecatito, MEXICO, BRONCE
    strcpy(arreglo_Atl[11].nombre, "Tecatito");
    strcpy(arreglo_Atl[11].pais, "MEXICO");
    arreglo_Atl[11].medalla = 3;
//Javier, MEXICO, ORO
    strcpy(arreglo_Atl[12].nombre, "Javier");
    strcpy(arreglo_Atl[12].pais, "MEXICO");
    arreglo_Atl[12].medalla = 1;
//Corona, MEXICO, BRONCE
    strcpy(arreglo_Atl[13].nombre, "Corona");
    strcpy(arreglo_Atl[13].pais, "MEXICO");
    arreglo_Atl[13].medalla = 3;
//Raul, MEXICO, BRONCE
    strcpy(arreglo_Atl[14].nombre, "Raul");
    strcpy(arreglo_Atl[14].pais, "MEXICO");
    arreglo_Atl[14].medalla = 3;


//ARGENTINA
//Manu  ARGENTINA ORO
    strcpy(arreglo_Atl[15].nombre, "Manu");
    strcpy(arreglo_Atl[15].pais, "ARGENTINA");
    arreglo_Atl[15].medalla = 1;
//Messi ARGENTINA ORO
    strcpy(arreglo_Atl[16].nombre, "Messi");
    strcpy(arreglo_Atl[16].pais, "ARGENTINA");
    arreglo_Atl[16].medalla = 1;
//DiMaria ARGENTINA PLATA
    strcpy(arreglo_Atl[17].nombre, "DiMaria");
    strcpy(arreglo_Atl[17].pais, "ARGENTINA");
    arreglo_Atl[17].medalla = 2;
//Campazo ARGENTINA BRONCE
    strcpy(arreglo_Atl[18].nombre, "Campazo");
    strcpy(arreglo_Atl[18].pais, "ARGENTINA");
    arreglo_Atl[18].medalla = 3;
//Maradona ARGENTINA PLATA
    strcpy(arreglo_Atl[19].nombre, "Maradona");
    strcpy(arreglo_Atl[19].pais, "ARGENTINA");
    arreglo_Atl[19].medalla = 2;
//Kun ARGENTINA PLATA
    strcpy(arreglo_Atl[20].nombre, "Kun");
    strcpy(arreglo_Atl[20].pais, "ARGENTINA");
    arreglo_Atl[20].medalla = 2;
//Kempes ARGENTINA BRONCE
    strcpy(arreglo_Atl[21].nombre, "Kempes");
    strcpy(arreglo_Atl[21].pais, "ARGENTINA");
    arreglo_Atl[21].medalla = 3;


//GERMANY
//Dirk Nowitzki   GERMANY ORO
    strcpy(arreglo_Atl[22].nombre, "Dirk");
    strcpy(arreglo_Atl[22].pais, "GERMANY");
    arreglo_Atl[22].medalla = 1;
//Luka GERMANY ORO
    strcpy(arreglo_Atl[23].nombre, "Luka");
    strcpy(arreglo_Atl[23].pais, "GERMANY");
    arreglo_Atl[23].medalla = 1;
//Embid GERMANY BRONCE
    strcpy(arreglo_Atl[24].nombre, "Embid");
    strcpy(arreglo_Atl[24].pais, "GERMANY");
    arreglo_Atl[24].medalla = 3;
//Giannis GERMANY PLATA
    strcpy(arreglo_Atl[25].nombre, "Giannis");
    strcpy(arreglo_Atl[25].pais, "GERMANY");
    arreglo_Atl[25].medalla = 2;
//Jokic GERMANY PLATA
    strcpy(arreglo_Atl[26].nombre, "Jokic");
    strcpy(arreglo_Atl[26].pais, "GERMANY");
    arreglo_Atl[26].medalla = 2;
//Pascal GERMANY BRONCE
    strcpy(arreglo_Atl[27].nombre, "Pascal");
    strcpy(arreglo_Atl[27].pais, "GERMANY");
    arreglo_Atl[27].medalla = 3;
//Dennis GERMANY BRONCE 
    strcpy(arreglo_Atl[28].nombre, "Dennis");
    strcpy(arreglo_Atl[28].pais, "GERMANY");
    arreglo_Atl[28].medalla = 3;


//SPAIN
//Gasol  SPAIN     ORO
    strcpy(arreglo_Atl[29].nombre, "Gasol");
    strcpy(arreglo_Atl[29].pais, "SPAIN");
    arreglo_Atl[29].medalla = 1;
//Ibaka SPAIN PLATA
    strcpy(arreglo_Atl[30].nombre, "Ibaka");
    strcpy(arreglo_Atl[30].pais, "SPAIN");
    arreglo_Atl[30].medalla = 2;
//Xavi SPAIN PLATA
    strcpy(arreglo_Atl[31].nombre, "Xavi");
    strcpy(arreglo_Atl[31].pais, "SPAIN");
    arreglo_Atl[31].medalla = 2;
//Iniesta PLATA
    strcpy(arreglo_Atl[32].nombre, "Iniesta");
    strcpy(arreglo_Atl[32].pais, "SPAIN");
    arreglo_Atl[32].medalla = 1;
//Ramos PLATA
    strcpy(arreglo_Atl[33].nombre, "Ramos");
    strcpy(arreglo_Atl[33].pais, "SPAIN");
    arreglo_Atl[33].medalla = 2;    
//Pique PLATA
    strcpy(arreglo_Atl[34].nombre, "Pique");
    strcpy(arreglo_Atl[34].pais, "SPAIN");
    arreglo_Atl[34].medalla = 2;
//Isco BRONCE
    strcpy(arreglo_Atl[35].nombre, "Isco");
    strcpy(arreglo_Atl[35].pais, "SPAIN");
    arreglo_Atl[35].medalla = 3;


//FRANCE
//Tony Parker, FRANCE     ORO
    strcpy(arreglo_Atl[36].nombre, "Tony");
    strcpy(arreglo_Atl[36].pais, "FRANCE");
    arreglo_Atl[36].medalla = 1;
//Batum, FRANCE, PLATA
    strcpy(arreglo_Atl[37].nombre, "Batum");
    strcpy(arreglo_Atl[37].pais, "FRANCE");
    arreglo_Atl[37].medalla = 2;
//Rudy FRANCE BRONCE
    strcpy(arreglo_Atl[38].nombre, "Rudy");
    strcpy(arreglo_Atl[38].pais, "FRANCE");
    arreglo_Atl[38].medalla = 3;
//Zidane FRANCE ORO
    strcpy(arreglo_Atl[39].nombre, "Zidane");
    strcpy(arreglo_Atl[39].pais, "FRANCE");
    arreglo_Atl[39].medalla = 1;
//Pogba FRANCE BRONCE
    strcpy(arreglo_Atl[40].nombre, "Pogba");
    strcpy(arreglo_Atl[40].pais, "FRANCE");
    arreglo_Atl[40].medalla = 3;
//Mbappe FRANCE ORO
    strcpy(arreglo_Atl[41].nombre, "Mbappe");
    strcpy(arreglo_Atl[41].pais, "FRANCE");
    arreglo_Atl[41].medalla = 1;
//Griezmann FRANCE BRONCE
    strcpy(arreglo_Atl[42].nombre, "Griezmann");
    strcpy(arreglo_Atl[42].pais, "FRANCE");
    arreglo_Atl[42].medalla = 3;


//CANADA
//Nash   CANADA     ORO
    strcpy(arreglo_Atl[43].nombre, "Nash");
    strcpy(arreglo_Atl[43].pais, "CANADA");
    arreglo_Atl[43].medalla = 1;
//Wiggings    CANADA  BRONCE
    strcpy(arreglo_Atl[44].nombre, "Wiggings");
    strcpy(arreglo_Atl[44].pais, "CANADA");
    arreglo_Atl[44].medalla = 3;
//Murray  CANADA BRONCE
    strcpy(arreglo_Atl[45].nombre, "Murray");
    strcpy(arreglo_Atl[45].pais, "CANADA");
    arreglo_Atl[45].medalla = 3;
//Brooks  CANADA BRONCE
    strcpy(arreglo_Atl[46].nombre, "Brooks");
    strcpy(arreglo_Atl[46].pais, "CANADA");
    arreglo_Atl[46].medalla = 3;
//Fox CANADA BRONCE
    strcpy(arreglo_Atl[47].nombre, "Fox");
    strcpy(arreglo_Atl[47].pais, "CANADA");
    arreglo_Atl[47].medalla = 3;
//Tristan CANADA BRONCE
    strcpy(arreglo_Atl[48].nombre, "Tristan");
    strcpy(arreglo_Atl[48].pais, "CANADA");
    arreglo_Atl[48].medalla = 3;
//Olynyk CANADA BRONCE
    strcpy(arreglo_Atl[49].nombre, "Olynyk");
    strcpy(arreglo_Atl[49].pais, "CANADA");
    arreglo_Atl[49].medalla = 3;











//Inicializamos los arboles
    Nodo* arbolORO = NULL;
    Nodo* arbolPLATA = NULL;
    Nodo* arbolBRONCE = NULL;


    //Ingresa a los ATLETAS en sus arboles respectivos de acuerdo a su medalla 
    for(i=0; i<TAMANIO; i++){
        //Filtro de medallas
        //Elige el arbol segun la medalla 
        switch(arreglo_Atl[i].medalla){
            case 1: //ASIGNAR AL ARBOL ORO
                //printf("%s tiene ORO", arreglo_Atl[i].nombre);
                insertarNodo(&arbolORO, arreglo_Atl[i]);
            break;

            case 2: //ASIGNAR AL ARBOL PLATA
                //printf("%s tiene PLATA", arreglo_Atl[i].nombre);
                insertarNodo(&arbolPLATA, arreglo_Atl[i]);
            break;

            case 3: //ASIGNAR AL ARBOL BRONCE
                //printf("%s tiene BRONCE", arreglo_Atl[i].nombre);
                insertarNodo(&arbolBRONCE, arreglo_Atl[i]);
            break;

            default:
                printf("ESTE COMPETIDOR NO TIENE MEDALLA\n");
            break;
        }//Fin del switch 
    }


    //Comprueba que los ALTLETAS hayan sido organizados alfabeticamente en cada uno de los arboles
    //para verificar ese orden utilizamos el recorrido inOrden
    printf("\n\nRecorrido inOrden:  (ARBOL ORO) \n");
    inOrden(arbolORO);

    printf("\n\nRecorrido inOrden:  (ARBOL PLATA) \n");
    inOrden(arbolPLATA);

    printf("\n\nRecorrido inOrden:  (ARBOL BRONCE) \n");
    inOrden(arbolBRONCE);





    char r[20];     //Guardara el nombre a buscar
    char r2[20];    //Guardara la nacionalidad
    int bandera = 649;  //Bandera para verificar si se encontrol al atleta y despues para buscar a su equipo
    int r3 = 0;         //Bandera para controlar el ciclo while que nos sirve de menu
    int acumPts =0;     //Acumulara los puntos totales de los equipos por nacionalidades


    while(r3!=-1){
        printf("\n\n\t\tFuncion BUSCAR:  \n");
        printf("\tIngrese un nombre ");
        //scanf("%s", r);
        //fgets(r, 20, stdin);      //Con fgets no me funcionaba a la hora de comparar no se porque:c
        gets(r);                    //Con gets funciono 
        printf("\tIngrese una nacionalidad ");
        gets(r2);                   
        //printf("BANDERA: %d", bandera);

        bandera = buscar(arbolORO, r, r2);
        //printf("BANDERA: %d", bandera);
        if(bandera==1){
            printf("\n\tEl atleta SI FUE ENCONTRADO\n");
        }else{
            bandera = buscar(arbolPLATA, r, r2);
            if(bandera==1){
                printf("\n\tEl atleta SI FUE ENCONTRADO\n");
            }else{
                bandera = buscar(arbolBRONCE, r, r2);
                if(bandera==1){
                printf("\n\tEl atleta SI FUE ENCONTRADO\n");
                }else{
                                printf("\n\tEl atleta NO FUE ENCONTRADO:c\n");
                }
            }
        }//Fin del else
        //printf("\nBAAAAAANDA: %d", bandera);
        //printf("\nNACIONALIDAD: %s\n", r2);
        if(bandera == 1){
            printf("\n\tBuscando ATLETLAS del pais %s\n\n", r2);
            inOrden2(arbolORO, r2, &acumPts);
            inOrden2(arbolPLATA, r2, &acumPts);
            inOrden2(arbolBRONCE, r2, &acumPts);
            
            printf("ACUMULACION DE PUNTOS: %d\n\n\n", acumPts);
        }
        printf("Ingrese -1 para salir/Cualquier otro numero para intentarlo de nuevo: ");
        scanf("%d", &r3);
        fflush(stdin);	
        bandera=6;
        acumPts = 0;
    }//Fin del while
    
    printf("\n\n\n\tFIN DEL PROGRAMA\n");
    return 0;
}//Fin del MAIN



void inOrden(Nodo* ptrArbol){  //(izq, raiz, der)
    if(ptrArbol!= NULL){    //Verificamos que el arbol no este vacio
        inOrden(ptrArbol->izq);
        printf("\t%s", ptrArbol->datos.nombre);
        printf("\t%s", ptrArbol->datos.pais);
        
        switch(ptrArbol->datos.medalla){
            case 1:
            printf("\tORO\n");
            break;

            case 2:
            printf("\tPLATA\n");
            break;

            case 3:
            printf("\tBRONCE\n");
            break;
        }
        inOrden(ptrArbol->der);
    }
}//Fin de inOrder



void insertarNodo(Nodo** ptrArbol, Atleta valores){
    //Si es el primer nodo del arbol se crea el nodo RAIZ
    int mover = 0;  //Para cambiar de caracter, en caso de que tengan la misma letra
                    //moverse al siguiente caracter y comparar.
    
    int bandera = 1;//Para controlar el ciclo while

    if(*ptrArbol == NULL){ //Si el arbol ESTA VACIO
        *ptrArbol = malloc(sizeof(Nodo));

        //Ya que se asigno la memoria, asigna los datos
        if(*ptrArbol != NULL){   //verificacion de que se asigno memoria a este apuntador
            (*ptrArbol)->datos = valores;
            (*ptrArbol)->izq = NULL;
            (*ptrArbol)->der = NULL;
        }else{
            //printf("\n\tNo se pudo insertar %d. No se pudo asignar la memoria correctamente.\n", valor);
        }
    }
    //printf("El caracter es: %c", (*ptrArbol)->datos.nombre[0]);
    else{  //Si el arbol NO ESTA VACIO
        while(bandera !=-1){
            //printf("NO ESTA VACIO ");
            //Si el CARACTER es menor a la raiz va para la izq
            //if(valor < (*ptrArbol)->dato){
            if(valores.nombre[mover] < (*ptrArbol)->datos.nombre[mover]){
                //arreglo_Atl[0].nombre[0] > arreglo_Atl[1].nombre[0]
                bandera = -1;
                insertarNodo(&((*ptrArbol)->izq), valores); 

            }
            //Si el CARACTER es mayor a la raiz va para la derecha
            //else if(valor > (*ptrArbol)->dato){
            else if(valores.nombre[mover] > (*ptrArbol)->datos.nombre[mover]){
                bandera = -1;
                insertarNodo(&((*ptrArbol)->der), valores); 
            }
            //Si el CARACTER es igual  la raiz se comparara su siguiente caracter
            else if(valores.nombre[mover] == (*ptrArbol)->datos.nombre[mover]){
                mover += 1;
            }
        }//Fin del while
    }
}//Fin de insertarNodo


int buscar(Nodo* ptrArbol, char nombreF[], char paisF[]){
    //printf("Buscando: %s\n", nombreF);
    //printf("\tValor Actual: %s\n", ptrArbol->datos.nombre);
    int bandera = 1;
    int mover = 0; 
    if(ptrArbol == NULL){
        return 0;
  //  }else if(ptrArbol->dato == valor){
    }else if( (strcmp(nombreF, (ptrArbol->datos.nombre))) == 0){
        if( (strcmp(paisF, (ptrArbol->datos.pais))) == 0){
            printf("\n\tATLETA: %s\n", ptrArbol->datos.nombre);
            printf("\tNacionalidad: %s\n", ptrArbol->datos.pais);
            switch(ptrArbol->datos.medalla){
                case 1: //ASIGNAR AL ARBOL ORO
                    printf("\tMedalla: ORO\n");
                break;

                case 2: //ASIGNAR AL ARBOL PLATA
                    printf("\tMedalla: PLATA\n");
                break;

                case 3: //ASIGNAR AL ARBOL BRONCE
                    printf("\tMedalla: BRONCE\n");
                break;
            }//Fin del switch 
            return 1;
        }else{
            return 0;
        }
    //}else if(valor > ptrArbol->dato){
    }else{
        while(bandera != -1){
            if(nombreF[mover] < ptrArbol->datos.nombre[mover]){
                bandera = -1;
                return buscar(ptrArbol->izq, nombreF, paisF);
            }
            else if(nombreF[mover] > ptrArbol->datos.nombre[mover]){
                bandera = -1;
                return buscar(ptrArbol->der, nombreF, paisF);
            }
            //Si el CARACTER es igual  la raiz se comparara su siguiente caracter
            else if(nombreF[mover] == ptrArbol->datos.nombre[mover]){
                mover += 1;
            }
        }//Fin del while
    }//Fin del else
    
}//Fin de buscar 

void inOrden2(Nodo* ptrArbol, char paisF[], int *acumPtsF){
    if(ptrArbol!= NULL){    //Verificamos que el arbol no este vacio
        inOrden2(ptrArbol->izq, paisF, &(*acumPtsF));
        if((strcmp(paisF, ptrArbol->datos.pais)) == 0){
            //*acumPtsF += 1;
            printf("\t%s", ptrArbol->datos.nombre);
            printf("\t%s", ptrArbol->datos.pais);
            switch(ptrArbol->datos.medalla){
                case 1:
                printf("\tORO +10PTS\n");
                *acumPtsF += 10;
                break;

                case 2:
                printf("\tPLATA + 5PTS\n");
                *acumPtsF += 5;
                break;

                case 3:
                printf("\tBRONCE +2PTS\n");
                *acumPtsF += 2;
                break;
            }
        }//Fin del if
        inOrden2(ptrArbol->der, paisF, &(*acumPtsF));
    }
}//Fin de inOrder