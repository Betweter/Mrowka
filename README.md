Program jest przeznaczony do użytkowanie w systemach operacyjnych z rodziny UNIX w terminalu/jego emulatorze. 
 
Z poziomu folderu ”Mrowka” widoczne są: 
- folder ”bin”, do którego kompilowany jest program, 
- folder ”src”, w którym znajdują się pliki źródłowe programu, 
- plik ”Makefile” pozwalający na szybką kompilację programu komendą ”make”. 
 
Po kompilacji (komendą ”make” program można wywołać z domyślnymi parametrami komendą ”bin/mrowka”. Program korzysta z funkcji getopt, zatem obsługuje flagi wywołania. Poniżej rozpisano wyjaśnienie flag: 
-m ustawia liczbę wierszy planszy (argument powinien być całkowitą liczbą dodatnią). 
-n ustawia liczbę kolumn planszy (analogicznie jak wyżej). 
-i określa liczbę iteracji wykonanej przez program. 
-d określa kierunek początkowy mrówki (oznaczone kierunkami świata: N, E, W, S). 
-f określa nazwę folderu i przedrostek plików poszczególnych iteracji (domyślnie są one wypisywane do terminala) 
-r włącza tryb losowy. Podany argument z przedziału od zera do jeden określa prawdopodobieństwo, z jakim będą pojawiały się na planszy czarne pola przed rozpoczęciem symulacji. 
-u pozwala dołączyć ścieżkę do pliku z gotową iteracją. Będzie ona wczytana i stanie się zerową iteracją symulacji. 
