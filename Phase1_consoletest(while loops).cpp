#include <iostream>
using namespace std;

int main()
{

	int hp = 0;

	do
	{
		cout << "this runs once\n\n" << endl;
	} while (hp > 0);
	

	int HP = 100;

	while (HP > 0)
	{
		cout << "player Health is: " << HP << endl;
		HP = HP - 20;
	}

	cout << "Player is Dead" << endl;

	return 0;
}