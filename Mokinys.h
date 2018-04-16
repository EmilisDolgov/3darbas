#ifndef MOKINYS_H
#define MOKINYS_H

#include <string>
#include <list>
#include <vector>
#include <deque>

class Mokinys
{
private:
	std::string vardas;
	std::string pavarde;
	double egz;
	double vidurkis;
	double galBal;
public:
	Mokinys() {
		egz = 0;
		vidurkis = 0;
		galBal = 0;
	};
	Mokinys(std::string vard, std::string pava, double egza, double vid, double gB) {
		vardas = vard; pavarde = pava; egz = egza; vidurkis = vid; galBal = gB;
	};
	std::string Vardas() { return vardas; };
	std::string Pavarde() { return pavarde; };	
	double Vidurkis() { return vidurkis; };
	double Egz() { return egz; };
	double GalBal() { return galBal; };

};
bool sortByLastName(Mokinys&,Mokinys&);
void generavimasfailo(int);
void timedgen(int);
void OutputFile(std::list<Mokinys>&);
void skirstimas(std::list<Mokinys>&);
void skirstimasistrinant(std::list<Mokinys>&);
void skaitymasfailo(std::list<Mokinys>&, int);
void timedproc(std::list<Mokinys>&, int);
void timedprocwdel(std::list<Mokinys>&, int);
void OutputFile(std::vector<Mokinys>&);
void skirstimas(std::vector<Mokinys>&);
void skirstimasistrinant(std::vector<Mokinys>&);
void skaitymasfailo(std::vector<Mokinys>&, int);
void timedproc(std::vector<Mokinys>&, int);
void timedprocwdel(std::vector<Mokinys>&, int);
void OutputFile(std::deque<Mokinys>&);
void skirstimas(std::deque<Mokinys>&);
void skirstimasistrinant(std::deque<Mokinys>&);
void skaitymasfailo(std::deque<Mokinys>&, int);
void timedproc(std::deque<Mokinys>&, int);
void timedprocwdel(std::deque<Mokinys>&, int);
#endif // !MOKINYS_H
