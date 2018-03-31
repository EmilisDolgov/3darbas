#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <string>
#include <deque>

struct mokinys
{
	std::string vardas;
	std::string pavarde;
	std::deque<double> paz;
	double egz;
	double galBal;
};
double vidurkissk(std::deque<double>&);
double mediana(std::deque<double>&);
void outputcons(std::string, std::string, std::deque<double>&, double);
void outputfile(std::deque<mokinys>&, std::deque<mokinys>&, std::deque<mokinys>&,bool);
void generavimasfailo(int&);
bool sortByLastName(const mokinys&,const mokinys&);
#endif // !STUDENTAI_H
