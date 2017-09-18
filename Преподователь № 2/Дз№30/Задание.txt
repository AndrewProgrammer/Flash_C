#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define STONES 10
#define MIN_PART 1
#define MAX_PART 3
#define FLAG_HUMAN 1
#define FLAG_AI 2

void main()
{
	int stones_quantity = STONES;
	int max_part;
	int taken_stones;
	int control_flag = FLAG_HUMAN;

	srand(time(0));
	for (;;)
	{
		cout << "There are " << stones_quantity << " stones.\n";
		max_part = stones_quantity >= MAX_PART ? MAX_PART : stones_quantity;
		if (control_flag == FLAG_HUMAN)
		{
			cout << "You should take not less than " << MIN_PART << " and not more than " <<  max_part << " stones.\n";
			cout << "How many stones you want to take? ";
			cin >> taken_stones;
			if (taken_stones <= MIN_PART || taken_stones >= max_part)
			{
				cout << "You said incorrect quantity.\n";
				break;
			}
		}
		if (control_flag == FLAG_AI)
		{
			taken_stones = stones_quantity - 1;
			if (taken_stones > max_part || taken_stones < MIN_PART)
			{
				taken_stones = rand() % (max_part - MIN_PART + 1) + MIN_PART;
			}
			cout << "Computer took: " << taken_stones << "stones.\n";
		}
		stones_quantity -= taken_stones;
		if (stones_quantity == 0)
		{
			if (control_flag == FLAG_HUMAN)
			{
				cout << "Computer wins and you loses.\n";
			}
			if (control_flag == FLAG_AI)
			{
				cout << "You wins and computer loses.\n";
			}
			break;
		}
		else
		{
			if (control_flag == FLAG_HUMAN)
			{
				control_flag = FLAG_AI;
			}
			else
			{
				control_flag = FLAG_HUMAN;
			}
		}
		system("pause");
	}
	system("pause");
}