#include <iostream>
using namespace std;
void main()
{
	double time;
	int d, h, m;
	cout << "Enter Time(seconds): " << endl;
	cin >> time;
	d = time / 86400;
	h = time / 3600;
	m = (time - h) / 60;
	cout << "Time in days: " << d << " Time in hours: " << h << " Time in minutes: " << m << endl;
}