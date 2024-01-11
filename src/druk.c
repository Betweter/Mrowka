#include"druk.h"

void pole(int wiersze, int kolumny, int x, int y, int kierunek, int* plansza, int i, int j, FILE *out){
	if( j == y && i == x){
		if(plansza[j*wiersze + i] == 1){
			switch(kierunek){
				case 0:
					fprintf(out, "mrówka BN");
					break; 
				case 1:
					fprintf(out, "mrówka BE");
					break; 
				case 2:
					fprintf(out, "mrówka BS");
					break; 
				case 3:
					fprintf(out, "mrówka BW");
					break;
			}
		}
		else{
			switch(kierunek){
				case 0:
					fprintf(out, "mrówka WN");
					break; 
				case 1:
					fprintf(out, "mrówka WE");
					break; 
				case 2:
					fprintf(out, "mrówka WS");
					break; 
				case 3:
					fprintf(out, "mrówka WW");
					break;
			}
		}
	}
	else{
		if(plansza[j*wiersze + i] == 1){
			fprintf(out, "B");
		}
		else{
			fprintf(out, "W");
		}
	}
}

void mapa(int wiersze, int kolumny, int x, int y, int kierunek, int* plansza, FILE *out){
	int i = 0;
	int j = 0;
	
	for(j = 0; j <= wiersze; j++){
		for(i = 0; i <= kolumny; i++){
			fprintf(out, "LG");
			fprintf(out, "hor");
			fprintf(out, "PG");
		}
		fprintf(out, "\n");
		for(i = 0; i <= kolumny; i++){
			fprintf(out, "ver");
			pole(wiersze, kolumny, x, y, kierunek, plansza, i, j, out);
			fprintf(out, "ver");
		}
		fprintf(out, "\n");
		for(i = 0; i <= kolumny; i++){
			fprintf(out, "LD");
			fprintf(out, "hor");
			fprintf(out, "PD");
		}
		fprintf(out, "\n");
	}
}

void druk(int wiersze, int kolumny, int x, int y, int kierunek, int* plansza, char* przedrostek_pliku, int i){
	//fprintf(stderr, "i= %d. x=%d, y= %d\n", i+1, x, y);
	//char nowy_plik[100];  
    	//snprintf(nowy_plik, sizeof(nowy_plik), "%s-%d", przedrostek_pliku, i);

	//FILE *out = przedrostek_pliku =! NULL ? fopen( nowy_plik, "w" ) : stdout;
	FILE *out = stdout;
	mapa(wiersze, kolumny, x, y, kierunek, plansza, out);
}
