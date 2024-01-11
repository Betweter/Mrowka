#include "wczyt.h"

int* wczytaj(char* mapa, int* wiersze, int* kolumny, char* kierunek_poczatkowy, int* x, int* y){
	FILE *in = fopen(mapa, "r");

	//liczenie znaków w pierwszej linii i na podstawie tego określenie wartości "kolumny"
	char bufor[1024];
	if(fgets(bufor, sizeof(bufor), in) != NULL){
		*kolumny = 0;
		while (bufor[*kolumny] != '\0' && bufor[*kolumny] != '\n')
			(*kolumny)++;
		*kolumny /= 9;
	}
	fprintf(stderr,"kolumny = %d\n", *kolumny);
	
	rewind(in);
	//liczenie linii pliku i na podstawie tego określenie wartości "wiersze"
	*wiersze = 0;
	while(fgets(bufor, sizeof(bufor), in) != NULL)
		(*wiersze)++;
	*wiersze = (*wiersze - 2)/3;
	fprintf(stderr,"wiersze = %d\n", *wiersze);
	rewind(in);
	
	int* mapa1 = malloc( *wiersze * *kolumny * sizeof(int));	
	//sprawdzanie jakiego koloru jest dana komórka (trzeba omijać rogi i pipe'y
	//jeśli nie jest kwadratem to jest mrówką, switch jaką i z tego rzeczy

	fclose(in);
	return mapa1;
}
