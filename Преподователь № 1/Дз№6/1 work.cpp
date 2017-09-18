#include <iostream>
using namespace std;
void main()
{
	double S, V, t;
	int h, m, s;
	cout << "Enter distance(km)" << endl;
	cin >> S;
	cout << "Enter speed(m/c)" << endl;
	cin >> V;
	t = S / V;
	h = (int)t / 3600;
	m = (t - h * 3600) / 60;
	s = t - ((h * 3600) - (m * 60));
	cout << "Time in hours \n" << h << "Time in m \n" << m << "Time in s \n" << s;
}