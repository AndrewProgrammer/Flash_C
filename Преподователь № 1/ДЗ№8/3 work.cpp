#include <iostream>;
using namespace std;
void main()
{
	int a, N, M;
	cout << "Vedite a\n";
	cin >> a;
	cout << "Vedite N\n";
	cin >> N;
	cout << "Vedite M\n";
	cin >> M;
	if (a >= N && a <= M)
	{
		cout << "Chislo a prinadleschit diapozony ot N do M!\n";
	}
	else cout << "a ne prinadleschit diapozony ot N do M!\n";
}
