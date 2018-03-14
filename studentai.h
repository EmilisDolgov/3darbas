#ifndef STUDENTAI_H
#define STUDENTAI_H
#include <string>
#include <vector>
using std::string;
using std::vector;
struct mokinys
{
	string vardas;
	string pavarde;
	vector<double> paz;
	double egz;
	double galBal;
};
double vidurkissk(vector<double>& paz);
double mediana(vector<double>& paz);
void outputcons(string vardas, string pavarde, vector<double>& paz, double egz);
void outputfile(vector<mokinys>& a);
#endif // !STUDENTAI_H
