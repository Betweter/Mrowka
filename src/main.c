#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "Langton.h"

int main(int argc, char** argv){
	int wiersze = 10;
	int kolumny = 10;
	int l_iteracji = 1000;
	char kierunek_poczatkowy = 'N';
	char* przedrostek_pliku = NULL;
	int czy_losowo = 0;
	double procent_przeszkod;
	char* mapa = NULL;


	int opcja;
	while((opcja = getopt(argc, argv, "m:n:i:d:f:r:u:")) != -1){
		switch(opcja){
			case 'm':
				wiersze = atoi(optarg);
				break;
			case 'n':
				kolumny = atoi(optarg);
				break;
			case 'i':
				l_iteracji = atoi(optarg);
				break;
			case 'd':
				kierunek_poczatkowy = *optarg;
				if(kierunek_poczatkowy != 'N' && kierunek_poczatkowy != 'E' && kierunek_poczatkowy != 'S' && kierunek_poczatkowy != 'W'){
					fprintf(stderr, "Kierunek powinien być literą N/E/W/S\n");
					exit(1);	
				}
				break;
			case 'f':
				przedrostek_pliku = optarg;
				break;
			case 'r':
				if( atof(optarg) > 0 && atof(optarg) < 1){
					czy_losowo = 1;
					procent_przeszkod = atof(optarg);
				} else {
					fprintf(stderr, "Tryb losowy wymaga argumentu pomiędzy 0 a 1\n");
					exit(1);
				}
				break;
			case 'u':
				mapa = optarg;
				break;
			case '?':
				if ((optopt == 'm')||(optopt == 'n')||(optopt == 'l'))
					fprintf(stderr, "Opcja -%c wymaga argumentu.\n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Nieznana opcja '-%c'.\n", optopt);
				else
					fprintf(stderr, "Nieznany znak opcji '\\x%x'.\n", optopt);
				return 1;
			default:
				abort();
		}
	}
	
	fprintf(stderr, "wierszy=%d, kolumn=%d, iteracji=%d, kierunek=%c\n", wiersze, kolumny, l_iteracji, kierunek_poczatkowy);
	if( przedrostek_pliku != NULL)
		fprintf(stderr, "przedrostek_pliku= %s\n", przedrostek_pliku);
	if( czy_losowo != 0)
		fprintf(stderr, "parametr losowania przeszkod = %lf\n", procent_przeszkod);
	if( mapa != 0)
		fprintf(stderr, "nazwa wczytywanej mapy: %s\n", mapa);	
	Langton(wiersze, kolumny, l_iteracji, kierunek_poczatkowy, przedrostek_pliku, czy_losowo, procent_przeszkod, mapa);
return 0;
}

/* DO ZROBIENIA:
 *   komunikaty czy odpowiednie argumenty
 *   rozłączność losowania i wczytywania
 *   wczytywanie (i jakaś testowa załączona)
 *   drukowanie
 *   sprawozdanie
 *   Makefile