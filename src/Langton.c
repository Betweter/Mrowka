#include"Langton.h"
#include"druk.h"
#include"wczyt.h"

void losulosu(int wiersze, int kolumny, int* plansza, double procent_przeszkod){
	srand(time(NULL));
	
	for(int i = 0; i < wiersze; i++)
		for(int j = 0; j < kolumny; j++)
			plansza[i*wiersze + j] = ( rand() % 100 ) < ( procent_przeszkod * 100 ) ? 1 : 0;
		
}

void biale(int* x, int* y, int* kierunek, int* plansza, int wiersze, int kolumny){
	plansza[ (*x) * wiersze + *y] = 1;
	switch(*kierunek){
		case 0:
			*kierunek = 1;
			if( *x < kolumny )
				(*x)++;
			else
				*x = 0;
			break;
		case 1:
			*kierunek = 2;
			if( *y > 0 )
				(*y)--;
			else
				*y = wiersze;
			break;
		case 2:
			*kierunek = 3;
			if(*x > 0)
				(*x)--;
			else
				*x = kolumny;
			break;
		case 3:
			*kierunek = 0;
			if(*y < wiersze)
				(*y)++;
			else
				*y = 0;
			break;
	}
}

void czarne(int* x, int* y, int* kierunek, int* plansza, int wiersze, int kolumny){
	plansza[ (*x) * wiersze + *y] = 0;
	switch(*kierunek){
		case 0:
			*kierunek = 3;
			if( *x > 0 )
				(*x)--;
			else
				*x = kolumny;
			break;
		case 1:
			*kierunek = 0;
			if( *y < wiersze )
				(*y)++;
			else
				*y = 0;
			break;
		case 2:
			*kierunek = 1;
			if(*x < kolumny)
				(*x)++;
			else
				*x = 0;
			break;
		case 3:
			*kierunek = 2;
			if(*y > 0)
				(*y)--;
			else
				*y = wiersze;
			break;
	}
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

	druk(wiersze, kolumny, x, y, plansza, przedrostek_pliku, 0);
	
	for(int i = 0; i<l_iteracji; i++){

		if ( plansza[x*wiersze + y] == 0)
			biale(&x, &y, &kierunek, plansza, wiersze, kolumny);
		else
			czarne(&x, &y, &kierunek, plansza, wiersze, kolumny);
			
		druk(wiersze, kolumny, x, y, plansza, przedrostek_pliku, i);
	}	

return 0;
}
