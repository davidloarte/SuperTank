
#include <stdlib.h>
#include <stdio.h>

#define N 18
#define M 32 

char tmp_map[N][M];
char map[N][M] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|## ########### ##   #########|",
	"|   |                         |",
	"| | |### |  |           |     |",
	"| |      |  | |###  |   |  |  |",
	"| | #####|  | |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"+#############################+"
	};

void Map(){
	for(int i = 0; i < 18; i++) {			
		printf("%s\n",map[i] );
	}
}
 void limites( int x, int y ){
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '#';
	}
}
	

int main(){

Map();

	return EXIT_SUCCESS;
}
