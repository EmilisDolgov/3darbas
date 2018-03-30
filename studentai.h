#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <string>
#include <list>

struct mokinys
{
	std::string vardas;
	std::string pavarde;
	std::list<double> paz;
	double egz;
	double galBal;
};
double vidurkissk(std::list<double>&);
double mediana(std::list<double>&);
void outputcons(std::string, std::string, std::list<double>&, double);
void outputfile(std::list<mokinys>&, std::list<mokinys>&, std::list<mokinys>&,bool);
void generavimasfailo(int&);
bool sortByLastName(const mokinys&,const mokinys&);
#endif // !STUDENTAI_H
