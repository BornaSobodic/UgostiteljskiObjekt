#define _CRT_SECURE_NO_WARNINGS
#include "Funkcije.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	inicijalizacija("skladiste.bin"); //16

	int uvijet = 1;

	while (uvijet) {
		uvijet = izbornik("skladiste.bin");
	}

	printf("Kraj programa.");

	return 0;
}