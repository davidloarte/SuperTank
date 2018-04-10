#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define fila  45
#define columna 200

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

char matriz[fila][columna];



void dibujar_marco(){

     /*Dibujar marco*/


    for(int f=0; f<fila;f++) {
         for(int c=0;c<columna;c++) {
             if(((f) == minf) || ((f) == maxf)){
                 if( ((f==minf)&&(c==minc)) || ((f==minf)&&(c==maxc)) || ((f==maxf)&&(c==minc)) || ((f==maxf)&&(c==maxc)) )
                     printf("%c█", matriz[f][c] );
                else printf("█");
             }
             else
                if(((f) >= (minf)/*2*/) || ((f) <= (maxf)/*8*/)) {
                     if( (c<(minc+1)) ||(c>(maxc-1)) )
                         printf("█%c",matriz[f][c]);
                     else
                         printf(" ");
                }


         }
         printf("\n");
    }

void dibujar_mapa(){
    /*Dibuja el mapa dentro del marco*/

    for(int f=1; f<fila-1;f++){
        for(int c=1; c<columna-1;C++){

        }
    }
}



 
 }

int main() {
     /*TODO pasar todo a double y comprobar que funcione bien*/


     char matriz[fila][columna];

     for(int i=0;i<fila;i++) {
         for(int j=0;j<columna;j++) {
             matriz[i][j] = 'x';
         }
    }


     while(1){
         system("clear");
           dibujar_marco();
        usleep(60000);
     }
     return 0;
}
