#pragma once
#ifndef StrukturaProizvoda_H
#define StrukturaProizvoda_H

//3
typedef struct proizvod {       //Struktura proizvoda
	int id;
	char ime[20];
	char vrsta[20];
	float cijena;
	int kolicina;
}PROIZVOD;

#endif //StrukturaProizvoda_H