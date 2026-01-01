#include <iostream>
using namespace std;

int main()
{
	int Hp = 50;

	if (Hp > 50)
	{
		cout << "player is healthy" << endl;
	}

	else if (Hp > 0)
	{
		cout << "player is injured" << endl;
	}

	else
	{
		cout << "player is dead" << endl;
	}

	return 0;
}