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


void gotoxy(int x, int y){
    int MAX_SCREEN_AREA = 100;
    char essq[MAX_SCREEN_AREA]={0};
    sprintf(essq, "\033[%d;%df", y,x);
        printf("%s", essq);
}
}

char matriz[fila][columna];

void pintar_limites(){
  for(int x = 2; x<78; x++){
        gotoxy(int x,3); printf("%c",205);
        gotoxy(int y,23);printf("%c", 205);
  }

}

void dibujar_Marco(){

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

 }

int main() {
     /*TODO pasar todo a double y comprobar que funcione bien*/


     pintar_limites();
     dibujar_Marco();
     char matriz[fila][columna];

     for(int i=0;i<fila;i++) {
         for(int j=0;j<columna;j++) {
             matriz[i][j] = 'x';
         }
    }


     while(1){
         system("clear");
        usleep(60000);
     }
     return 0;
}
