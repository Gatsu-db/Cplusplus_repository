#include <iostream>
int main()
{
	int HP = 25;

	if (0 < HP < 50)
	{
		std::cout << "Heal up\n";
	}
	else if (HP > 0)
	{
		std::cout << "Players alive\n";
	}
	else
	{
		std::cout << "player's dead\n";
	}
	return 0;
}