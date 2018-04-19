#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for mygetch
#include <unistd.h>
#include <ncurses.h>

//For UTF-8
#include <locale.h>

#define fila  27
#define columna 42

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)
#define xInicio 10
#define yInicio 10

#define N 50
#define M 50
#define MAX_BULLETS 100

char tmp_map[fila][columna];
char map[fila][columna] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};
int arrow;
int checkRIGHT = 0;
int checkLEFT = 0;
int checkUP = 0;
int checkDOWN = 0;
int lastKey = 0;
//Bloques

struct BlockUnbreakable {
    int x;
    int y;
};

struct Block {
    int x;
    int y;
};
//Tank
struct Tanks {
    double x = 0;
    double y = 0;
};

struct Bullets {
    double posx;
    double posy;
    double dir ;

};


//Funciones de Curses
void iniciar_Curses();
void finalizar_Curses();

//Funciones del juego
void Map();
int teclas(struct Tanks *move, struct Bullets *moveBullet);
void tank1(int y, int x, struct Bullets *pos);

int row,col;
struct Bullets *bullet[MAX_BULLETS] = {NULL};
void printbullet(struct Bullets *shot, struct Tanks *warCar);

int main() {
    struct BlockUnbreakable blockU[N];
    struct Block block[M];
    struct Tanks tank;


    setlocale(LC_ALL,"");
    iniciar_Curses();


    getmaxyx(stdscr,row,col);

    while(teclas(&tank,bullet[MAX_BULLETS]) != KEY_BREAK){
        clear();
        Map();
        tank1( (int) tank.x, (int) tank.y, bullet[MAX_BULLETS]);
        teclas(&tank,bullet[MAX_BULLETS]);
    //    printbullet(bullet[MAX_BULLETS],&tank);

        usleep(20000);

    }
    finalizar_Curses();
    return 0;
}

void iniciar_Curses(){
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);

}

void finalizar_Curses(){
    curs_set(1);
    endwin();
}

int teclas(struct Tanks *move, struct Bullets *moveBullet){

    arrow = getch();
    if(arrow != -1)
        lastKey = arrow;

    //    check_collision();
    mvprintw(row-5,0,"arrow es %i, y lastkey es %i", arrow, lastKey);
    mvprintw(row-6,0,"ccheckRIGHT: %i, checkDOWN: %i, checkLEFT: %i, checkU: %i", checkRIGHT, checkDOWN, checkLEFT, checkUP);
    switch(arrow){

        case KEY_UP:
            if(checkUP != 0){
                (*move).y += 1;
                if((*move).y > ((minf-1) + yInicio ))//Up limit 9
                    (*move).y -= 1;

                checkRIGHT = 0;
                checkDOWN  = 0;
                checkLEFT  = 0;
            }
            checkUP += 1;
            if(checkUP > 1)
                checkUP -= 1;
            break;

        case KEY_LEFT:
          if(checkLEFT != 0){
                (*move).x += 1;
                if((*move).x > ((minc-1) + xInicio ))//Left limit 9
                    (*move).x -= 1;
                checkRIGHT = 0;
                checkDOWN  = 0;
                checkUP    = 0;
            }

            checkLEFT += 1;
            if(checkLEFT > 1)
                checkLEFT -= 1;
            break;

        case KEY_DOWN:
            if(checkDOWN != 0){
                (*move).y -= 1;
                if( (*move).y < ((yInicio)+ ( (-maxf)+1 )) )// Down limit -15
                    (*move).y += 1;
                checkRIGHT = 0;
                checkLEFT  = 0;
                checkUP    = 0;
            }

            checkDOWN -= 1;
            if(checkDOWN < -1)
                checkDOWN += 1;
            break;

        case KEY_RIGHT:
            if(checkRIGHT != 0){
                (*move).x -= 1;
                if( (*move).x < ((xInicio)+ ( (-maxc)+1 )) )// Right limit -30
                    (*move).x += 1;
                checkDOWN  = 0;
                checkLEFT  = 0;
                checkUP    = 0;
            }
            checkRIGHT -= 1;
            if(checkRIGHT < -1)
                checkRIGHT += 1;
            break;
        case 'b':

            takeTankxy();

            int direction = 0;
            int found = -1;
            if(checkRIGHT = -1)
                mvprintw((*move).y-1,(*move).x, "*");

            if(checkLEFT = 1)
                mvprintw((*move).y+1,(*move).x, "*");

            if(checkUP = 1)
                mvprintw((*move).y-1,(*move).x, "*");

            if(checkDOWN = -1)
                mvprintw((*move).y+1,(*move).x, "*");


            for(int i = 0; i < MAX_BULLETS; i++)
            {
                if(bullet[i] == NULL)
                {
                    found = i;
                    break;
                }
            }

            if(found >= 0)
            {
                int i = found;
                bullet[i] = (Bullets*) malloc(sizeof(Bullets));
                bullet[i]->posx = (*move).x;
                bullet[i]->posy = (*move).y;
                bullet[i]->dir = direction;
            }           //updateBullet((*moveBullet).y,(*moveBullet).x);


            break;
    }
    refresh();
    return arrow;
}

void tank1(int x, int y, struct Bullets *pos) {
    int algo;

    algo=mvprintw(yInicio - y, xInicio - x,"H");
    if(ERR == algo){
        mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
        mvprintw(row-1,0,"errah, %i,%i no es una direccio valida\n", yInicio - y, xInicio - x);
        /*
           fprintf(stderr, "errah, %i,%i no es una direccio valida\n", yInicio - y, xInicio - x);
           if((xInicio - x)<0)
           tank1(x+1, y);
           if((yInicio - y)<0)
           tank1(x, y+1);*/
    }
    mvprintw(row-1,0,"tank 1 está en, %i,%i", yInicio - y, xInicio - x);
    mvprintw(row-2,0,"tank 1 está en, %i,%i", y, x);
//    mvprintw(row-3,0,"bala está en, %i,%i", pos.posy, pos.posx);

    refresh();
}
void addBullet(double x, double y, double direction){

    int found = -1;
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        if(bullet[i] == NULL)
        {
            found = i;
            break;
        }
    }

    if(found >= 0)
    {
        int i = found;
        bullet[i] = (Bullets*) malloc(sizeof(Bullets));
        bullet[i]->posx = x;
        bullet[i]->posy = y;
        bullet[i]->dir = direction;
    }
}

void removeBullet(int i){
    if(bullet[i])
    {
        free(bullet[i]);
        bullet[i] = NULL;
    }
}
/*void updateBullet(struct Tanks *warCar){
    addBullet(&warCar);

}*/
void updateBullet(struct Bullets *shot, struct Tanks *warCar){


               mvprintw(shot->posy,shot->posx,"hey");
                refresh();



/*            if(checkUP)
                (*shot).dir += 1;
            if(checkDOWN)
                (*shot).dir -= 1;
            if(checkLEFT)
                (*shot).dir += 1;
            if(checkRIGHT)
                (*shot).dir -= 1;*/
            //            (*shot).y += 1;
//                if((*shot).y > ((minf-1) + yInicio ))//Up limit 9
//                    (*shot).y -= 1;




}

void Map(){
    for(int f = 0; f < fila; f++) {
        for (int c=0; c< columna; c++ ){

            if(map[f][c]==0)
                printw(" ");
            if(map[f][c]==1)
                printw("#");
            if(map[f][c]==2){
//                const wchar_t* block = L"\u2588"; // caracter utf-8
//                addwstr(block);    //necesitas ncursesw para caracteres largos tipo unicode
                printw("X");
            }
        }
        printw("\n");
    }
    refresh();
}

double takeTankxy(struct tank *dir){


    return tank->x;
}
