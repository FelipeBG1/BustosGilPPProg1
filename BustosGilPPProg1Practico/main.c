#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
typedef struct
{
    int id;
    char procesador[51];
    char marca[51];
    float precio;

}eNotebook;



float aplicarDescuento(float precio);
int contarCaracteres(char cadena1[],char x);
void ordenarNotebooks(eNotebook x[],int tam);


int main()
{
    float precioProducto;
    float precioFinal;
    char cadenaIngresada[51];
    int vecesCaracter;


    eNotebook lista[TAM]= {{1,"Pentium", "Intel",20.0},
                           {2,"Core 2", "Intel",15.0},
                           {3,"Cualquiera","AMD",30.0}};



    printf("\nIngrese el precio del producto: ");
    scanf("%f",&precioProducto);

    precioFinal = aplicarDescuento(precioProducto);

    printf("\n%.2f\n\n",precioFinal);

    printf("-------------------------------- Segundo ejercicio\n");
    printf("\nIngresa la cadena: ");
    fflush(stdin);
    gets(cadenaIngresada);

    vecesCaracter=contarCaracteres(cadenaIngresada,'e');
    printf("\nEl caracter buscado esta un total de %d veces\n\n",vecesCaracter);

    printf("-------------------------------- Tercer ejercicio\n");

    ordenarNotebooks(lista,TAM);

    printf("Id   Procesador   Marca   Precio\n");

    for(int i=0;i<TAM;i++)
    {
       printf("%2d   %s    %s    %.2f\n\n",lista[i].id, lista[i].procesador, lista[i].marca, lista[i].precio);
    }

    return 0;
}
float aplicarDescuento(float precio)
{
    float precioSinDescuento;
    float precioConDescuento;

    precioSinDescuento = precio*5/100;
    precioConDescuento = precio - precioSinDescuento;

    return precioConDescuento;
}

int contarCaracteres(char cadena1[],char x)
{
    int contadorCaracter=0;
    int tamCad;

    tamCad=strlen(cadena1);

    for(int i=0;i<tamCad;i++)
    {
        if(cadena1[i]== x)
        {
            contadorCaracter++;
        }
    }

    return contadorCaracter;
}


void ordenarNotebooks(eNotebook x[],int tam)
{
    eNotebook auxNotebook;

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(x[i].marca, x[j].marca)>0)
            {
                auxNotebook = x[i];
                x[i]= x[j];
                x[j]= auxNotebook;
            }
            else
            {
                if(strcmp(x[i].marca,x[j].marca)==0 && x[i].precio <x[j].precio)
                {
                    auxNotebook=x[i];
                    x[i]=x[j];
                    x[j]=auxNotebook;
                }
            }
        }
    }
}
