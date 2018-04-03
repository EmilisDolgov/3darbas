#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <string>
#include <list>
#include <vector>
#include <deque>

struct mokinysl
{
	std::string vardas;
	std::string pavarde;
	std::list<double> paz;
	double egz;
	double galBal;
};
struct mokinysd
{
	std::string vardas;
	std::string pavarde;
	std::deque<double> paz;
	double egz;
	double galBal;
};
struct mokinysv
{
	std::string vardas;
	std::string pavarde;
	std::vector<double> paz;
	double egz;
	double galBal;
};
double vidurkissk(std::list<double>&);
void outputfile(std::list<mokinysl>&,double);
void skirstimas(std::list<mokinysl>&,double&);
bool sortByLastNameL(const mokinysl&,const mokinysl&);
void skaitymasfailo(std::list<mokinysl>&,int);
void timedgen(int);
void timedproc(std::list<mokinysl>&, double, int);
double vidurkissk(std::deque<double>&);
void outputfile(std::deque<mokinysd>&, double);
void skirstimas(std::deque<mokinysd>&, double&);
void skaitymasfailo(std::deque<mokinysd>&, int);
bool sortByLastNameD(const mokinysd&, const mokinysd&);
double vidurkissk(std::vector<double>&);
void outputfile(std::vector<mokinysv>&, double);
void skirstimas(std::vector<mokinysv>&, double&);
bool sortByLastNameV(const mokinysv&, const mokinysv&);
void skaitymasfailo(std::vector<mokinysv>&, int);
void generavimasfailo(int);
#endif // !STUDENTAI_H
