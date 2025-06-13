#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int N = 5000;
int main()
{
	int tab[N];
	ifstream in("dane.txt");
	ofstream out("wyniki.txt");
	for (int i = 0; i < N; i++) {
		in >> tab[i];
	}
	out << "ZADANIE 1" << endl;
	int ile_takich_samych = 0;
	for(int i = 0; i < N; i++) {
		int liczba = tab[i];
		int pierwsza = 0;
		int ostatnia = 0;
		ostatnia = liczba%10;
		while(liczba != 0) {
			pierwsza = liczba%10;
			liczba /= 10;
		}
		if(pierwsza == ostatnia) {
			ile_takich_samych++;
		}
	}
	out << ile_takich_samych << endl;

	out << "ZADANIE 2" << endl;
	int ile_takich_samych_dziesietne = 0;
	for(int i = 0; i < N; i++) {
		int osemkowy = tab[i];
		int dziesietny = 0;
		int ostatnia = 0;
		int iterator = 0;
		while(osemkowy != 0) {
			ostatnia = osemkowy%10;
			osemkowy /= 10;
			dziesietny += ostatnia*pow(8,iterator);
			iterator++;
		}
		int pierwsza = 0;
		int ostatnia_dziesietne = 0;
		ostatnia_dziesietne = dziesietny%10;
		while(dziesietny != 0) {
			pierwsza = dziesietny%10;
			dziesietny /= 10;
		}
		if(pierwsza == ostatnia_dziesietne) {
			ile_takich_samych_dziesietne++;
		}
	}
	out << ile_takich_samych_dziesietne << endl;

	out << "ZADANIE 3" << endl;
	int ile_rosnacych_cyfr = 0;
	int najwieksza = 0;
	int najmniejsza = 30000;
	for(int i = 0; i < N; i++) {
		int liczba = tab[i];
		int oryginalna_liczba = liczba;
		int poprzednia = liczba%10;
		int obecna = 0;
		bool czy_zachodzi_warunek = true;
		while(liczba != 0) {
			obecna = liczba%10;
			if(obecna <= poprzednia) {
				czy_zachodzi_warunek = true;
			} else {
				czy_zachodzi_warunek=false;
				break;
			}
			liczba /= 10;
			poprzednia=obecna;
		}
		if(czy_zachodzi_warunek) {
			if(oryginalna_liczba>najwieksza) {
				najwieksza = oryginalna_liczba;
			} else if(oryginalna_liczba<najmniejsza) {
				najmniejsza = oryginalna_liczba;
			}
		}
		if(czy_zachodzi_warunek) {
			ile_rosnacych_cyfr++;
		}
	}
	out << ile_rosnacych_cyfr << endl;
	out << najmniejsza << endl;
	out << najwieksza << endl;
}
