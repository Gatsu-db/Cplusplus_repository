#include <iostream>
using namespace std;

enum Enemystate
{
	HEALTHY,
	HURT,
	CRTICAL,
	DEAD,
};

struct Enemy
{
	int health;
	Enemystate state;
	Enemystate previousState;
};

Enemystate determinenextstate(const Enemy& enemy)
{
	if (enemy.health <= 0)
		return DEAD;
	else if (enemy.health <= 20)
		return CRTICAL;
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
	case HEALTHY: cout << "Act Aggressivly\n";
		break;
	case HURT: cout << "Defend Themselves\n";
		break;
	case CRTICAL: cout << "Attempt To flee\n";
		break;
	case DEAD: cout << "be dead\n";
		break;
	}
}

void OnEnterstate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " enetered ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Healhty\n";
		break;
	case HURT: cout << " Hurt\n";
		break;
	case CRTICAL: cout << " Critcal\n";
		break;
	case DEAD: cout << " Dead\n";
		break;
	}
}

void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << "| Health: " << enemy.health << " | State ";

	switch (enemy.state)
	{
	case HEALTHY: cout << "Healhty";
		break;
	case HURT: cout << "Hurt";
		break;
	case CRTICAL: cout << "Critcal";
		break;
	case DEAD: cout << "Dead";
		break;
	}
		cout << endl;
}

void OnExitstate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " Exited ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Healhty\n";
	break;
	case HURT: cout << " Hurt\n";
		break;
	case CRTICAL: cout << " Critcal\n";
		break;
	case DEAD: cout << " Dead\n";
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

		for (int i = 0; i<3; i++)
		{
			if (enemies[i].state == DEAD)
				continue;

			enemies[i].health -= 25;

			Enemystate newstate = determinenextstate(enemies[i]);

			if(newstate != enemies[i].state)
			{
				OnEnterstate(enemies[i], i);
				enemies[i].previousState = enemies[i].state;
				enemies[i].state = newstate;
				OnExitstate(enemies[i], i);
			}
			printenemy(enemies[i], i);
			enemyaction(enemies[i], i);

			if (enemies[i].state != DEAD)
				alldead = false;
		}
		if (alldead)
		{
			cout << "\nAll enemies Dead\n";
			break;
		}
		turn++;
	}
	return 0;
}