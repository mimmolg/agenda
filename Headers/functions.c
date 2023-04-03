#include "header.h"
/*FUNCTION PER LA GENERAZIONE DEL MENU NON HA NESSUN PARAMETRO,E RESTITUISCE LA SCELTA EFFETTUATA DALL'UTENTE*/
int menu(){
    int scelta;
    printf("-------GESTIONE AGENDA ELETTRONICA-------\n");
    printf("[1] INSERISCI APPUNTAMENTO\n");
    printf("[2] DISDICI APPUNTAMENTO\n");
    printf("[3] INSERISCI ORA PER VISUALIZZARE APPUNTAMENTI DEL MESE\n");
    printf("[0] ESCI\n\n");
    printf("SCELTA :  \n");
    scanf("%d",&scelta);
    while(scelta<0 || scelta>4){
        printf("SCELTA NON VALIDA!!!!");
        printf("SCELTA : \n");
        scanf("%d",&scelta);
        return scelta;
    }
        return scelta;
}
/*QUESTA FUNZIONE SERVE A CONTROLLARE SE L'ANNO CHE HA INSERITO L'UTENTE E' BISESTILE OPPURE NO.
PRENDE IN INPUT L'ANNO INSERITO DALL'UTENTE E UNA VARABILE DI TIPO BOOLEANA SE L'ANNO E' BISESTILE LA VARABILE DIVENTA TRUE
ALTRIMENTI SARA' UGUALE A FALSE.*/
void anno_bisestile(int* anno,bool* bisestile){
printf("INSERISCI ANNO GESTIONE AGENDA :\n");
scanf("%d",anno);
if((*anno%4==0 && *anno%100!=0) || *anno%400==0){
//printf("L'anno inserito e' Bisestile !!\n");
*bisestile=true;

}else{
//printf("L'anno inserito non e' bisestile\n");
*bisestile=false;
}
}
/*FUNZIONE CHE CI PERMETTE DI INSERIRE IL MESE IL GIORNO E L'ORA IN BASE ALL'ANNO
CIOE' SE L'ANNO E' BISESTILE FEBBRAIO AVRA' 29 GIORNI ALTRIMENTI 28.*/
void ins_mese(Mesi* m,int* g,int* h,bool* bisestile){
bool trovato=true;
do{
printf("INSERIRE MESE :\n");
scanf("%d",m);              //L'UTENTE INSERISCE IL MESE FINO A QUANDO NON E' COMPRESO TRA 1 E 12
}while(*m<1 || *m>12);
trovato=false;
if(*bisestile){ //SE L'ANNO E' BISESTILE ALLORA FEBBRAIO AVRA' 29 GIORNI
if(*m==Febbraio){
     do{
        printf("INSERIRE GIORNO (DA 1 A 29): FORMATO GG\n");
        scanf("%d",g);
        }while(*g<1 || *g>29);
        trovato=true;
}else if(trovato==false){  //GESTIONE MESI DI 30 GIORNI
                        if(*m==Aprile || *m==Giugno || *m==Settembre || *m==Novembre){
                            do{
                                printf("INSERIRE GIORNO (DA 1 A 30): FORMATO GG\n");
                                scanf("%d",g);
                            }while(*g<1 || *g>30);
                            trovato=true;
                        }
}
if(trovato==false){
    do{ //GESTIONE MESI 31 GIORNI
    printf("INSERIRE GIORNO (DA 1 A 31): FORMATO GG\n");
    scanf("%d",g);
    }while(*g<1 || *g>31);
}
}else{
        if(*m==Febbraio){
     do{
        printf("INSERIRE GIORNO (DA 1 A 28): FORMATO GG\n");
        scanf("%d",g);
        }while(*g<1 || *g>29);
        trovato=true;
}else if(trovato==false){
                        if(*m==Aprile || *m==Giugno || *m==Settembre || *m==Novembre){
                            do{
                                printf("INSERIRE GIORNO (DA 1 A 30): FORMATO GG\n");
                                scanf("%d",g);
                            }while(*g<1 || *g>30);
                            trovato=true;
                        }
}
if(trovato==false){
    do{
    printf("INSERIRE GIORNO (DA 1 A 31): FORMATO GG\n");
    scanf("%d",g);
    }while(*g<1 || *g>31);
}
}
do{
    printf("INSERIRE ORA (da 0 a 23)\n");
    scanf("%d",h);
    }while(*h<0 || *h>23);
}
/*FUNZIONE CHE CI PERMETTE DI INSERIRE UN APPUNTAMENTO IN AGENDA IN BASE AL GIORNO E ALL'ORA INSERITI PRECEDENTEMENTE*/
void inserire_appuntamento(Agenda appuntamenti[365][24],int* g,int* h){
    fflush(stdin);
    printf("Inserire appuntamento in Agenda :\n");
    gets(appuntamenti[*g][*h].appuntamenti);
}
/*FUNZIONE CHE CI PERMETTE DI DISDIRE UN APPUNTAMENTO IN BASE AL GIORNO E ALL'ORA SCELTI DALL'UTENTE,PRATICAMENTE CON LA
 STRCPY ANDIAMO A COPIARE NELLA MATRICE DI APPUNTAMENTI AGLI INDICI SCELTI LA STRINGA : "E' STATO ANNULLATO"*/
void disdici_appuntamento(Agenda appuntamenti[365][24],int* g,int* h){
fflush(stdin);
strcpy(appuntamenti[*g][*h].appuntamenti,"E' stato Annullato");
}
//FUNZIONE CHE DATA UN ORA SCELTA DALL'UTENTE ED UN MESE VISUALIZZA TUTTI GLI APPUNTAMENTI FISSATI A QUELL'ORA IN QUEL MESE
void vis_app(Agenda appuntamenti[][24],Mesi* m,int* h){
int giorno_calcolato; //NUMERO DEI GIORNI DEL MESE CHE VOGLIAMO CALCOLARE
int len;
printf("INSERISCI MESE :\n");
scanf("%d",m);
giorno_calcolato=calcolo_mese[*m+1]-calcolo_mese[*m];
printf("INSERISCI ORA:\n");
scanf("%d",h);
    do{
        len=strlen(appuntamenti[giorno_calcolato][*h].appuntamenti);
        if(len!=0){ //SE NELL'AGENDA A QUEL GIORNO E QUELL'ORA SONO PRESENTI APPUNTAMENTI LI ANDIAMO A VISUALIZZARE E DECREMENTIAMO IL GIORNO
        printf("GLI APPUNTAMENTI DEL MESE SONO : %s\n",appuntamenti[giorno_calcolato][*h].appuntamenti);
        }
        giorno_calcolato--;
    }while(giorno_calcolato>=0);
}
