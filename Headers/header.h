#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
char appuntamenti[150]; //array dove vengono salvati gli appuntamenti inseriti dall'utente
}Agenda;
typedef enum{Gennaio=1,Febbraio,Marzo,Aprile,Maggio,Giugno,Luglio,Agosto,Settembre,Ottobre,Novembre,Dicembre}Mesi;
int calcolo_mese[]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};//array globale per il calcolo del mese
int menu();
void anno_bisestile(int* ,bool* );
void ins_mese(Mesi* ,int* ,int* ,bool* );
void inserire_appuntamento(Agenda [][24],int* ,int* );
void disdici_appuntamento(Agenda [][24],int* ,int* );
void vis_app(Agenda [][24],Mesi* ,int* );
#endif // HEADER_H_INCLUDED
