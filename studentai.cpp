#include "stdafx.h"
#include "studentai.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <random>
#include <list>
#include <chrono>

double vidurkissk(std::list<double>& paz)
{
	double sum{};
	for (auto i:paz)
	{
		sum += i;
	}
	return sum / paz.size();
}
void skaitymasfailo(std::list<mokinysl>& a,int n)
{
	std::ifstream in("kursiokai"+std::to_string(n)+".txt");
	mokinysl tempm{};
	try
	{
		if (!in.good()) throw 1;
		else if (in.peek() == std::ifstream::traits_type::eof()) throw 0;
	}
	catch (int n)
	{
		if (n == 1)
			std::cout << "Failas nerastas" << std::endl;
		else if (n == 0)
			std::cout << "Failas tuscias" << std::endl;
	}
	for (auto i = 0; i<n; i++)
	{
		in >> tempm.vardas >> tempm.pavarde;
		std::string line;
		std::getline(in, line);
		std::istringstream iss(line);
		double temp;
		while (iss >> temp)
			tempm.paz.push_back(temp);
		temp = tempm.paz.back();
		tempm.egz = temp;
		tempm.paz.pop_back();
		a.push_back(tempm);
		tempm.paz.clear();
	}
	in.close();
}
bool sortByLastNameL(const mokinysl &a, const mokinysl &b)
{
	return a.pavarde > b.pavarde;
}
void skirstimas(std::list<mokinysl>& a, double& vidurkis)
{
	std::list<mokinysl> neprileisti{};
    std::list<mokinysl> prileisti{};
	for (auto i : a)
	{
		vidurkis = vidurkissk(i.paz);
		if (vidurkis < 6)
			neprileisti.push_back(i);
		else if (vidurkis >= 6)
			prileisti.push_back(i);
	}
	/*
	for (auto i = a.begin(); i != a.end();) 
	{
		vidurkis = vidurkissk((*i).paz);
		if (vidurkis < 6)
		{
			neprileisti.push_back((*i));
			i = a.erase(i);
		}	
		else
			++i;
	}
	*/
}
void outputfile(std::list<mokinysl>& a,double vidurkis)
{
	std::ofstream out("rez"+std::to_string(a.size())+".txt");
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
	a.clear();
}
void generavimasfailo(int n)
{
	std::ofstream out("kursiokai"+std::to_string(n)+".txt");
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
void timedgen(int n)
{
	auto start = std::chrono::high_resolution_clock::now();
	generavimasfailo(n);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Failo generavimo laikas: " << elapsed.count() << "s" <<std::endl;
}
void timedproc(std::list<mokinysl>& a, double vidurkis, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	//std::sort(a.begin(), a.end(), sortByLastName);
	a.sort(sortByLastNameL);
	skirstimas(a, vidurkis);
	outputfile(a, vidurkis);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "(L)Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
