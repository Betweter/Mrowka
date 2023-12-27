#include"Langton.h"
#include"druk.h"

int Langton(int wiersze, int kolumny,int  l_iteracji, char kierunek_poczatkowy, char* przedrostek_pliku, int czy_losowo, double procent_przeszkod ){
	int* plansza = calloc(wiersze*kolumny, sizeof(plansza));
	char kierunek = kierunek_poczatkowy;
	int x = wiersze/2;
	int y = kolumny/2;

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

		druk(wiersze, kolumny, x, y, plansza);
	}	

return 0;
}
