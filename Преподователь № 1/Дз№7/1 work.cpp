#include <iostream>;
using namespace std;
void main()
{
	double funti, kg, const gr=409.5;
	cout << "kol funtov\n";
	cin >> funti;
	kg = funti * gr / 1024;
	cout << "funti v kg\n" << kg;
}