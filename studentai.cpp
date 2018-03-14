#include "stdafx.h"
#include "studentai.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;
using std::ifstream;
using std::ofstream;
using std::endl;



double vidurkissk(vector<double>& paz)
{
	double sum{};
	for (auto i = 0; i < paz.size(); i++)
	{
		sum += paz[i];
	}
	return sum / paz.size();
}
double mediana(vector<double>& paz)
{
	double temp;
	for (auto i = 0; i < paz.size(); i++)
	{
		for (auto j = 0; j < paz.size() - 1; j++)
		{
			if (paz[j] > paz[j + 1])
			{
				temp = paz[j];
				paz[j] = paz[j + 1];
				paz[j + 1] = temp;
			}
		}
	}
	if (paz.size() % 2 == 1)
		return paz[(paz.size() / 2 + 1) - 1];
	else
		return (paz[(paz.size() / 2) - 1] + paz[(paz.size() / 2 + 1) - 1]) / 2;
}
void outputcons(string vardas, string pavarde, vector<double>& paz, double egz)
{
	bool metodas;
	double vidurkis{};
	cout << "Pazymiu skaiciavimo budas: mediana(0) arba vidurkis(1)" << endl;
	cin >> metodas;
	if (metodas == 1)
		vidurkis = vidurkissk(paz);
	else if (metodas == 0)
		vidurkis = mediana(paz);
	double galBalas{};
	cout << vardas << " " << pavarde << " ";
	for (auto i = 0; i < paz.size(); i++)
		cout << paz[i] << " ";
	cout << endl;
	galBalas = 0.4*vidurkis + 0.6*egz;
	cout << fixed << setprecision(2) << galBalas << endl;
}
void outputfile(vector<mokinys>& a)
{
	ofstream out("rez.txt");
	bool metodas;
	double vidurkis{};
	cout << "Pazymiu skaiciavimo budas: mediana(0) arba vidurkis(1)" << endl;
	cin >> metodas;
	for (auto i = 0; i<a.size(); i++)
	{
		if (metodas == 1)
			vidurkis = vidurkissk(a[i].paz);
		else if (metodas == 0)
			vidurkis = mediana(a[i].paz);
		out << a[i].vardas << " " << a[i].pavarde << " ";
		for (auto j = 0; j < a[i].paz.size(); j++)
			out << a[i].paz[j] << " ";
		out << endl;
		a[i].galBal = 0.4*vidurkis + 0.6*a[i].egz;
		out << fixed << setprecision(2) << a[i].galBal << endl;
	}
}
