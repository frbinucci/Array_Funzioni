/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: franc
 *
 * Created on 11 agosto 2017, 12.31
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_utilities.h"
/*
 * Questo programma consente di effettuare delle operazioni di diverso tipo
 * su un array di tipo double. Il programma si avvale dei puntatori a funzione.
 */
//Definizione dei prototipi

int main(int argc, char** argv) {
    
    int dim;
    printf("%s","Inserire la dimensione dell'array: ");
    scanf("%d",&dim);
   
    double array[dim];
    int scelta;
    double somma,media;
    
    //Definizione di due array di puntatori a funzione.
    /*Il primo array (printLoad) contiene le funzioni necessarie al caricamento
     * e alla stampa dell'array.
     * Il secondo array (sommaMedia) contiene le funzioni necessarie al calcolo
     * di somma e media degli elementi dell'array.
     * */
    void (*voidFunctions[2])(const double *array,size_t dim);
    double (*sommaMedia[2])(const double *array,size_t dim);
    
    //Caricamento degli array con le funzioni necessarie.
    voidFunctions[0] = caricaArray;
    voidFunctions[1] = stampaArray;
    sommaMedia[0] = sommaElementi;
    sommaMedia[1] = mediaElementi;
    
    /*--TEST--
     Stampa degli indirizzi delle locazioni di memoria da cui inizia la memorizzazione
     delle varie funzioni.*/
    puts("");
    puts("Funzioni necessarie alla somma e al caricamento: ");
    for(int i=0;i<2;i++)
    {
        printf("La funzione n.%d e' allocata a partire dall'indirizzo: %p",i+1,voidFunctions[i]);
        puts("");
    }
    puts("");
    puts("Funzioni necessarie al calcolo di somma e media: ");
    for(int i=0;i<2;i++)
    {
        printf("La funzione n.%d e' allocata a partire dall'indirizzo: %p",i+1,sommaMedia[i]);
        puts("");       
    }
 
    do
    {
        puts("");
        puts("Cosa si vuol fare?");
        puts("1.Caricare l'array");
        puts("2.Stampare l'array");
        puts("3.Sommare gli elementi");
        puts("4.Calcolare la media degli elementi");
        puts("5.Ordinare l'array in ordine crescente");
        puts("6.Ordinare l'array in ordine decrescente");
        puts("0.Uscire dal programma");
        scanf("%d",&scelta);
        puts("");
        
        switch(scelta)
        {
            case 1:
                voidFunctions[0](array,dim);
                break;
            case 2:
                voidFunctions[1](array,dim);
                break;
            case 3:
                somma = sommaMedia[0](array,dim);
                printf("La somma degli elementi dell'array e': %-3.2lf",somma);
                puts("");
                break;
            case 4:
               media = sommaMedia[1](array,dim);
               printf("La media degli elementi dell'array e': %-3.2lf",media);
               puts("");
               break;
            case 5:
                bubbleSort(array,dim,ascending);
                puts("");
                break;
            case 6:
                bubbleSort(array,dim,descending);
                puts("");
                break;
            case 0:
                break;
            default:
                puts("Valore non riconosciuto!");
                break;
        }
    }while(scelta!=0);

    
    
    
    return (EXIT_SUCCESS);
}

