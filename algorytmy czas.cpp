#include "pch.h"
#include <ctime> 
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

void wypiszRand(int tab[], int num)
{
	for (int i = 0; i < num;i++)
	{
		tab[i] = rand() % 500;
		//cout << tab[i] << " ";
	}
}

void wypisz(int tab[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << tab[i] << " ";
	}
}

int kopiujTablice(int tab[], int tab2[], int num)
{
	for (int i = 0; i < num; i++)
	{
		tab2[i] = tab[i];
	}
	return 0;
}

void wypiszKopia(int tab[], int tab2[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << tab2[i] << " ";
	}
}

void sortowaniePrzezWstawianie(int tab[], int num)
{
	int pom, j;
	for (int i = 0; i < num; i++)
	{
		pom = tab[i];
		j = i - 1;

		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = pom;
	}
}

void sortowanieBabelkowe(int tab[], int num)
{
	int tmp;
	for (int i = 1; i < num - 1;i++)
	{
		for (int j = num - 1; j >= i;j--)
		{
			if (tab[j] < tab[j - 1])
			{
				tmp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = tmp;
			}
		}
	}
}

void prostyWybor(int tab[], int num) {
	for (int i = 0; i < num - 1;i++) {
		int c = i;
		int b = tab[i];

		for (int j = i + 1; j < num; j++) {
			if (tab[j] < b) {
				c = j;
				b = tab[j];

			}
		}
		tab[c] = tab[i];
		tab[i] = b;
	}
}

void merge(int tab[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];


	for (int i = 0; i < n1; i++)
		L[i] = tab[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = tab[m + 1 + j];




	int i = 0;


	int j = 0;


	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			tab[k] = L[i];
			i++;
		}
		else {
			tab[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		tab[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		tab[k] = R[j];
		j++;
		k++;
	}
}

int mergeSort(int tab[], int l, int r) {
	if (l >= r) {
		return 0;
	}
	int m = (l + r) / 2;
	mergeSort(tab, l, m);
	mergeSort(tab, m + 1, r);
	merge(tab, l, m, r);
}

void sortowanie(int tab[], int a) {
	for (int i = a - 1; i > 0; i--) {
		for (int j = i; j >= 0;j--) {
			if (tab[i] > tab[j])
				swap(tab[i], tab[j]);

		}
	}
}

void sortowanieOdwrotne(int tab[], int a) {
	for (int i = a - 1; i > 0; i--) {
		for (int j = i; j >= 0;j--) {
			if (tab[i] > tab[j])
				swap(tab[i], tab[j]);

		}
	}
}

void intOdwrotnieSortTab(int tab[], int num)
{
	for (int i = 0; i < num; i++)
	{
		tab[i] = num - 1 - i;
	}
}

int main(int argc) {

	int num;
	cout << "podaj wielkosc tablicy: ";
	cin >> num;
	int* tab = new int[num];
	int* tab2 = new int[num];


	int iloscSort;
	cout << "Ilosc sortowan: ";
	cin >> iloscSort;

	srand(2001/*(unsigned)time(NULL)*/);

	//cout << "nieposortowane elementy:" << endl;

	wypiszRand(tab, num);
	cout << endl;

	kopiujTablice(tab, tab2, num);
	cout << endl;
	//cout << "druga tablica skopiowana:" << endl;
	for (int i = 0; i < iloscSort; i++)
		sortowaniePrzezWstawianie(tab2, num);
	//wypiszKopia(tab, tab2, num);

	cout << endl;


	time_t t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		prostyWybor(tab, num);
	}
	time_t t2 = clock();
	time_t czasprosty = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla nieposortowanej tablicy, prosty wybor: " << czasprosty << " sec" << endl;
	wypiszRand(tab, num);
	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		sortowanieBabelkowe(tab, num);
	}
	t2 = clock();
	time_t czasBabelkowego = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania nieposortowane, babelkowe: " << czasBabelkowego << " sec" << endl;
	wypiszRand(tab, num);


	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		sortowaniePrzezWstawianie(tab, num);
	}
	t2 = clock();
	time_t czassort = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania nieposortowanej, wstawienie: " << czassort << " sec" << endl;
	wypiszRand(tab, num);


	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		mergeSort(tab, 0, num);
	}
	t2 = clock();
	time_t czasmerge = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania nieposortowanej, merge sort: " << czasmerge << " sec" << endl;


	cout << endl;

	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		prostyWybor(tab2, num);
	}
	t2 = clock();
	czasprosty = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania tablicy posortowanej prosty wybor: " << czasprosty << " sec" << endl;

	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		sortowanieBabelkowe(tab2, num);
	}
	t2 = clock();
	czasBabelkowego = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania tablicy posortowanej babelkowe: " << czasBabelkowego << " sec" << endl;


	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		sortowanie(tab2, num);
	}
	t2 = clock();
	czassort = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania tablicy posortowanej przez wstawienie: " << czassort << " sec" << endl;

	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		mergeSort(tab2, 0, num);
	}
	t2 = clock();
	czasmerge = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania tablicy posortowanej merge sort: " << czasmerge << " sec" << endl;


	cout << endl;

	intOdwrotnieSortTab(tab, num);

	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		prostyWybor(tab, num);
	}
	t2 = clock();
	czasprosty = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania odwroconej  prosty wybor: " << czasprosty << " sec" << endl;

	intOdwrotnieSortTab(tab, num);

	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		sortowanieBabelkowe(tab, num);
	}
	t2 = clock();
	czasBabelkowego = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania odwroconej babelkowej: " << czasBabelkowego << " sec" << endl;
	intOdwrotnieSortTab(tab, num);

	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		sortowanie(tab, num);
	}
	t2 = clock();
	czassort = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania odwroconej przez wstawienie: " << czassort << " sec" << endl;

	intOdwrotnieSortTab(tab, num);
	t1 = clock();
	for (int i = 0; i < iloscSort; i++)
	{
		mergeSort(tab, 0, num);
	}
	t2 = clock();
	czasmerge = (t2 - t1);// / CLOCKS_PER_SEC;
	cout << "Czas sortowania odwroconej merge " << czasmerge << " sec" << endl;
	return 0;
}
