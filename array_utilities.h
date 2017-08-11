/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array_utilities.h
 * Author: franc
 *
 * Created on 11 agosto 2017, 14.51
 */

#ifndef ARRAY_UTILITIES_H
#define ARRAY_UTILITIES_H

#ifdef __cplusplus
extern "C" {
#endif
    
void caricaArray(const double *array,size_t dim);
void stampaArray(const double const *array,size_t dim);
double sommaElementi(const double *array,size_t dim);
double mediaElementi(const double *array,size_t dim);
void bubbleSort(const double *array,size_t dim,int (*compare)(double elementA,double elementB));

int ascending(double elementA,double elementB);
int descending(double elementA,double elementB);
void swap(double *elementA,double *elementB);





#ifdef __cplusplus
}
#endif

#endif /* ARRAY_UTILITIES_H */

