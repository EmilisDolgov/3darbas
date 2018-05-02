#ifndef MOKINYS_H
#define MOKINYS_H

#include <string>
#include <vector>
#include <iomanip>

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
    inline bool operator<(const Mokinys& rhs) const 
	{
		return galBal < rhs.galBal;
	};
    inline bool operator>(const Mokinys& rhs) const
	{
		return galBal > rhs.galBal;
	};

	inline bool operator==(const Mokinys& rhs) const
	{
		return galBal == rhs.galBal;
	}
	inline bool operator!=(const Mokinys& rhs) const
	{
		return !operator==(rhs);
	}
	inline bool operator<=(const Mokinys& rhs) const
	{
		return galBal <= rhs.galBal;
	}
	inline bool operator>=(const Mokinys& rhs) const
	{
		return !operator<=(rhs);
	}
	inline friend std::ostream& operator<<(std::ostream& os, const Mokinys& obj)
	{
		os << obj.vardas << " " << obj.pavarde << " " << std::setprecision(2) << obj.galBal;
		return os;
	}

};
void generavimasfailo(int);
void timedgen(int);
void OutputFile(std::vector<Mokinys>&);
void skirstimas(std::vector<Mokinys>&);
void skirstimasistrinant(std::vector<Mokinys>&);
void skaitymasfailo(std::vector<Mokinys>&, int);
void timedproc(std::vector<Mokinys>&, int);
void timedprocwdel(std::vector<Mokinys>&, int);
#endif //!MOKINYS_H
