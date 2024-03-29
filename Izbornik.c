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
	printf("Opcija 6: Zavrsetak programa\n");
	printf("Opcija 7: Brisanje datoteke\n");

	int uvijet = 0;

	static PROIZVOD* poljeProizvoda = NULL;   
	static PROIZVOD* pronadeniProizvod = NULL; 

	scanf("%d", &uvijet);
	system("cls");



	switch (uvijet) {                     //Ovo su opcije koje imam u izborniku
	case 1: //6

		dodajProizvod(ime);

		break;

	case 2:  

		if (poljeProizvoda != NULL) {
			free(poljeProizvoda);
			poljeProizvoda = NULL;
		}

		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);

		ispisiSortiraneProizvode(poljeProizvoda);


		break;

	case 3:
		if (poljeProizvoda != NULL) {
			free(poljeProizvoda);
		}

		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);  //9

		ispisiProizvoda(poljeProizvoda);


		break;

	case 4:
		if (poljeProizvoda != NULL) {
			free(poljeProizvoda);
		}

		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);

		pronadeniProizvod = (PROIZVOD*)pretrazivanje(poljeProizvoda);

		if (pronadeniProizvod != NULL) {
			printf("ID: %d\n", pronadeniProizvod->id);
			printf("Ime: %s\n", pronadeniProizvod->ime);
			printf("vrsta proizvoda: %s\n", pronadeniProizvod->vrsta);
			printf("kolicina proizvoda: %d\n", pronadeniProizvod->kolicina);
		}
		else {
			printf("Ne postoji proizvod s tim ID-em");
		}

		break;

	case 5:

		if (poljeProizvoda != NULL) {
			free(poljeProizvoda);
			poljeProizvoda = NULL;
		}

		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);

		brisanjePROIZVODA(poljeProizvoda, ime);
		break;

	case 6:

		uvijet = izlaz(poljeProizvoda);
		break;

	case 7:
		brisanjeDatoteke("skladiste.bin");

		break;

	default:
		uvijet = 0;
	}


	return uvijet;
}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include "Funkcije.h"
//#include <stdio.h>
//#include <stdlib.h>
////8
//int izbornik(const char* const ime) {
//
//	printf("Odaberite jednu od ponudenih opcija\n\n");            // Izbornik
//
//	printf("Opcija 1: Dodavanje proizvoda\n");
//	printf("Opcija 2: Sortiranje po cijeni\n");
//	printf("Opcija 3: Ispisivanje svih prozvoda\n");
//	printf("Opcija 4: Pretrazivanje proizvoda po ID-u\n");
//	printf("Opcija 5: Brisanje proizvoda\n");
//	printf("Opcija 6: Zavrsetak programa\n\n");
//	printf("Opcija 7: Brisanje datoteke\n");
//
//	int uvijet = 0; //1
//
//	static PROIZVOD* poljeProizvoda = NULL;
//	static PROIZVOD* pronadeniProizvod = NULL;
//
//	scanf("%d", &uvijet);
//	system("cls");
//
//
//
//	switch (uvijet) {                     //Ovo su opcije koje imam u izborniku
//	case 1: //6
//
//		dodajProizvod(ime);
//
//		break;
//
//	case 2:   //14
//
//		if (poljeProizvoda != NULL) {
//			free(poljeProizvoda);
//			poljeProizvoda = NULL;
//		}
//
//		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);
//
//		ispisiSortiraneProizvode(poljeProizvoda);
//
//
//		break;
//
//	case 3:
//		if (poljeProizvoda != NULL) {
//			free(poljeProizvoda);
//		}
//
//		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);
//
//		ispisiProizvoda(poljeProizvoda);
//
//
//		break;
//
//	case 4:
//		if (poljeProizvoda != NULL) {
//			free(poljeProizvoda);
//		}
//
//		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);
//
//		pronadeniProizvod = (PROIZVOD*)pretrazivanje(poljeProizvoda);
//
//		if (pronadeniProizvod != NULL) {
//			printf("ID: %d\n", pronadeniProizvod->id);
//			printf("Ime: %s\n", pronadeniProizvod->ime);
//			printf("vrsta proizvoda: %s\n", pronadeniProizvod->vrsta);
//			printf("kolicina proizvoda: %d\n", pronadeniProizvod->kolicina);
//		}
//		else {
//			printf("Ne postoji proizvod s tim ID-em");
//		}
//
//		break;
//
//	case 5:
//
//		if (poljeProizvoda != NULL) {
//			free(poljeProizvoda);
//			poljeProizvoda = NULL;
//		}
//
//		poljeProizvoda = (PROIZVOD*)ucitajProizvod(ime);
//
//		brisanjePROIZVODA(poljeProizvoda, ime);
//		break;
//
//	case 6:
//
//		uvijet = izlaz(poljeProizvoda);
//		break;
//	default:
//		uvijet = 0;
//	}
//
//
//	return uvijet;
//}
