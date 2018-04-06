void movimiento_Bola() {
  146 
  147     //                Movimiento de la bola
  148     //   gotoxy(xbola,ybola); printf("   ");
  149     gotoxy(xbola,ybola); printf("(_)");
  150 
  151     xbola = xbola + ( xvel * xdireccion );
  152     ybola = ybola + ( yvel * ydireccion );
  153 
  154 
  155     if ( ((xbola == xpala)||(xbola+1 == xpala)||(xbola+2 == xpala)) && ((ybola == ypala)||(ybola == ypala+1)||(ybola == ypala+2)||(ybola == ypala+3)||(ybola == ypala+4)) ){
  156         xdireccion *= -1;
  157         ydireccion *= -1;
  158     }
  159     if ( ((xbola == xpala1)||(xbola+1 == xpala1)||(xbola+2 == xpala1)) && ((ybola == ypala1)||(ybola == ypala1+1)||(ybola == ypala1+2)||(ybola == ypala1+3)||(ybola == ypala1+3)) ){
  160         xdireccion *= -1;
  161         ydireccion *= -1;
  162     }
  163 
  164    if((xbola<=5)|| (xbola>=99))
  165         xdireccion *= -1;
  166     if((ybola<=3) || (ybola>=29))
  167         ydireccion *= -1;
  168 
  169 
  170 
  171     gotoxy(55,8);printf("%d , %d", xbola,ybola);            // situacion de la bola
  172     gotoxy(55,10);printf("%c", flecha);            // situacion de la bola
  173 }
