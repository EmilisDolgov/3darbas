#include "stdafx.h"
#include "studentai.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

void generavimasfailo(int n)
{
	std::ofstream out("kursiokai" + std::to_string(n) + ".txt");
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 10);
	for (auto i = 0; i < n; i++)
	{
		out << "Vardas" + std::to_string(i) << " ";
		out << "Pavarde" + std::to_string(i) << " ";
		out << dis(gen) << " " << dis(gen) << " " << dis(gen) << " " << dis(gen) << " " << dis(gen) << " ";
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
	std::cout << "Failo generavimo laikas: " << elapsed.count() << "s" << std::endl;
}