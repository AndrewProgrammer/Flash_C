#include <iostream>
using namespace std;
class Foo
{
public:
	Foo()
	{
		cout << "Constructor" << endl;
	}
};

int main()
{
	Foo a;
	Foo b();

	return 0;
}

