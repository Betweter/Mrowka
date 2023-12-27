#include"Langton.h"
#include"druk.h"

void losulosu(int wiersze, int kolumny, int* plansza, double procent_przeszkod){
	;
}

int Langton(int wiersze, int kolumny,int  l_iteracji, char kierunek_poczatkowy, char* przedrostek_pliku, int czy_losowo, double procent_przeszkod, char* mapa ){
	
	int* plansza = mapa == NULL ? calloc(wiersze*kolumny, sizeof(plansza)) : wczytaj(char* mapa);
	char kierunek = kierunek_poczatkowy;
	int x = wiersze/2;
	int y = kolumny/2;

	if(czy_losowo != 0)
		losulosu(int wiersze, int kolumny, int* plansza, double procent_przeszkod);

	for(int i = 0; i<l_iteracji; i++){

		if ( plansza[x*wiersze + y] == 0){
			plansza[x*wiersze + y] = 1;

			switch(kierunek){
				case 'N':
					kierunek = 'E';
					x++;
					break;
				case 'E':
					kierunek = 'S';
					y--;
					break;
				case 'S':
					kierunek = 'W';
					x--;
					break;
				case 'W':
					kierunek = 'N';
					y++;
					break;
			}
		}else{

			plansza[x*wiersze + y] = 0;

			switch(kierunek){
				case 'N':
					kierunek = 'W';
					x--;
					break;
				case 'E':
					kierunek = 'N';
					y++;
					break;
				case 'S':
					kierunek = 'E';
					x++;
					break;
				case 'W':
					kierunek = 'S';
					y--;
					break;
		}

		druk(wiersze, kolumny, x, y, plansza, przedrostek_pliku);
	}	

return 0;
}
