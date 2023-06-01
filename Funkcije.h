#pragma once
#ifndef FUNKCIJE_H
#define FUNKCIJE_H
#include "StrukturaProizvoda.h"

int izbornik(const char* const);
void inicijalizacija(const char* const);
void dodajProizvod(const char* const);
void* ucitajProizvod(const char* const);
void ispisiProizvoda(const PROIZVOD* const);
void brisanjePROIZVODA(PROIZVOD* const, const char* const);
void* pretrazivanje(PROIZVOD* const);
void* sortiraj(char*);
void ispisiSortiraneProizvode(const PROIZVOD* polje);
#endif