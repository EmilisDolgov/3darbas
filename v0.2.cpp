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


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::array;
using std::fixed;
using std::setprecision;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;

struct mokinys
{
	string vardas;
	string pavarde;
	vector<double> paz;
	double egz;
	double galBal;
};

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
		vidurkis=vidurkissk(paz);
	else if (metodas == 0)
		vidurkis=mediana(paz);
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
	for(auto i=0;i<a.size();i++)
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
	double laik{};
	vector<double> paz{};
	cout << "Duomenu ivedimo budas: ivedimas(0) arba skaitymas is failo(1)" << endl;
	cin >> sk;
	if (!sk)
	{
		cout << "Vardas: ";
		cin >> vardas;
		cout << "Pavarde: ";
		cin >> pavarde;
		cout << "Egzamino ivertinimas: ";
		cin >> egz;
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
		vector<mokinys> a;
		ifstream in("kursiokai.txt");
		int i{};
		while (!in.eof())
		{
			a.push_back(mokinys());
			in >> a[i].vardas >> a[i].pavarde;
			string line;
			getline(in, line);
			std::istringstream iss(line);
			double temp;
			while (iss >> temp)
				a[i].paz.push_back(temp);
			temp = a[i].paz.back();
			a[i].egz = temp;
			a[i].paz.pop_back();
			i++;
		}
		outputfile(a);
		in.close();
	}
	return 0;
}