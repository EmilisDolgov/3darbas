#include "stdafx.h"
#include "Mokinys.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <random>
#include <vector>
#include <chrono>
struct greater
{
	template<class T>
	bool operator()(T const &a, T const &b) const { return a > b; }
};
bool JeiNeprileistas(Mokinys& a)
{
	return a.GalBal() < 6;
};
double vidurkissk(std::vector<double>& paz)
{
	double sum{};
	for (auto i : paz)
	{
		sum += i;
	}
	return sum / paz.size();
}
Mokinys::Mokinys(std::istream& input) 
{
	input >> vardas >> pavarde;
	for (auto i = 0; i < 5; i++) {
		double t;
		std::vector<double> temp;
		input >> t;
		temp.push_back(t);
		vidurkis = vidurkissk(temp);
	}
	input >> egz;
	galBal= 0.4*vidurkis + 0.6*egz;
}
void nskaitymasf(std::vector<Mokinys>& a, int n)
{
	Mokinys *b;
	std::ifstream in("kursiokai" + std::to_string(n) + ".txt");
	a.reserve(n);
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
	while (!in.eof()) {
		b = new Mokinys(in);
		if (in.eof()) break;
		a.push_back(*b);

	}
}
void skirstimas(std::vector<Mokinys>& a)
{
	
	auto it = std::partition(a.begin(), a.end(), JeiNeprileistas);
	std::vector<Mokinys> neprileisti(a.begin(), it);
	std::vector<Mokinys> prileisti(it, a.end());
}
void skirstimasistrinant(std::vector<Mokinys>& a)
{	
	auto it = std::partition(a.begin(), a.end(), JeiNeprileistas);
	std::vector<Mokinys> neprileisti(a.begin(), it);
	a.erase(a.begin(), it);
}
void outputfile(std::vector<Mokinys>& a)
{
	std::ofstream out("rez" + std::to_string(a.size()) + ".txt");
	for (auto i : a)
	{
		out << i << std::endl;
	}
	out.close();
	a.clear();
}
void timedproc(std::vector<Mokinys>& a, int n)
{
	nskaitymasf(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	skirstimas(a);
	sort(a.begin(), a.end(), greater());
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[V/3c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
}
void timedprocwdel(std::vector<Mokinys>& a, int n)
{
	nskaitymasf(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	skirstimasistrinant(a);
	sort(a.begin(), a.end(),greater());
	outputfile(a);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "[V/2c]Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << std::endl;
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
