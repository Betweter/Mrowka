#include"Langton.h"
#include"druk.h"
#include"wczyt.h"

void losulosu(int wiersze, int kolumny, int* plansza, double procent_przeszkod){
	srand(time(NULL));
	
	for(int i = 0; i < wiersze; i++)
		for(int j = 0; j < kolumny; j++)
			plansza[i*kolumny + j] = ( rand() % 100 ) < ( procent_przeszkod * 100 ) ? 1 : 0;
		
}

int biale(int* x, int* y, int* kierunek, int* plansza, int wiersze, int kolumny){
	plansza[ (*y) * kolumny + *x] = 1;
	switch(*kierunek){
		case 0:
			*kierunek = 1;
			if( *x < kolumny - 1 )
				(*x)++;
			else
				return 1;
			break;
		case 1:
			*kierunek = 2;
			if( *y < wiersze - 1 )
				(*y)++;
			else
				return 1;
			break;
		case 2:
			*kierunek = 3;
			if(*x > 0)
				(*x)--;
			else
				return 1;
			break;
		case 3:
			*kierunek = 0;
			if(*y > 0)
				(*y)--;
			else
				return 1;
			break;
	}
	return 0;
}

int czarne(int* x, int* y, int* kierunek, int* plansza, int wiersze, int kolumny){
	plansza[ (*y) * kolumny + *x] = 0;
	switch(*kierunek){
		case 0:
			*kierunek = 3;
			if( *x > 0 )
				(*x)--;
			else
				return 1;
			break;
		case 1:
			*kierunek = 0;
			if( *y > 0 )
				(*y)--;
			else
				return 1;
			break;
		case 2:
			*kierunek = 1;
			if(*x < kolumny - 1 )
				(*x)++;
			else
				return 1;
			break;
		case 3:
			*kierunek = 2;
			if(*y < wiersze - 1 )
				(*y)++;
			else
				return 1;
			break;
	}
	return 0;
}

int kier_zmian(char kierunek_poczatkowy){
	char k = kierunek_poczatkowy;
	return k == 'N' ? 0 : k == 'E' ? 1 : k == 'S' ? 2: 3;
}

int Langton(int wiersze, int kolumny,int  l_iteracji, char kierunek_poczatkowy, char* przedrostek_pliku, int czy_losowo, double procent_przeszkod, char* mapa ){
	
	int x = wiersze/2;
	int y = kolumny/2;

	int* plansza = mapa == NULL ? calloc(wiersze*kolumny, sizeof(plansza)) : wczytaj(mapa, &wiersze, &kolumny, &kierunek_poczatkowy, &x, &y);
	int kierunek = kier_zmian(kierunek_poczatkowy);

	if(czy_losowo != 0)
		losulosu(wiersze, kolumny, plansza, procent_przeszkod);

	
	druk(wiersze, kolumny, x, y, kierunek, plansza, przedrostek_pliku, 0);
	for(int i = 0; i<l_iteracji; i++){

		if ( plansza[y*kolumny + x] == 0){
			if ( biale(&x, &y, &kierunek, plansza, wiersze, kolumny) == 1){
				fprintf(stderr, "Mrówka weszła w ścianę :(\n");
				return 1;
			}
		} else {
			if ( czarne(&x, &y, &kierunek, plansza, wiersze, kolumny) == 1){
				fprintf(stderr, "Mrówka weszła w ścianę :(\n");
				return 1;
			}
		}
		druk(wiersze, kolumny, x, y, kierunek, plansza, przedrostek_pliku, i);
	}	

return 0;
}
