#include <iostream>
using namespace std;

int Playerhealth = 100;

void Damage(int hurt)
{
	Playerhealth -= hurt;
		cout << "player took " << hurt << " damage." << endl;
}

void showhp()
{
	cout << "Current HP is:\n" << Playerhealth << endl;
}

int main()
{
	showhp();

	for (int i=0; i <= 9; i++)
	{
		Damage(10);
			showhp();
	}

	cout << "GAME OVER" << endl;

	return 0;
}