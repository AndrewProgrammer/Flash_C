#include <iostream>
using namespace std;


/*
	Функция может принимать аргументы.
	Каждый аргумент отдельная переменная, которая существует только внутри функции.
	При объявлении функции с параметрами, каждой переменной-параметру необходимо задать свой тип.
*/


void sumOfTwo (int firstVal, int secondVal)
{
	int result = firstVal + secondVal;
	cout << "Result: " << result << endl;
}

void sumOfThree (int firstVal, int secondVal, double thirdVal)
{
	double result = firstVal + secondVal + thirdVal;
	cout << "Result: " << result << endl;
}



// Аргументы в функцию в данном случае передаются по значению.
// Это значит, что значения будут при вызове СКОПИРОВАНЫ в переменные-аргументы у функции, без привязки к месту вызова.
// По идее эта функция должна менять местами значения исходных переменных. Это и просиходит, НО...
// Это происходит только с локальными перменными-аргументами, которые живут только внутри функции.

void wrongSwap (int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void main ()
{
	int first = 5, second = 2;

	// Вызываем функцию sumOfTwo, передавая в качестве первого аргумента значение переменной first, а в качестве второго - значение
	// переменной second
	sumOfTwo (first, second);



	// Вызываем функцию sumOfTwo, передавая в качестве первого аргумента значение переменной first, а в качестве второго - значение
	// переменной second. Обратите внимание на то, что значение 8.2 - double. Тем не менее, будет взято значение, выполнено преобразование
	// и преобразованное значение будет передано функции sumOfTwo в качестве второго параметра.
	sumOfTwo (first, 8.2);

	// У функции sumOfThree три параметра
	sumOfThree (first, second, 15.1);






	cout << "Before swap: first = " << first << " \t second = " << second << endl;

	// По идее, значения first и second должны поменяться местами, однако этого не происходит.
	// Причина - аргументы передаются по значению. То есть из переменной first копируется значение и помещается в первую переменную-аргумент у функции,
	// и то же самое происходит со вторым значением. На переменные в функции main никакого эффекта нет.
	wrongSwap (first, second);

	cout << "After swap: first = " << first << " \t second = " << second << endl;
}