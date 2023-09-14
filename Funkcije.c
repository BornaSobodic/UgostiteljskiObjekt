#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrukturaProizvoda.h"

static int brojProizvoda = 0; //10

//17

void inicijalizacija(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		fp = fopen(ime, "wb");

		fwrite(&brojProizvoda, sizeof(int), 1, fp);

		fclose(fp);
	}
	else {
		fclose(fp);
	}
}


void dodajProizvod(const char* const ime) {

	FILE* fp = fopen(ime, "rb+");

	if (fp == NULL) {
		perror("Dodavanje clanova u datoteku");   //19
		exit(EXIT_FAILURE);
	}

	fread(&brojProizvoda, sizeof(int), 1, fp);
	printf("Broj clanova: %d\n", brojProizvoda);

	PROIZVOD temp = { 0 };

	temp.id = brojProizvoda + 1;

	getchar();

	printf("Unesite ime: ");
	scanf("%24[^\n]", temp.ime);    //2
	getchar();



	printf("unesite vrstu pica: ");
	scanf("%24[^\n]", temp.vrsta);
	getchar();

	printf("unesite cijenu proizvoda: ");
	scanf("%f", &temp.cijena);
	getchar();

	printf("unesite kolicinu proizvoda: ");
	scanf("%d", &temp.kolicina);
	getchar();

	fseek(fp, sizeof(PROIZVOD) * brojProizvoda, SEEK_CUR); //17
	fwrite(&temp, sizeof(PROIZVOD), 1, fp);

	rewind(fp);

	brojProizvoda++;

	fwrite(&brojProizvoda, sizeof(int), 1, fp);
	fclose(fp);
}


void* ucitajProizvod(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		perror("Ucitavanje clanova iz datoteke"); //19
		exit(EXIT_FAILURE);
	}

	fread(&brojProizvoda, sizeof(int), 1, fp);
	printf("Broj proizvoda: %d\n", brojProizvoda);

	PROIZVOD* poljeProizvoda = (PROIZVOD*)calloc(brojProizvoda, sizeof(PROIZVOD));

	if (poljeProizvoda == NULL) {
		perror("Zauzimanje memorije za polje proizvoda.");
		return NULL;

	}

	fread(poljeProizvoda, sizeof(PROIZVOD), brojProizvoda, fp);

	printf("Svi proizvodi ucitani..\n");

	return poljeProizvoda;
}

void zamjena(PROIZVOD* const veci, PROIZVOD* const manji) {
	PROIZVOD temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

void* sortiraj(PROIZVOD* polje) {  //20
	int min = -1;
	for (int i = 0; i < brojProizvoda - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < brojProizvoda; j++)
		{
			if ((polje + j)->cijena < (polje + min)->cijena) {
				min = j;
			}
		}
		zamjena((polje + i), (polje + min));
	}

	return polje;
}

void ispisiSortiraneProizvode(const PROIZVOD* polje) {

	if (brojProizvoda == 0) {
		printf("Polje proizvoda prazno\n");
		return;
	}


	polje = sortiraj(polje);


	for (int i = 0; i < brojProizvoda; i++) {
		printf("ID: %d\tIme: %s\tvrsta: %s\tcijena: %.2f\tkolicina: %d\n\n",
			(polje + i)->id,
			(polje + i)->ime,
			(polje + i)->vrsta,
			(polje + i)->cijena,
			(polje + i)->kolicina);
	}
}

void ispisiProizvoda(const PROIZVOD* const polje) {

	if (polje == NULL) {
		printf("Polje proizvoda prazno");
		return;
	}

	int i;

	for (i = 0; i < brojProizvoda; i++) {
		printf("ID: %d\tIme: %s\tvrsta: %s\tcijena: %.2f\tkolicina: %d\n\n",
			(polje + i)->id,
			(polje + i)->ime,
			(polje + i)->vrsta,
			(polje + i)->cijena,
			(polje + i)->kolicina);
	}
}


void* pretrazivanje(PROIZVOD* const polje) {  //21

	if (polje == NULL) {
		printf("Polje proizvoda prazno");
		return NULL;
	}

	int i;

	int trazeniId;

	printf("Unesite ID proizvoda kojeg trazite: ");
	scanf("%d", &trazeniId);

	for (i = 0; i < brojProizvoda; i++) {

		if (trazeniId == (polje + i)->id) {
			printf("Proizvod pronaden.\n");

			return (polje + i);
		}
	}

	return NULL;
}


void brisanjePROIZVODA(PROIZVOD* const polje, const char* const dat) {

	if (brojProizvoda == 0) {
		printf("Polje proizvoda je prazno\n");
		return;
	}

	FILE* fp = fopen(dat, "rb+");

	if (fp == NULL) {
		perror("Brisanje proizvoda");
		exit(EXIT_FAILURE);
	}

	fseek(fp, sizeof(int), SEEK_CUR);

	int i, trazeniId;

	printf("Unesite ID proizvoda kojeg zelite obrisati: ");

	do {
		scanf("%d", &trazeniId);
		if (trazeniId < 1 || trazeniId > brojProizvoda) {
			printf("Proizvod s unesenim ID-em ne postoji. Unesite ID koji postoji: ");
		}
	} while (trazeniId < 1 || trazeniId > brojProizvoda);

	PROIZVOD* poljeProizvoda = (PROIZVOD*)calloc(brojProizvoda - 1, sizeof(PROIZVOD)); //14

	int counter = 0;

	for (i = 0; i < brojProizvoda; i++) {

		if (trazeniId != (polje + i)->id) {
			*(poljeProizvoda + counter) = *(polje + i);

			if ((poljeProizvoda + counter)->id > trazeniId) {
				(poljeProizvoda + counter)->id -= 1;
			}

			fwrite((poljeProizvoda + counter), sizeof(PROIZVOD), 1, fp);
			counter++;
		}
	}

	free(poljeProizvoda); //15
	poljeProizvoda = NULL;

	rewind(fp);

	fwrite(&counter, sizeof(int), 1, fp);
	fclose(fp);

	printf("Proizvod je uspjesno obrisan\n");
}

int brisanjeDatoteke(char* fp) {

	int status;

	status = remove("skladiste.bin");//18

	if (status == 0) {
		printf("Datoteka uspjesno obrisana\n");

	}
	else {
		printf("Nije moguce obrisati datoteku\n");
	}
	return 0;
}

int izlaz(PROIZVOD* polje) {

	free(polje);

	return 0;
}
