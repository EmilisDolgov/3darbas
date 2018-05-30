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
	///Konstruktorius su paduodamu inputu
    Mokinys(std::istream& input);
	///Funkcija grąžinanti vardą
	std::string Vardas() { return vardas; };
	///Funkcija grąžinanti pavardę
	std::string Pavarde() { return pavarde; };
	///Funkcija grąžinanti vidurkį
	double Vidurkis() { return vidurkis; };
	///Funkcija grąžinanti egzamino įvertinimą
	double Egz() { return egz; };
	///Funkcija grąžinanti galutinį įvertinimą
	double GalBal() { return galBal; };
	///Palyginimo operatorius <
    inline bool operator<(const Mokinys& rhs) const 
	{
		return galBal < rhs.galBal;
	};
	///Palyginimo operatorius >
    inline bool operator>(const Mokinys& rhs) const
	{
		return galBal > rhs.galBal;
	};
	///Palyginimo operatorius ==
	inline bool operator==(const Mokinys& rhs) const
	{
		return galBal == rhs.galBal;
	}
	///Palyginimo operatorius !=
	inline bool operator!=(const Mokinys& rhs) const
	{
		return !operator==(rhs);
	}
	///Palyginimo operatorius <=
	inline bool operator<=(const Mokinys& rhs) const
	{
		return galBal <= rhs.galBal;
	}
	///Palyginimo operatorius >=
	inline bool operator>=(const Mokinys& rhs) const
	{
		return !operator<=(rhs);
	}
	///Outputo operatorius
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
void timedproc(std::vector<Mokinys>&, int);
void timedprocwdel(std::vector<Mokinys>&, int);
#endif //!MOKINYS_H
