#include <iostream>
using namespace std;
void main()
{
	double S;
	int tvm, v = 0, tvh;
	cout << "Enter distance: " << endl;
	cin >> S;
	cout << "Enter time(minutes only): " << endl;
	cin >> tvm;
	tvh = tvm / 60;
	v = S / tvh;
	cout << "To arrive in time your speed must be (km/h) = " << v << endl;
}