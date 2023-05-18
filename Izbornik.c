#define _CRT_SECURE_NO_WARNINGS

#include "Funkcije.h"
#include <stdio.h>
#include <stdlib.h>
//8
int izbornik(const char* const ime) {

	printf("Odaberite jednu od ponudenih opcija\n\n");            // Izbornik

	printf("Opcija 1: Dodavanje proizvoda\n");
	printf("Opcija 2: Sortiranje po cijeni\n");
	printf("Opcija 3: Ispisivanje svih prozvoda\n");
	printf("Opcija 4: Pretrazivanje proizvoda po ID-u\n");
	printf("Opcija 5: Brisanje proizvoda\n");
	printf("Opcija 6: Zavrsetak programa\n\n");

	int uvijet = 0;

	static PROIZVOD* poljeProizvoda = NULL;
	static PROIZVOD* pronadeniProizvoda = NULL;

	switch (uvijet) {                     //Ovo su opcije koje imam u izborniku
	case 1:

		dodajProizvod(ime);

		break;

	case 2:
	

		break;
	case 3:


		break;

	case 4:
		
		break;

	case 5:

		break;

	case 6:

		break;
	default:
		
	}

	return uvijet;
}