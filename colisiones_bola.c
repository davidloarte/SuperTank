void movimiento_bala() {
  
      //                Movimiento de la bola
      //   gotoxy(xbola,ybola); printf("   ");
      gotoxy(bala.x,ybola); printf("⦿");
//  • bala normal por si queremos usar la otra bala para algo
      xbola = bala.x + ( xvel * 1 );
      ybola = bala.y + ( yvel * 1 );
  
  
      if ( ((bala.x == tank.x)||(bala.x+1 == tank.x)||(bala.x+2 == tank.x)) && ((bala.y == pala.y)||(bala.y ==pala.y+1)||(bala.y ==pala.y+2)||(bala.y ==pala.y+3)||(bala.y ==pala.y+4)) ){
         
      }
      /*if ( ((bala.x == xpala1)||(bala.x+1 == xpala1)||(bala.x+2 == xpala1)) && ((bala.y == ypala1)||(bala.y == ypala1+1)||(bala.y == ypala1+2)||(bala.y == ypala1+3)||(bala.y == ypala1+3)) ){
          xdireccion *= -1;
          ydireccion *= -1;
2     }*/
  
     if((bala.x<=5)|| (bala.x>=99))
          xdireccion *= -1;
      if((bala.y<=3) || (bala.y>=29))
          ydireccion *= -1;
  
  
  
      gotoxy(55,8);printf("%d , %d", bala.x,bala.y);            // situacion de la bala
      gotoxy(55,10);printf("%c", flecha);            // situacion de la bala
  }
