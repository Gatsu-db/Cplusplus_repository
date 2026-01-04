#include <iostream>
using namespace std;

int main()
{
	int hp = 194; // the player starts with a large health pool
	int dps = 10; // base damage per enemy
	int totaldamage = 0; // tracks the accumulated damge

	//loop runs exactly 5 times (5 enemies)
	for (int enemyindex = 1; enemyindex <= 10; enemyindex++)
	{
		//damage increases per enemy 
		int currentdamage = (dps + enemyindex)*2;

			// accumulate total damage
		totaldamage += currentdamage;

		//apply damage to a player
		hp -= currentdamage;

		cout << "Enemy " << enemyindex
			<< " dealt " << currentdamage
			<< " damage. Health now: "
			<< hp << endl;
		
		if (hp <= 0)
		{
			break;
		}
	}

	cout << "Total dmagee taken: " << totaldamage << endl;
	
	// gives reponses based on current health
	
	if (totaldamage >= (hp+totaldamage) )
	{
		cout << "\nGame Over you died" << endl;
	}
	else if (totaldamage <= ((hp+totaldamage)/2))
	{
		cout << "hang in there your doing great" << endl;
	}
	else
	{
		cout << "you might want to heal you only have " << hp << " health left" << endl;
	}


	return 0;
}