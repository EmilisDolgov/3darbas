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
	double egz;
	double vidurkis;
	double galBal;
};
struct mokinysd
{
	std::string vardas;
	std::string pavarde;
	double egz;
	double vidurkis;
	double galBal;
};
struct mokinysv
{
	std::string vardas;
	std::string pavarde;
	double egz;
	double vidurkis;
	double galBal;
};
double vidurkissk(std::list<double>&);
void outputfile(std::list<mokinysl>&);
void skirstimas(std::list<mokinysl>&);
void skirstimasistrinant(std::list<mokinysl>&);
bool sortByLastNameL(mokinysl&, mokinysl&);
void skaitymasfailo(std::list<mokinysl>&,int);
void timedproc(std::list<mokinysl>&, int);
void timedprocwdel(std::list<mokinysl>&, int);
//
double vidurkissk(std::deque<double>&);
void outputfile(std::deque<mokinysd>&);
void skirstimas(std::deque<mokinysd>&);
void skirstimasistrinant(std::deque<mokinysd>&);
bool sortByLastNameD(mokinysd&, mokinysd&);
void skaitymasfailo(std::deque<mokinysd>&, int);
void timedproc(std::deque<mokinysd>&, int);
void timedprocwdel(std::deque<mokinysd>&, int);
//
double vidurkissk(std::vector<double>&);
void outputfile(std::vector<mokinysv>&);
void skirstimas(std::vector<mokinysv>&);
void skirstimasistrinant(std::vector<mokinysv>&);
bool sortByLastNameV(mokinysv&, mokinysv&);
void skaitymasfailo(std::vector<mokinysv>&, int);
void timedproc(std::vector<mokinysv>&, int);
void timedprocwdel(std::vector<mokinysv>&, int);
//
void generavimasfailo(int);
void timedgen(int);
#endif // !STUDENTAI_H
