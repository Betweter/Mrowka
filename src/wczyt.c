#include "wczyt.h"

int* wczytaj(char* mapa, int* wiersze, int* kolumny, char* kierunek_poczatkowy, int* x, int* y){
	FILE *in = fopen(mapa, "r");

	//liczenie znaków w pierwszej linii i na podstawie tego określenie wartości "kolumny"
	//liczenie linii pliku i na podstawie tego określenie wartości "wiersze"
	//rewind
	int* mapa1 = malloc( wiersze * kolumny * sizeof(int));//fjashjfgvoasfhgjio	
	//sprawdzanie jakiego koloru jest dana komórka (trzeba omijać rogi i pipe'y
	//jeśli nie jest kwadratem to jest mrówką, switch jaką i z tego rzeczy


return mapa1;
}
