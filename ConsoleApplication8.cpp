// Vidurkis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string; using std::endl;

int main()
{
	string vardas;
	string pavarde;
	int n{};
	double vidurkis{};
	double sum{};
	cout << "Vardas: ";
	cin >> vardas;
	cout << "Pavarde: ";
	cin >> pavarde;
	cout << "Pazymiu kiekis: ";
	cin >> n;
	double *paz = new double[n];
	for (auto i = 0; i < n; i++)
	{
		cin >> paz[i];
	}
	for (auto i=0;i<n;i++)
	{
		sum += paz[i];
	}
	vidurkis = sum / n;
	cout << vardas << " " << pavarde << " ";
	for (int i = 0; i < n; i++)
		cout << paz[i] << " ";
	cout << endl;
	cout << "Vidurkis " << vidurkis << endl;
	return 0;
}