#include "header.h"
#include "functions.c"
int main()
{
    Agenda appuntamenti[365][24];
    int anno;
    bool bisestile;
    Mesi m;
    int g,h;
    int scelta;
    int n,i;
    printf("-------AGENDA ELETTRONICA--------\n");
    anno_bisestile(&anno,&bisestile);
    while(scelta=menu()){
            switch(scelta){
        case 1:/*INSERIMENTO APPUNTAMENTO*/
        printf("Quanti appuntamenti vuoi inserire ?");
        scanf("%d",&n);
        system("CLS");
        for(i=0;i<n;i++){ //inserimento degli appuntamenti
        printf("%d\n",anno);
        ins_mese(&m,&g,&h,&bisestile);
        inserire_appuntamento(appuntamenti,&g,&h);
        printf("L'appuntamento : %s\nE' stato fissato il %d/%d/%d alle Ore: %d.00\n",appuntamenti[g][h].appuntamenti,g,m,anno,h);
        }
        system("PAUSE");
        break;
        case 2: /*DISDICI APPUNTAMENTO*/
        ins_mese(&m,&g,&h,&bisestile);
        printf("L'appuntamento : %s il %d/%d/%d alle Ore: %d.00\n",appuntamenti[g][h].appuntamenti,g,m,anno,h);
        disdici_appuntamento(appuntamenti,&g,&h);
        printf("%s\n",appuntamenti[g][h].appuntamenti);
        system("PAUSE");
        break;
        case 3:/*CERCA APPUNTAMENTI DEL MESE*/
        vis_app(appuntamenti,&m,&h);
        system("PAUSE");
        break;
        case 0:
        return 0;
}
}
}
