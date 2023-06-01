#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrukturaProizvoda.h"

static int brojArtikala = 0;

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

	ARTIKL temp = { 0 };

	temp.id = brojProizvoda + 1;

	getchar();

	printf("Unesite ime: ");
	scanf("%24[^\n]", temp.ime);
	getchar();

	printf("Unesite broj godina odlezanosti: ");
	scanf("%d", &temp.starost);
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

	fseek(fp, sizeof(PROIZVOD) * brojProizvoda, SEEK_CUR);
	fwrite(&temp, sizeof(PROIZVOD), 1, fp);

	rewind(fp);

	brojProizvoda++;

	fwrite(&brojProizvoda, sizeof(int), 1, fp);
	fclose(fp);
}


void* ucitajProizvod(const char* const ime) {   //10

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		perror("Ucitavanje clanova iz datoteke");
		exit(EXIT_FAILURE);
	}

	fread(&brojProizvoda, sizeof(int), 1, fp);
	printf("Broj artikala: %d\n", brojProizvoda);

	PROIZVOD* poljeProizvoda = (PROIZVOD*)calloc(brojProizvoda, sizeof(PROIZVOD));

	if (poljeProizvoda == NULL) {
		perror("Zauzimanje memorije za polje artikala.");
		return NULL;

	}

	fread(poljeProizvoda, sizeof(PROIZVOD), brojProizvoda, fp);

	printf("Svi artikli ucitani..\n");

	return poljeProizvoda;
}


void* pretrazivanje(PROIZVOD* const polje) {  

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