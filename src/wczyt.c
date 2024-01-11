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
	
	/*long int a = 0;//to będzie aktualna komórka
	
	for(int i = 0; i<(*wiersze); i++){
	
		fgets(bufor, sizeof(bufor), in);
		fgets(bufor, sizeof(bufor), in);
		for (int j = 0; bufor[j] != '\0' && bufor[j] != '\n'; j++){
			if (bufor[j] != '│') {
				if (bufor[j] == '█') {
				    mapa1[a] = 1;
				} else if (bufor[j] == ' ') {
				    mapa1[a] = 0;
				} else {
				    if (bufor[j] == '▲') {
					*kierunek_poczatkowy = 'N';
					mapa1[a] = 1;
				    } else if (bufor[j] == '▶') {
					*kierunek_poczatkowy = 'E';
					mapa1[a] = 1;
				    } else if (bufor[j] == '▼') {
					*kierunek_poczatkowy = 'S';
					mapa1[a] = 1;
				    } else if (bufor[j] == '◀') {
					*kierunek_poczatkowy = 'W';
					mapa1[a] = 1;
				    } else if (bufor[j] == '△') {
					*kierunek_poczatkowy = 'N';
					mapa1[a] = 0;
				    } else if (bufor[j] == '▷') {
					*kierunek_poczatkowy = 'E';
					mapa1[a] = 0;
				    } else if (bufor[j] == '▽') {
					*kierunek_poczatkowy = 'S';
					mapa1[a] = 0;
				    } else if (bufor[j] == '◁') {
					*kierunek_poczatkowy = 'W';
					mapa1[a] = 0;
				    }
				    *x = a - i * (*kolumny);
				    *y = i;
				}
				a++;
		    	}
		}
	}*/

	fclose(in);
	return mapa1;
}
