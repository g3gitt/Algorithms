#include<iostream>
#include "AreaCircumference.h"
#include "PI.h"

using namespace std;
int main() {
	cout << area(1)<<endl;
	cout << circumference(4)<<endl;
	cout << "This School Method 22/7 returns value correct only for 2 digts after decimal points "<<TwoDigits() << endl;
	cout << "This uses Archimedes Method to calculate the value of PI "<<Archimedes(20) << endl;
}