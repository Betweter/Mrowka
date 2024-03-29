#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Langton.h"

int czyLiczba (char* wyr){

	if( wyr == NULL || *wyr == '\0')
		return 0;

	while (*wyr) {
		if (*wyr < '0' || *wyr > '9')
			return 0;
		wyr++;
	}
	return 1;
}

int main(int argc, char** argv){
	int wiersze = 6;
	int kolumny = 6;
	int l_iteracji = 10;
	char kierunek_poczatkowy = 'N';
	char* przedrostek_pliku = NULL;
	int czy_losowo = 0;
	double procent_przeszkod;
	char* mapa = NULL;

	int licznik_trybow = 0;
	int opcja;
	while((opcja = getopt(argc, argv, "m:n:i:d:f:r:u:")) != -1){
		switch(opcja){
			case 'm':
				if( czyLiczba(optarg) )
					wiersze = atoi(optarg);
				else {
					fprintf(stderr,"Argument -m powinien być całkowitą liczbą dodatnią\n");
					exit(1);
				}
				break;
			case 'n':
				if( czyLiczba(optarg) )
					kolumny = atoi(optarg);
				else {
					fprintf(stderr,"Argument -n powinien być całkowitą liczbą dodatnią\n");
					exit(1);
				}
				break;
			case 'i':
				if( czyLiczba(optarg) )
					l_iteracji = atoi(optarg);
				else {
					fprintf(stderr,"Argument -i powinien być całkowitą liczbą dodatnią\n");
					exit(1);
				}
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
				if( atof(optarg) > 0 && atof(optarg) < 1 && licznik_trybow == 0){
					czy_losowo = 1;
					procent_przeszkod = atof(optarg);
					licznik_trybow++;
				} else {
					fprintf(stderr, "Tryb losowy wymaga argumentu pomiędzy 0 a 1 oraz nie może być aktywowany jednocześnie z opcją wczytania mapy.\n");
					exit(1);
				}
				break;
			case 'u':
				if(licznik_trybow == 0)
					mapa = optarg;
				else
					fprintf(stderr, "Tryb wczytania mapy nie może być aktywowany jednocześnie z opcją losowej planszy.\n");
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
	
	//fprintf(stderr, "wierszy=%d, kolumn=%d, iteracji=%d, kierunek=%c\n", wiersze, kolumny, l_iteracji, kierunek_poczatkowy);
	if( przedrostek_pliku != NULL){
		mkdir( przedrostek_pliku, 0777);
		fprintf(stderr, "przedrostek_pliku= %s\n", przedrostek_pliku);
	}
	if( czy_losowo != 0)
		fprintf(stderr, "parametr losowania przeszkod = %lf\n", procent_przeszkod);
	if( mapa != 0)
		fprintf(stderr, "nazwa wczytywanej mapy: %s\n", mapa);	
	
	Langton(wiersze, kolumny, l_iteracji, kierunek_poczatkowy, przedrostek_pliku, czy_losowo, procent_przeszkod, mapa);

return 0;
}

/* DO ZROBIENIA:
 *   drukowanie
 *   wczytywanie (i jakaś testowa załączona)
 *   Makefile
 *   sprawozdanie
 */
