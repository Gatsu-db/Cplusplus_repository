#include <iostream>
#include <string>;
using namespace std;

enum Enemystate
{
	HEALTHY,
	HURT,
	CRITICAL,
	DEAD
};

enum Playerattck
{
	MAGIC = 1,
	MELEE,
	RANGED
};

struct Player
{
	int damage;
	Playerattck action;
};

struct Enemy
{
	int health;
	Enemystate state;
};

void updatestate(Enemy& enemy)
{
	if (enemy.health <= 0)
	{
		enemy.state = DEAD;
	}
	else if (enemy.health <= 20)
	{
		enemy.state = CRITICAL;
	}
	else if (enemy.health <= 50)
	{
		enemy.state = HURT;
	}
	else
	{
		enemy.state = HEALTHY;
	}
}

void Printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy: " << index << " |Health: " << enemy.health << " |" ;
	switch (enemy.state)
	{
	case HEALTHY: cout << " Healthy";
		break;
	case HURT: cout << " Hurt";
		break;
	case CRITICAL: cout << " Critical";
		break;
	case DEAD: cout << " Dead";
		break;
	}
	cout << "\n" <<endl;
}

void Enemyaction(const Enemy& enemy, int index)
{
	cout << "\nEnemy " << index << " takes action by:";
	switch (enemy.state)
	{
	case HEALTHY: cout << " Acting agressivly\n";
		break;
	case HURT: cout << " Defending self\n";
		break;
	case CRITICAL: cout << " attempts retreat\n";
		break;
	case DEAD: cout << " Being dead\n";
		break;
	}
	cout << endl;
}

void playeraction(Player& player, int attack, const Enemy& enemy, Enemy enemies[], int index);

int main()
{
	Enemy enemies[3] =
	{
		{100, HEALTHY},
		{60, HEALTHY},
		{40, HEALTHY}
	};

	Player options[3] =
	{
		{5, MAGIC},
		{7, MELEE},
		{3, RANGED}
	};

	string name;
	cout << "\nPlayer please input your name: ";
	cin >> name;
	cout << "\nGreetings " << name << '\n';

	int turn = 1;
	while (true)
	{
		cout << "\n--- TURN " << turn << "---\n";

		bool alldead = true;

		for (int i = 0; i < 3; i++)
		{
			if (enemies[i].state == DEAD)
				continue;

			playeraction(options[i], options[i].action, enemies[i], enemies, i);
			updatestate(enemies[i]);
			Enemyaction(enemies[i], i);
			Printenemy(enemies[i], i);

			if (enemies[i].state != DEAD)
				alldead = false;

		}

		if (alldead)
		{
			cout << "You've Defeated all of the enemies " << name << " Your victorious";
			break;
		}

		turn++;
	}
	return 0;
}

void playeraction(Player& player, int attack, const Enemy& enemy,Enemy enemies[], int index)
{
	Player options[3] =
	{
		{17, MAGIC},
		{25, MELEE},
		{15, RANGED}
	};

	cout << "Choose your attack method:\n1. Magic\n2. Melee\n3. Ranged\n";
	cout << "\n";
	cin >> attack;

	if (enemy.state == CRITICAL && attack == 2)
	{
		options[1].damage = 0 ;
		cout << "\nYour too far away (try Ranged or Magic)\n";
	}
	

	switch (attack)
	{
	case MAGIC:cout << "\nYou chose the Magic attack dealing " << options[0].damage << " damage.\n";
		enemies[index].health -= options[0].damage;
		break;
	case MELEE: cout << "\nYou chose the Melee attack dealing " << options[1].damage << " damage\n";
		enemies[index].health -= options[1].damage;
		break;
	case RANGED: cout << "\nYou chose the Ranged attack dealing " << options[2].damage << " damage\n";
		enemies[index].health -= options[2].damage;
		break;
	default: cout << "\ninvalid attack type!\n";
		break;
	}
}
