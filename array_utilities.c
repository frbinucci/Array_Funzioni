/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>
#include "array_utilities.h"

void caricaArray(const double *array,size_t dim);
//Funzione necessaria al caricamento dell'array.
void caricaArray(const double *array,size_t dim)
{
    for(int i=0;i<dim;i++)
    {
        printf("Inserire l'elemento n.%d: ",i+1);
        scanf("%lf",(array+i));
    }
}
//Funzione necessaria alla stampa dell'array.
void stampaArray(const double const *array,size_t dim)
{
    for(int i=0;i<dim;i++)
    {
        printf("%d)%-3.2lf",i+1,*(array+i));
        puts("");
    }
}
//Funzione necessaria alla somma degli elementi dell'array.
double sommaElementi(const double *array,size_t dim)
{
    double somma=0;
    for(int i=0;i<dim;i++)
    {
        somma+=*(array+i);
    }
    
    return somma;
}
//Funzione necessaria al calcolo della media degli  elementi dell'array.
double mediaElementi(const double *array,size_t dim)
{
    double media=0;
    for(int i=0;i<dim;i++)
    {
        media+=*(array+i);
    }
    media/=dim;
    return media;
}
//Funzione necessaria all'ordinamento dell'array
void bubbleSort(const double *array,size_t dim,int (*compare)(double elementA,double elementB))
{
    for(int pass=0;pass<dim;pass++)
    {
        for(int i=0;i<dim-1;i++)
        {
            if((*compare)(array[i],array[i+1]))
            {
                swap(&array[i],&array[i+1]);
            }
        }
    }
}
//Funzione necessaria allo scambio di due elementi dell'array.
void swap(double *elementA,double *elementB)
{
    int hold = *elementA;
    *elementA = *elementB;
    *elementB = hold;
}
//Funzione necessaria all'ordinamento crescente.
int ascending(double elementA,double elementB)
{
    return elementA>elementB;
}
//Funzione necessaria all'ordinamento decrescente.
int descending(double elementA,double elementB)
{
    return elementA<elementB;
}

