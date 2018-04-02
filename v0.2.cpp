// Vidurkis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include <chrono>
#include <list>
#include <deque>
#include "studentai.h"


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::array;
using std::fixed;
using std::setprecision;
using std::list;
using std::deque;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;


int main()
{
	string vardas;
	string pavarde;
	bool inpmetodas;
	bool sk;
	double vidurkis{};
	double sum{};
	double egz{};
	int n{};
	int moksk{};
	double laik{};
	list<double> paz{};
	list<mokinys> prileisti{};
	list<mokinys> neprileisti{};
	cout << "Kiek mokiniu sugeneruoti?" << endl;
	try
	{
		cin >> moksk;
		if (moksk < 1)
		{
			throw 0;
		}
	}
	catch (int a)
	{
		cout << "Iveskite sveikaji mokiniu skaiciu" << endl;
		exit(a);
	}
	auto start = std::chrono::high_resolution_clock::now();
	generavimasfailo(moksk);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Failo nuskaitymo laikas: " << elapsed.count() << "s" << endl;
	cout << "Duomenu ivedimo budas: ivedimas(0) arba skaitymas is failo(1)" << endl;
	try
	{
		cin >> sk;
		if (sk != 0 && sk != 1)
			throw 1;
	}
	catch (int a)
	{
		cout << "Iveskite 0 arba 1" << endl;
		exit(a);
	}
	if (!sk)
	{
		cout << "Vardas: ";
		cin >> vardas;
		cout << "Pavarde: ";
		cin >> pavarde;
		cout << "Egzamino ivertinimas: ";		
		try
		{
			cin >> egz;
			if (egz<0||egz>10)
				throw 1;
		}
		catch (int a)
		{
			cout << "Iveskite skaiciu tarp 0 ir 10" << endl;
			exit(a);
		}
		cout << "Pazymiu gavimo budas: ivedimas(0) arba generavimas(1)" << endl;
		cin >> inpmetodas;
		int input{};
		if (!inpmetodas)
		{
			cout << "Pazymiai. Noredami sustabdyti vedima iveskite -1" << endl;
			while (cin >> input)
			{
				if (input==-1)
					break;
				paz.push_back(input);
				n++;
			}
			if (paz.size()== 0)
			{
				cout << "Privalote ivesti ND ivertinimus" << endl;
				return 1;
			}
		}
		else
		{
			std::random_device rd;  //Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			std::uniform_int_distribution<> dis(1, 10);
			cout << "Kiek skaiciu sugeneruoti?" << endl;
			cin >> n;
			for (auto i = 0; i < n; i++)
			{
				paz.push_back(dis(gen));
			}

		}
		outputcons(vardas, pavarde, paz, egz);
	}
	else
	{
		list<mokinys> a;
		int i{};
		mokinys tempm{};
		ifstream in("kursiokai.txt");
		try 
		{
			if (!in.good()) throw 1;
			else if (in.peek() == ifstream::traits_type::eof()) throw 0;
		}
		catch (int n)
		{
			if (n == 1)
				cout << "Failas nerastas" << endl;
			else if (n == 0)
				cout << "Failas tuscias" << endl;
		}
		for(auto i=0;i<moksk;i++)
		{	
			in >> tempm.vardas >> tempm.pavarde;
			string line;
			getline(in, line);
			std::istringstream iss(line);
			double temp;
			while (iss >> temp)
				tempm.paz.push_back(temp);
			temp = tempm.paz.back();
			tempm.egz= temp;
			tempm.paz.pop_back();
			a.push_back(tempm);
			tempm.paz.clear();
		}
		bool metodas;
		cout << "Pazymiu skaiciavimo budas: mediana(0) arba vidurkis(1)" << endl;
		try
		{
			cin >> metodas;
			if (metodas != 0 && metodas != 1)
				throw 1;
		}
		catch (int a)
		{
			cout << "Iveskite 0 arba 1" << endl;
			exit(a);
		}
		auto start = std::chrono::high_resolution_clock::now();
		//std::sort(a.begin(), a.end(), sortByLastName);
		a.sort(sortByLastName);
		skirstimas(a, metodas, vidurkis);
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		cout << "Duomenu suskirtimo ir isvedimo laikas: " << elapsed.count() << "s" << endl;
		cout << a.size() << endl;
		outputfile(a,metodas,vidurkis);
		in.close();
	}
	return 0;
}