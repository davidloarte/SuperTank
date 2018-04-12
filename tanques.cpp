#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
//for mygetch
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include <time.h>

//#include <curses.h>

#define fila  45
#define columna 200

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

char matriz[fila][columna];

int xbola = 50;
int ybola = 15;
int x = 5;
int y = 5;
char tecla;
char flecha;

char loquefalta;

//////bola

double xvel = 1;
double yvel = 1;

int xdireccion = 1;
int ydireccion = 1;


/////Palas

int xpala = 20;
int ypala = 10;

int xpala1 = 80;
int ypala1 = 10;




/*

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}




void gotoxy(int x, int y){
    int MAX_SCREEN_AREA = 100;
    char essq[MAX_SCREEN_AREA]={0}; // String variable to hold the escape sequence
    sprintf(essq, "\033[%d;%df", y,x); //\033 = ESC, [X;X valores fila, columna, "f" para indicar que es localizacion espacial
    printf("%s", essq); //imprime la linea de texto en esa localizacion
}

int mygetch( ) {
    struct termios oldt,
                   newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
/*
   void movimiento_bola(){
   gotoxy(xbola,ybola); printf("(_)");
//gotoxy(xbola,ybola); printf(" ");
ybola++;
if(ybola > maxf){
xbola = rand() % 50 +4;
ybola = 4;
}

}*/
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
/*
void pintar_pala1();
void pintar_pala2();

void movimiento_Bola() {

    //                Movimiento de la bola
    //   gotoxy(xbola,ybola); printf("   ");
    gotoxy(xbola,ybola); printf("(_)");

    xbola = xbola + ( xvel * xdireccion );
    ybola = ybola + ( yvel * ydireccion );
•
⦿

    if ( ((xbola == xpala)||(xbola+1 == xpala)||(xbola+2 == xpala)) && ((ybola == ypala)||(ybola == ypala+1)||(ybola == ypala+2)||(ybola == ypala+3)||(ybola == ypala+4)) ){
        xdireccion *= -1;
        ydireccion *= -1;
    }
    if ( ((xbola == xpala1)||(xbola+1 == xpala1)||(xbola+2 == xpala1)) && ((ybola == ypala1)||(ybola == ypala1+1)||(ybola == ypala1+2)||(ybola == ypala1+3)||(ybola == ypala1+3)) ){
        xdireccion *= -1;
        ydireccion *= -1;
    }

   if((xbola<=5)|| (xbola>=99))
        xdireccion *= -1;
    if((ybola<=3) || (ybola>=29))
        ydireccion *= -1;



    gotoxy(55,8);printf("%d , %d", xbola,ybola);            // situacion de la bola
    gotoxy(55,10);printf("%c", flecha);            // situacion de la bola
}
void teclas(){

//        curs_set(0);
    if( (mygetch() == '\033')) {

        mygetch();// == '[';
        flecha=mygetch();
        if(flecha=='A' && ypala1>=minf+3)
            ypala1--;
        if(flecha=='B' && ypala1+4<=maxf-1)
            ypala1++;
        __fpurge(stdin);
    }
    else{
        if (kbhit()){
            flecha=mygetch();

            if(flecha=='w' && ypala>=minf+3)
                ypala--;
            if(flecha=='s' && ypala+4<=maxf-1)
                ypala++;

            __fpurge(stdin);

        }
    }    //close(STDIN_FILENO);

    //    else
    //       ungetc('[',stdin);

    /*    flecha=mygetch();                //'\033' podria incluirlo en el nombre de 'w'

          if(flecha=='w' && ypala>=minf+3)
          ypala--;
          if(flecha=='s' && ypala+3<=maxf-1)
          ypala++;
          __fpurge(stdin);*/

/*

}
void pala1() {
    gotoxy(60,10);printf("%c",tecla);
    if (kbhit()){
        //      int limite;

        /*        gotoxy(55,5);printf("%d , %d", xpala,ypala);

                  gotoxy(xpala,ypala);
                  printf(" ");
                  gotoxy(xpala,ypala+1);
                  printf(" ");
                  gotoxy(xpala,ypala+2);
                  printf(" ");
                  gotoxy(xpala,ypala+3);
                  printf(" ");*

        gotoxy(xpala,ypala);
        printf("█");
        gotoxy(xpala,ypala+1);
        printf("█");
        gotoxy(xpala,ypala+2);
        printf("█");
        gotoxy(xpala,ypala+3);
        printf("█");
        gotoxy(xpala,ypala+4);
        printf("█");

        teclas();
    }

}

void pala2() {
    if (kbhit()){
        gotoxy(xpala1,ypala1);
        printf("█");
        gotoxy(xpala1,ypala1+1);
        printf("█");
        gotoxy(xpala1,ypala1+2);
        printf("█");
        gotoxy(xpala1,ypala1+3);
        printf("█");

        gotoxy(xpala1,ypala1+4);
        printf("█");
        /*    gotoxy(xpala1,ypala1);
              printf(" ");
              gotoxy(xpala1,ypala1+1);
              printf(" ");
              gotoxy(xpala1,ypala1+2);
              printf(" ");
              gotoxy(xpala1,ypala1+3);
              printf(" ");*

        teclas();
    }
}*/
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
        //        __fpurge(stdin);
//        curs_set(0);
          dibujar_Marco();
//        movimiento_Bola();
//        pintar_pala1();
//        pintar_pala2();
        //        if(kbhit()){

//        pala1();
//        pala2();
        //      }

        usleep(60000);
    }
    return 0;
}

//        gotoxy(55,5);printf("%d , %d", x,y);                    // situacion de ||

//movimiento de ||
/*        gotoxy(x,y);
          printf("||");

          tecla=mygetch();

//tecla isquierda derecha minc=0 maxc=columna-1
if(tecla=='a' && x>=minc+4)
x--;
if(tecla=='d' && x<=maxc-1)
x++;
//teclas arriba abajo
if(tecla=='w' && y>=minf+3)
y--;
if(tecla=='s' && y<=maxf-1)
y++;
*/


/*
void pintar_pala1(){
    gotoxy(55,5);printf("%d , %d", xpala,ypala);

    /*    gotoxy(xpala,ypala);
          printf(" ");
          gotoxy(xpala,ypala+1);
          printf(" ");
          gotoxy(xpala,ypala+2);
          printf(" ");
          gotoxy(xpala,ypala+3);
          printf(" ");

    gotoxy(xpala,ypala);
    printf("█");
    gotoxy(xpala,ypala+1);
    printf("█");
    gotoxy(xpala,ypala+2);
    printf("█");
    gotoxy(xpala,ypala+3);
    printf("█");
    gotoxy(xpala,ypala+4);
    printf("█");
}
void pintar_pala2(){
    gotoxy(55,6);printf("%d , %d", xpala1,ypala1);

    /*    gotoxy(xpala,ypala);
          printf(" ");
          gotoxy(xpala,ypala+1);
          printf(" ");
          gotoxy(xpala,ypala+2);
          printf(" ");
          gotoxy(xpala,ypala+3);
          printf(" ");*

    gotoxy(xpala1,ypala1);
    printf("█");
    gotoxy(xpala1,ypala1+1);
    printf("█");
    gotoxy(xpala1,ypala1+2);
    printf("█");
    gotoxy(xpala1,ypala1+3);
    printf("█");
    gotoxy(xpala1,ypala1+4);
    printf("█");
*/


