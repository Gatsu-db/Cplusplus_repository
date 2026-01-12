#include <iostream>
using namespace std;

enum Enemystate
{
	HEALTHY,
	HURT,
	CRITICAL,
	DEAD
};

struct Enemy
{
	int health;
	Enemystate state;
};

Enemystate DetermineNextState(const Enemy& enemy)
{
	if (enemy.health <= 0)
		return DEAD;
	else if (enemy.health <= 20)
		return CRITICAL;
	else if (enemy.health <= 50)
		return HURT;
	else
		return HEALTHY;
}

void enemyaction(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " Decides to ";

	switch (enemy.state)
	{
	case HEALTHY: cout << "Attack aggressivly\n";
		break;
	case HURT: cout << "Defend Themself\n";
		break;
	case CRITICAL: cout << "Attempt fleeing\n";
		break;
	case DEAD: cout << "Be dead(Well its dead can't do much)";
		break;
	}
}

void Printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " | Health: " << enemy.health << " | State: ";

	switch (enemy.state)
	{
	case HEALTHY: cout << "HEALTHY";
		break;
	case HURT: cout << "HURT";
		break;
	case CRITICAL: cout << "CRITCAL";
		break;
	case DEAD: cout << "DEAD";
		break;
	}
	cout << endl;
}

int main()
{
	Enemy enemies[3]
	{
		{100,HEALTHY}, {60,HEALTHY}, {30,HEALTHY}
	};

	int turn = 1;
	while (true)
	{
		cout << "\n--- TURN " << turn << " ---\n";

		bool alldead = true;

		for (int i = 0; i < 3; i++)
		{
			if (enemies[i].state == DEAD)
				continue;

			enemies[i].health -= 25;

			enemies[i].state = DetermineNextState(enemies[i]);

			Printenemy(enemies[i], i);
			enemyaction(enemies[i], i);

			if (enemies[i].state != DEAD)
				alldead = false;
		}

		if (alldead)
		{
			cout << "\nAll Enemies Defeated\n";
				break;
		}

		turn++;
	}

	return 0;
}