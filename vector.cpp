#include "stdafx.h"
#include "studentai.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>

double vidurkissk(std::vector<double>& paz)
{
	double sum{};
	for (auto i : paz)
	{
		sum += i;
	}
	return sum / paz.size();
}
void skaitymasfailo(std::vector<mokinysv>& a, int n)
{
	std::ifstream in("kursiokai" + std::to_string(n) + ".txt");
	mokinysv tempm{};
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
bool sortByLastNameV(mokinysv& a, mokinysv& b)
{
	return a.pavarde > b.pavarde;
}
void skirstimas(std::vector<mokinysv>& a)
{
	std::vector<mokinysv> neprileisti{};
	std::vector<mokinysv> prileisti{};
	for (auto i : a)
	{
		if (i.vidurkis < 6)
			neprileisti.push_back(i);
		else if (i.vidurkis >= 6)
			prileisti.push_back(i);
	}
}
bool jeiNeprileistas(mokinysv& a)
{
	return a.vidurkis < 6;
}
void skirstimasistrinant(std::vector<mokinysv>& a)
{
	std::vector<mokinysv> neprileisti{};
	copy_if(a.begin(), a.end(), back_inserter(neprileisti), jeiNeprileistas);
	a.erase(remove_if(a.begin(), a.end(), jeiNeprileistas), a.end());	
}
void outputfile(std::vector<mokinysv>& a)
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
void timedproc(std::vector<mokinysv>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(a.begin(), a.end(), sortByLastNameV);
	skirstimas(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[V/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::vector<mokinysv>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(a.begin(), a.end(), sortByLastNameV);
	skirstimasistrinant(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[V/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
