#include "PI.h"
#include<iostream>
#include<iomanip>
#include<math.h>

const long double PI = 3.14159265358979323846;
double TwoDigits() {
	return 22.0/7;
}

long double Archimedes(int n)
{
	long double d = 2.0; //polygon_edge_length_squared
	int N = 4;//polygon_side
	for (int i = 1; i < n; i++) {
		d = 2 - 2 * sqrt(1 - d/ 4);
		N *= 2;
		std::cout << "Polygon Sides: " << N << std::endl;
		std::cout<< std::setprecision(20) <<std::fixed<< N * sqrt(d) / 2<<std::endl;
		std::cout<<"Error: "<< std::setprecision(20) << std::fixed << (N * sqrt(d) / 2 )-PI<< std::endl;
		std::cout << std::endl;
	}
	return N * sqrt(d) / 2;
}
