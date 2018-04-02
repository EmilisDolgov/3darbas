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
//double mediana(std::vector<double>&);
void outputcons(std::string, std::string, std::list<double>&, double);
void outputfile(std::list<mokinys>&,bool,double);
void skirstimas(std::list<mokinys>&, bool, double&);
void generavimasfailo(int&);
bool sortByLastName(const mokinys&,const mokinys&);
#endif // !STUDENTAI_H
