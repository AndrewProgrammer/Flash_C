#include <iostream>
using namespace std;
class A
{
public:
	A() { cout << "Constr A" << endl; }
	~A() { cout << "Destr A" << endl; }
};

class B
{
public:
	B() { cout << "Constr B" << endl; }
	~B() { cout << "Destr B" << endl; }
};

class C : public A, public B
{
public:
	C() { cout << "Constr C" << endl; }
	~C() { cout << "Destr C" << endl; }
};

void main()
{
	C c;
}