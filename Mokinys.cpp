#include "stdafx.h"
#include "Mokinys.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <random>
#include <list>
#include <chrono>

bool sortByLastName(Mokinys& a, Mokinys& b) { 
	return a.Vardas() > b.Vardas();
}
double vidurkissk(std::list<double>& paz)
{
	double sum{};
	for (auto i : paz)
	{
		sum += i;
	}
	return sum / paz.size();
}

void skaitymasfailo(std::list<Mokinys>& a,int n)
{
	std::ifstream in("kursiokai"+std::to_string(n)+".txt");
	Mokinys tempc;
	std::string vardas;
	std::string pavarde;
	double egz;
	double vidurkis;
	double galBal;
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
		in >> vardas >> pavarde;
		std::string line;
		std::getline(in, line);
		std::istringstream iss(line);
		double temp;
		std::list<double> paz;
		while (iss >> temp)
			paz.push_back(temp);
		egz = paz.back();
		vidurkis = vidurkissk(paz);
		galBal = 0.4*vidurkis + 0.6*egz;
		Mokinys tempc(vardas, pavarde, egz, vidurkis, galBal);
		a.push_back(tempc);
	}
	in.close();
}
void skaitymasfailo(std::vector<Mokinys>& a, int n)
{
	std::ifstream in("kursiokai" + std::to_string(n) + ".txt");
	Mokinys tempc;
	std::string vardas;
	std::string pavarde;
	double egz;
	double vidurkis;
	double galBal;
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
		in >> vardas >> pavarde;
		std::string line;
		std::getline(in, line);
		std::istringstream iss(line);
		double temp;
		std::list<double> paz;
		while (iss >> temp)
			paz.push_back(temp);
		egz = paz.back();
		vidurkis = vidurkissk(paz);
		galBal = 0.4*vidurkis + 0.6*egz;
		Mokinys tempc(vardas, pavarde, egz, vidurkis, galBal);
		a.push_back(tempc);
	}
	in.close();
}
void skaitymasfailo(std::deque<Mokinys>& a, int n)
{
	std::ifstream in("kursiokai" + std::to_string(n) + ".txt");
	Mokinys tempc;
	std::string vardas;
	std::string pavarde;
	double egz;
	double vidurkis;
	double galBal;
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
		in >> vardas >> pavarde;
		std::string line;
		std::getline(in, line);
		std::istringstream iss(line);
		double temp;
		std::list<double> paz;
		while (iss >> temp)
			paz.push_back(temp);
		egz = paz.back();
		vidurkis = vidurkissk(paz);
		galBal = 0.4*vidurkis + 0.6*egz;
		Mokinys tempc(vardas, pavarde, egz, vidurkis, galBal);
		a.push_back(tempc);
	}
	in.close();
}
void skirstimas(std::list<Mokinys>& a)
{
	std::list<Mokinys> neprileisti{};
    std::list<Mokinys> prileisti{};
	for (auto i : a)
	{
		if (i.Vidurkis() < 6)
			neprileisti.push_back(i);
		else if (i.Vidurkis() >= 6)
			prileisti.push_back(i);
	}

}
void skirstimas(std::vector<Mokinys>& a)
{
	std::vector<Mokinys> neprileisti{};
	std::vector<Mokinys> prileisti{};
	for (auto i : a)
	{
		if (i.Vidurkis() < 6)
			neprileisti.push_back(i);
		else if (i.Vidurkis() >= 6)
			prileisti.push_back(i);
	}

}
void skirstimas(std::deque<Mokinys>& a)
{
	std::deque<Mokinys> neprileisti{};
	std::deque<Mokinys> prileisti{};
	for (auto i : a)
	{
		if (i.Vidurkis() < 6)
			neprileisti.push_back(i);
		else if (i.Vidurkis() >= 6)
			prileisti.push_back(i);
	}

}
bool JeiNeprileistas(Mokinys& a) 
{ 
	return a.Vidurkis() < 6; 
};
void skirstimasistrinant(std::list<Mokinys>& a)
{
	std::list<Mokinys> neprileisti{};
	copy_if(a.begin(), a.end(), back_inserter(neprileisti), JeiNeprileistas);
	a.erase(remove_if(a.begin(), a.end(), JeiNeprileistas), a.end());
}
void skirstimasistrinant(std::vector<Mokinys>& a)
{
	std::vector<Mokinys> neprileisti{};
	copy_if(a.begin(), a.end(), back_inserter(neprileisti), JeiNeprileistas);
	a.erase(remove_if(a.begin(), a.end(), JeiNeprileistas), a.end());
}
void skirstimasistrinant(std::deque<Mokinys>& a)
{
	std::deque<Mokinys> neprileisti{};
	copy_if(a.begin(), a.end(), back_inserter(neprileisti), JeiNeprileistas);
	a.erase(remove_if(a.begin(), a.end(), JeiNeprileistas), a.end());
}
void outputfile(std::list<Mokinys>& a)
{
	std::ofstream out("rez"+std::to_string(a.size())+".txt");
	for(auto i:a)
	{
		out << i.Vardas() << " " << i.Pavarde() << " ";
		out << std::fixed << std::setprecision(2) << i.GalBal() << std::endl;
		std::setprecision(0);
	}
	out.close();
	a.clear();
}
void outputfile(std::vector<Mokinys>& a)
{
	std::ofstream out("rez" + std::to_string(a.size()) + ".txt");
	for (auto i : a)
	{
		out << i.Vardas() << " " << i.Pavarde() << " ";
		out << std::fixed << std::setprecision(2) << i.GalBal() << std::endl;
		std::setprecision(0);
	}
	out.close();
	a.clear();
}
void outputfile(std::deque<Mokinys>& a)
{
	std::ofstream out("rez" + std::to_string(a.size()) + ".txt");
	for (auto i : a)
	{
		out << i.Vardas() << " " << i.Pavarde() << " ";
		out << std::fixed << std::setprecision(2) << i.GalBal() << std::endl;
		std::setprecision(0);
	}
	out.close();
	a.clear();
}
void timedproc(std::list<Mokinys>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
    a.sort(sortByLastName);
	skirstimas(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedproc(std::vector<Mokinys>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	sort(a.begin(), a.end(), sortByLastName);
	skirstimas(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedproc(std::deque<Mokinys>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	sort(a.begin(), a.end(), sortByLastName);
	skirstimas(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::list<Mokinys>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	a.sort(sortByLastName);
	skirstimasistrinant(a);		
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::vector<Mokinys>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	sort(a.begin(), a.end(), sortByLastName);
	skirstimasistrinant(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::deque<Mokinys>& a, int n)
{
	skaitymasfailo(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	sort(a.begin(), a.end(), sortByLastName);
	skirstimasistrinant(a);
	a.clear();
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[L/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void generavimasfailo(int n)
{
	std::ofstream out("kursiokai" + std::to_string(n) + ".txt");
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 10);
	for (auto i = 0; i < n; i++)
	{
		out << "Vardas" + std::to_string(i) << " " << "Pavarde" + std::to_string(i) << " " << dis(gen) << " " << dis(gen) << " " << dis(gen) << " " << dis(gen) << " " << dis(gen) << " "<< dis(gen) << std::endl;
	}
	out.close();

}
void timedgen(int n)
{
	auto start = std::chrono::high_resolution_clock::now();
	generavimasfailo(n);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Failo generavimo laikas: " << elapsed.count() << "s" << std::endl;
}
