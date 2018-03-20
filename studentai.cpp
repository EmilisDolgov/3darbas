#include "stdafx.h"
#include "studentai.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#include <algorithm>

double vidurkissk(std::vector<double>& paz)
{
	double sum{};
	for (auto i = 0; i < paz.size(); i++)
	{
		sum += paz[i];
	}
	return sum / paz.size();
}
double mediana(std::vector<double>& paz)
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
void outputcons(std::string vardas, std::string pavarde, std::vector<double>& paz, double egz)
{
	bool metodas;
	double vidurkis{};
	std::cout << "Pazymiu skaiciavimo budas: mediana(0) arba vidurkis(1)" << std::endl;
	std::cin >> metodas;
	if (metodas == 1)
		vidurkis = vidurkissk(paz);
	else if (metodas == 0)
		vidurkis = mediana(paz);
	double galBalas{};
	std::cout << vardas << " " << pavarde << " ";
	for (auto i = 0; i < paz.size(); i++)
		std::cout << paz[i] << " ";
	std::cout << std::endl;
	galBalas = 0.4*vidurkis + 0.6*egz;
	std::cout << std::fixed << std::setprecision(2) << galBalas << std::endl;
}
bool comparebyalph(mokinys &a, mokinys &b)
{
	return a.vardas < b.vardas;
}
void outputfile(std::vector<mokinys>& a,std::vector<mokinys>& prileisti, std::vector<mokinys>& neprileisti)
{
	std::ofstream out("rez.txt");
	bool metodas;
	double vidurkis{};
	std::cout << "Pazymiu skaiciavimo budas: mediana(0) arba vidurkis(1)" << std:: endl;
	std::cin >> metodas;
	for (auto i = 0; i<a.size(); i++)
	{
		if (metodas == 1)
			vidurkis = vidurkissk(a[i].paz);
		else if (metodas == 0)
			vidurkis = mediana(a[i].paz);
		if (vidurkis >= 6)
			prileisti.push_back(a[i]);
		else if (vidurkis < 6)
			neprileisti.push_back(a[i]);
		out << a[i].vardas << " " << a[i].pavarde << " ";
		for (auto j = 0; j < a[i].paz.size(); j++)
			out << a[i].paz[j] << " ";
		out << std::endl;
		a[i].galBal = 0.4*vidurkis + 0.6*a[i].egz;
		out << std::fixed << std::setprecision(2) << a[i].galBal << std::endl;
		std::setprecision(0);
	}
}
void generavimasfailo(int& n)
{
	std::ofstream out("kursiokai.txt");
	int m = 5;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 10);
	for (auto i = 0; i < n; i++)
	{	
		out << "Vardas" + std::to_string(i) << " ";
		out << "Pavarde" + std::to_string(i) << " ";
		for (auto j = 0; j < m; j++)
			out << dis(gen) << " ";
		out << dis(gen) << std::endl;		
	}
	out.close();

}
