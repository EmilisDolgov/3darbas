// Vidurkis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include <chrono>
#include <list>
#include <deque>
#include "studentai.h"


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::array;
using std::fixed;
using std::setprecision;
using std::list;
using std::deque;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;


int main()
{
	double vidurkis{};
	list<mokinysl> prileisti{};
	list<mokinysl> neprileisti{};
	timedgen(10);
	timedgen(100);
	timedgen(1000);
	timedgen(10000);
	timedgen(100000);
	list<mokinysl> a;
	timedproc(a, vidurkis, 10);
	timedproc(a, vidurkis, 100);
	timedproc(a, vidurkis, 1000);
	timedproc(a, vidurkis, 10000);
	timedproc(a, vidurkis, 100000);
	return 0;
}