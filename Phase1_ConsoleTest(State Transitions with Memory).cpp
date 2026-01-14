#include <iostream>
using namespace std;

enum Enemystate
{
	HEALTHY,
	HURT,
	CRITICAL,
	DEAD,
};

struct Enemy
{
	int health;
	Enemystate state;
	Enemystate previousState; // Remebers last state
};

Enemystate determinenextstate(const Enemy& enemy)
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
	cout << "enemy " << index << " Decides to ";

	switch (enemy.state)
	{
	case HEALTHY: cout << "Act agressivly\n";
		break;
	case HURT: cout << "Defend Themselves\n";
		break;
	case CRITICAL: cout << "Attempt Fleeing\n";
		break;
	case DEAD: cout << "Be Dead ig\n";
		break;
	}
}

void Printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << "| Health: " << enemy.health << " | State ";

	switch (enemy.state)
	{
	case HEALTHY: cout << "HEALTHY";
		break;
	case HURT: cout << "HURT";
		break;
	case CRITICAL: cout << "CRITICAL";
		break;
	case DEAD: cout << "DEAD";
		break;
	}
	cout << endl;
}
void Onenterstate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " entered ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "	HEALTHY\n";
		break;
	case HURT: cout << "HURT\n";
		break;
	case CRITICAL: cout << "CRITICAL\n";
		break;
	case DEAD: cout << "DEAD ig\n";
		break;
	}
}

int main()
{
	Enemy enemies[3]
	{
		{100,HEALTHY,HEALTHY},{60,HEALTHY,HEALTHY},{40,HEALTHY,HEALTHY}
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

			Enemystate newstate = determinenextstate(enemies[i]);

			if (newstate != enemies[i].state)
			{
				enemies[i].previousState = enemies[i].state;
				enemies[i].state = newstate;
				Onenterstate(enemies[i], i);
			}
			Printenemy(enemies[i], i);
			enemyaction(enemies[i], i);

			if (enemies[i].state != DEAD)
				alldead = false;
		}
		if (alldead)
		{
			cout << "\n All Enemies Dead\n";
			break;
		}
		turn++;
	}
	return 0;
}