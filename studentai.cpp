#include "stdafx.h"
#include "studentai.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <random>
#include <list>

double vidurkissk(std::list<double>& paz)
{
	double sum{};
	for (auto i:paz)
	{
		sum += i;
	}
	return sum / paz.size();
}
/*double mediana(std::list<double>& paz)
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
}*/
void outputcons(std::string vardas, std::string pavarde, std::list<double>& paz, double egz)
{
	bool metodas;
	double vidurkis{};
	std::cout << "Pazymiu skaiciavimo budas: mediana(0) arba vidurkis(1)" << std::endl;
	try
	{
		std::cin >> metodas;
		if (metodas != 0 && metodas != 1)
			throw 1;
	}
	catch (int a)
	{
		std::cout << "Iveskite 0 arba 1" << std::endl;
		exit(a);
	}
	if (metodas == 1)
		vidurkis = vidurkissk(paz);
	//else if (metodas == 0)
		//vidurkis = mediana(paz);
	double galBalas{};
	std::cout << vardas << " " << pavarde << " ";
	for (auto i : paz)
		std::cout << i << " ";
	std::cout << std::endl;
	galBalas = 0.4*vidurkis + 0.6*egz;
	std::cout << std::fixed << std::setprecision(2) << galBalas << std::endl;
}

bool sortByLastName(const mokinys &a, const mokinys &b)
{
	return a.pavarde > b.pavarde;
}
void skirstimas(std::list<mokinys>& a, bool metodas, double& vidurkis)
{
	std::list<mokinys> neprileisti{};
    std::list<mokinys> prileisti{};
	for (auto i : a)
	{
		if (metodas == 1)
			vidurkis = vidurkissk(i.paz);
		if (vidurkis < 6)
		{
			neprileisti.push_back(i);
		}
		else if (vidurkis >= 6)
			prileisti.push_back(i);
	}
	/*for (auto i = a.begin(); i != a.end();) 
	{
		if (metodas == 1)
			vidurkis = vidurkissk((*i).paz);
		if (vidurkis < 6)
		{
			neprileisti.push_back((*i));
			i = a.erase(i);
		}	
		else
			++i;
	}*/
}
void outputfile(std::list<mokinys>& a,bool metodas,double vidurkis)
{
	std::ofstream out("rez.txt");
	for(auto i:a)
	{
		out << i.vardas << " " << i.pavarde << " ";
		for (auto j:i.paz)
			out << j << " ";
		out << std::endl;
		i.galBal = 0.4*vidurkis + 0.6*i.egz;
		out << std::fixed << std::setprecision(2) << i.galBal << std::endl;
		std::setprecision(0);
	}
	out.close();
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
