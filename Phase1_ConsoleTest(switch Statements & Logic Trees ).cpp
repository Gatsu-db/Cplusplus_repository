#include <iostream>
using namespace std;

int main()
{
	int gamestate;
	cout << "Enter a number from 0 - 3: " << endl;
	cin >> gamestate;


	switch (gamestate)
	{
	case 0:
		cout << "Main Menu" << endl;
		break;
	case 1:
		cout << "Playing Game" << endl;
		break;
	case 2 :
		cout << "Paused" << endl;
		break;
	case 3:
		cout << "Game Over" << endl;
		break;
	default:
		cout << "Unknown State" << endl;

	}

	return 0;
}