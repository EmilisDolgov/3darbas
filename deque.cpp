#include "stdafx.h"
#include "Mokinys.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <random>
#include <deque>
#include <chrono>

/*double vidurkissk(std::deque<double>& paz)
{
	double sum{};
	for (auto i : paz)
	{
		sum += i;
	}
	return sum / paz.size();
}
bool jeiNeprileistas(mokinysd& a)
{
	return a.vidurkis < 6;
}
void skaitymasfailo(std::deque<mokinysd>& a, int n)
{
	std::ifstream in("kursiokai" + std::to_string(n) + ".txt");
	mokinysd tempm{};
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
		std::deque<double> paz;
		while (iss >> temp)
			paz.push_back(temp);
		tempm.egz = paz.back();
		tempm.vidurkis = vidurkissk(paz);
		a.push_back(tempm);
	}
	in.close();
}
bool sortByLastNameD(mokinysd& a, mokinysd& b)
{
	return a.pavarde > b.pavarde;
}
void skirstimas(std::deque<mokinysd>& a)
{
	std::deque<mokinysd> neprileisti{};
	std::deque<mokinysd> prileisti{};
	for (auto i : a)
	{
		if (i.vidurkis < 6)
			neprileisti.push_back(i);
		else if (i.vidurkis >= 6)
			prileisti.push_back(i);
	}

}
void skirstimasistrinant(std::deque<mokinysd>& a)
{
	std::deque<mokinysd> neprileisti{};
	copy_if(a.begin(), a.end(), back_inserter(neprileisti), jeiNeprileistas);
	a.erase(remove_if(a.begin(), a.end(), jeiNeprileistas), a.end());
}
void outputfile(std::deque<mokinysd>& a)
{
	std::ofstream out("rez" + std::to_string(a.size()) + ".txt");
	for (auto i : a)
	{
		out << i.vardas << " " << i.pavarde << " ";
		i.galBal = 0.4*i.vidurkis + 0.6*i.egz;
		out << std::fixed << std::setprecision(2) << i.galBal << std::endl;
		std::setprecision(0);
	}
	out.close();
	a.clear();
}
void timedproc(std::deque<mokinysd>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(a.begin(), a.end(), sortByLastNameD);
	skirstimas(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[D/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::deque<mokinysd>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(a.begin(), a.end(), sortByLastNameD);
	skirstimasistrinant(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[D/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}*/
