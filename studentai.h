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
//double mediana(std::vector<double>&);
void outputcons(std::string, std::string, std::deque<double>&, double);
void outputfile(std::deque<mokinys>&,bool,double);
void skirstimas(std::deque<mokinys>&, bool, double&);
void generavimasfailo(int&);
bool sortByLastName(const mokinys&,const mokinys&);
#endif // !STUDENTAI_H
