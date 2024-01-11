#include"druk.h"

// SQUARE_WHITE: 
// SQUARE_BLACK:█
// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀
void pole(int wiersze, int kolumny, int x, int y, int kierunek, int* plansza, int k, int j, FILE *out){
	if( j == y && k == x){
		if(plansza[j*kolumny + k] == 1){
			switch(kierunek){
				case 0:
					fprintf(out, "▲");
					break; 
				case 1:
					fprintf(out, "▶");
					break; 
				case 2:
					fprintf(out, "▼");
					break; 
				case 3:
					fprintf(out, "◀");
					break;
			}
		}
		else{
			switch(kierunek){
				case 0:
					fprintf(out, "△");
					break; 
				case 1:
					fprintf(out, "▷");
					break; 
				case 2:
					fprintf(out, "▽");
					break; 
				case 3:
					fprintf(out, "◁");
					break;
			}
		}
	}
	else{
		if(plansza[j*kolumny + k] == 1){
			fprintf(out, "█");
		}
		else{
			fprintf(out, " ");
		}
	}
}

void mapa(int wiersze, int kolumny, int x, int y, int kierunek, int* plansza, FILE *out){
	int k = 0;
	int j = 0;
	// LINE_VERTICAL:│
	// LINE_HORIZONTAL:─
	// LINE_DOWN_RIGHT:┌
	// LINE_DOWN_LEFT:┐
	// LINE_UP_RIGHT:└
	// LINE_UP_LEFT:┘
	for(j = 0; j < wiersze; j++){
		for(k = 0; k < kolumny; k++){
			fprintf(out, "┌");
			fprintf(out, "─");
			fprintf(out, "┐");
		}
		fprintf(out, "\n");
		for(k = 0; k < kolumny; k++){
			fprintf(out, "│");
			pole(wiersze, kolumny, x, y, kierunek, plansza, k, j, out);
			fprintf(out, "│");
		}
		fprintf(out, "\n");
		for(k = 0; k < kolumny; k++){
			fprintf(out, "└");
			fprintf(out, "─");
			fprintf(out, "┘");
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
}

void druk(int wiersze, int kolumny, int x, int y, int kierunek, int* plansza, char* przedrostek_pliku, int i){
	
	FILE *out;
	if (przedrostek_pliku != NULL) {
        	char plik[100];
        	sprintf(plik, "%s_%d.txt", przedrostek_pliku, i+1);
        
        	out = fopen(plik, "w");

        	if (out == NULL) {
            		fprintf(stderr, "Error opening file %s\n", plik);
            		exit(EXIT_FAILURE);
        	}
    	} 
    	else {
        	out = stdout;
    	}
    	
	mapa(wiersze, kolumny, x, y, kierunek, plansza, out);
	
	if (przedrostek_pliku != NULL) {
        	fclose(out);
    	}
	fprintf(out, "iteracja %d\n", i+1);
}
