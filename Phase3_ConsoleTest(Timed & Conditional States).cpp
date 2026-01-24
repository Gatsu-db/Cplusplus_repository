#include <iostream>
using namespace std;

enum Enemystate
{
	HEALTHY,HURT,CRITICAL,DEAD
};

struct Enemy {
	int health;
	int stateturns;
	Enemystate state;
	Enemystate previoustate;
};

Enemystate Determinenextstate(const Enemy& enemy)
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

void onEnterState(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " Entered ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Healthy\n";
		break;
	case HURT: cout << "Hurt\n";
		break;
	case CRITICAL: cout << "Critical\n";
		break;
	case DEAD: cout << "Dead\n";
		break;
	}
}

void onExitstate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " Exited ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Healthy\n";
		break;
	case HURT: cout << "Hurt\n";
		break;
	case CRITICAL: cout << "Critical\n";
		break;
	case DEAD: cout << "Dead\n";
		break;
	}
}

void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " | Health " << enemy.health << " | State ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Healthy";
		break;
	case HURT: cout << "Hurt";
		break;
	case CRITICAL: cout << "Critical";
		break;
	case DEAD: cout << "Dead";
		break;
	}
	cout <<" |turns in state: "<<enemy.stateturns << endl;
}

void onUpdatestate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " decides to ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Act aggressively\n";
		break;
	case HURT: cout << "Defend themselves\n";
		break;
	case CRITICAL: if (enemy.stateturns == 0)
		cout << "panic\n";
				 else
		cout << "Attempt to flee\n";
		break;
	case DEAD: cout << "Dead\n";
		break;
	}
}

int main()
{
	Enemy enemies[3]
	{ {100,0,HEALTHY,HEALTHY},{60,0,HEALTHY,HEALTHY,},{40,0,HEALTHY,HEALTHY} };

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

			Enemystate newstate = Determinenextstate(enemies[i]);

			if (newstate != enemies[i].state)
			{
				onExitstate(enemies[i], i);// this only runs on transition
				enemies[i].previoustate = enemies[i].state;
				enemies[i].state = newstate;
				enemies[i].stateturns = 0;
				onEnterState(enemies[i], i);// this runs once 
			}
			else
			{
				enemies[i].stateturns++;
			}
			printenemy(enemies[i], i); //this runs every turn
			onUpdatestate(enemies[i], i);
			if (enemies[i].state != DEAD)
				alldead = false;
		}
		if (alldead)
		{
			cout << "\nAll Enemies Dead\n";
			break;
		}
		turn++;
	}
	return 0;
	
}