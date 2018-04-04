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
		std::deque<double> paz;
		while (iss >> temp)
			paz.push_back(temp);
		tempm.egz = paz.back();
		tempm.vidurkis = vidurkissk(paz);
		a.push_back(tempm);
	}
	in.close();
}
bool sortByLastNameL(mokinysl& a,  mokinysl& b)
{
	return a.pavarde > b.pavarde;
}
bool jeiNeprileistas(mokinysl &a)
{
	return a.vidurkis < 6;
}
void skirstimas(std::list<mokinysl>& a)
{
	std::list<mokinysl> neprileisti{};
    std::list<mokinysl> prileisti{};
	for (auto i : a)
	{
		if (i.vidurkis < 6)
			neprileisti.push_back(i);
		else if (i.vidurkis >= 6)
			prileisti.push_back(i);
	}

}
void skirstimasistrinant(std::list<mokinysl>& a)
{
	std::list<mokinysl> neprileisti{};
	copy_if(a.begin(), a.end(), back_inserter(neprileisti), jeiNeprileistas);
	a.erase(remove_if(a.begin(), a.end(), jeiNeprileistas), a.end());
}
void outputfile(std::list<mokinysl>& a)
{
	std::ofstream out("rez"+std::to_string(a.size())+".txt");
	for(auto i:a)
	{
		out << i.vardas << " " << i.pavarde << " ";
		i.galBal = 0.4*i.vidurkis + 0.6*i.egz;
		out << std::fixed << std::setprecision(2) << i.galBal << std::endl;
		std::setprecision(0);
	}
	out.close();
	a.clear();
}
void timedproc(std::list<mokinysl>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
    //a.sort(sortByLastNameL);
	skirstimas(a);
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::list<mokinysl>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	//a.sort(sortByLastNameL);
	skirstimasistrinant(a);
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
