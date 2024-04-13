#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5


struct compu
{
    int velocidad; // entre 1 y 3 GHz
    int anio; //entre 2015 y 2023
    int cantidadNucleos; //entre 1 y 8;
    char *tipo_cpu; //valores del arreglo tipos
}typedef pc;

//funciones

void mostrarPc(pc computadoras[]);
void mostrarPcMasAntigua(pc computadoras[]);
void MostrarPcMayorVelocidad(pc computadoras[]);

int main ()
{
    char tipos[6][10]={"Intel", "AMD","Celeron","Athlon","Core","Pentium"}, *pTipos;
    pTipos = &tipos[0][0];
    srand(time(NULL));
    pc computadoras[N];


    //inicializacion para probar que se imprime bien
    //si movemos el puntero en el valor de la estructura no afecta afuera? o para añadirse a la struc analiza el valor de afuera y luego adentro lo opera como una "copia"?
    // pc computadoras[]=
    // {   {2,2021,4,pTipos+3*10},
    //     {3,2023,8,pTipos+1*10},
    //     {2,2020,7,pTipos+2*10},
    //     {1,2019,6,pTipos+4*10},
    //     {1,2018,5,pTipos+5*10}};

    //esta inicializacion sirve para la pregunta de como trabaja el puntero
    // pc computadoras[]=
    // {   {2,2016,4},
    //     {3,2023,8},
    //     {3,2020,7},
    //     {1,2019,6},
    //     {1,2018,5}};


    // pc *pCompuradoras;
    // pCompuradoras = computadoras;


    for (int i = 0; i <N; i++)
    {
        printf("\n-----------INGRESAR DATOS DE LA COMPUTADORA [%d]-----------", i+1);

        while ((computadoras[i].anio < 2015) || (computadoras[i].anio > 2023))
        {
            printf("\nIngrese el anio de fabricacion (entre 2015 - 2023): ");
            scanf("%d", &computadoras[i].anio);
        }
        
        computadoras[i].velocidad = 0;
        while ((computadoras[i].velocidad < 1) || (computadoras[i].velocidad >3))
        {
            printf("\nIngrese la velocidad del cpu (MHz, entre 1 y 3): ");
            scanf("%d", &computadoras[i].velocidad);
        }

        computadoras[i].cantidadNucleos = 0;
        while ((computadoras[i].cantidadNucleos < 1) || (computadoras[i].cantidadNucleos >8))
        {
            printf("\nIngrese la cantidad de nucleos del cpu (entre 1 y 8): ");
            scanf("%d", &computadoras[i].cantidadNucleos);
        }
        
        computadoras[i].tipo_cpu = (pTipos+((rand()%6)*10));
    }

    // for (int i = 0; i < N; i++)
    // {
    //     computadoras[i].tipo_cpu = (pTipos+((rand()%6)*10)); //porque no se modifica el puntero de afuera si estamos operando aritmeticamente con
    // }
    
    //mostramos el arreglo de estruct
    mostrarPc(computadoras);

    //mostramos la computadora mas antigua
    mostrarPcMasAntigua(computadoras);
    
    //mostramos la pc mas veloz
    MostrarPcMayorVelocidad(computadoras);
    return 0;
}


void mostrarPc(pc computadoras[])
{
    for (int i = 0; i < N; i++)
    {
        printf("\n----------Computadora [%d]----------\n", i+1);
        printf("Tipo CPU: %s\n", computadoras[i].tipo_cpu);
        printf("Nucleos: %d\n", computadoras[i].cantidadNucleos);
        printf("Anio: %d\n", computadoras[i].anio);
        printf("Velocidad: %d[MHz]\n", computadoras[i].velocidad);
    }
}
void mostrarPcMasAntigua(pc computadoras[])
{
    int anioCpu,indice=0;
    anioCpu = computadoras[0].anio;
    for (int i = 0; i < N; i++)
    {
        if ((computadoras[i].anio) < anioCpu)
        {
            anioCpu = computadoras[i].anio;
            indice = i;
        }
    }

    printf("\n------La computadora mas antigua es------\n");
    printf("Tipo CPU: %s\n", computadoras[indice].tipo_cpu);
    printf("Nucleos: %d\n", computadoras[indice].cantidadNucleos);
    printf("Anio: %d\n", computadoras[indice].anio);
    printf("Velocidad: %d[MHz]\n", computadoras[indice].velocidad);
}
void MostrarPcMayorVelocidad(pc computadoras[])
{
    int velocidad,indice=0;
    velocidad = computadoras[0].velocidad;
    for (int i = 0; i < N; i++)
    {
        if ((computadoras[i].velocidad) > velocidad)
        {
            velocidad = computadoras[i].velocidad;
            indice = i;
        }
    }
    printf("\n------La computadora mas veloz es------\n");
    printf("Tipo CPU: %s\n", computadoras[indice].tipo_cpu);
    printf("Nucleos: %d\n", computadoras[indice].cantidadNucleos);
    printf("Anio: %d\n", computadoras[indice].anio);
    printf("Velocidad: %d[MHz]\n", computadoras[indice].velocidad);
}