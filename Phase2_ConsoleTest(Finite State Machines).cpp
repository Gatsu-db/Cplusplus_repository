#include <iostream>
using namespace std;

enum Enemystate {
	HEALTHY,HURT,CRITCAL,DEAD
};

struct Enemy
{
	int health;
	Enemystate state;
	Enemystate previoustate;
};

Enemystate determinenextstate(const Enemy& enemy)
{
	if (enemy.health <= 0)
		return DEAD;
	else if (enemy.health <= 20)
		return CRITCAL;
	else if (enemy.health <= 50)
		return HURT;
	else
		return HEALTHY;
}

void onExitstate(const Enemy&enemy,int index)
	{	if (enemy.state == DEAD)
			return;

		cout <<"Enemy "<< index<< " Exited " ;
		
		switch (enemy.state)
		{
		case HEALTHY: cout << "Healthy\n";
			break;
		case HURT: cout << "Hurt\n";
			break;
		case CRITCAL:cout << "Critical\n";
			break;
		default:
			break;
		}
	}

void onEnterstate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " Entered ";
		switch (enemy.state)
		{
		case HEALTHY:cout << "Healthy\n";
			break;
		case HURT:cout << "Hurt\n";
			break;
		case CRITCAL:cout << "Critical\n";
			break;
		case DEAD:cout << "Dead\n";
			break;
		}
}

void onUpdatestate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " decides to ";

	switch (enemy.state)
	{
	case HEALTHY:cout << "Act aggressively\n";
		break;
	case HURT:cout << "Defend themselves\n";
		break;
	case CRITCAL:cout << "Attempt fleeing\n";
		break;
	case DEAD:cout << "Be dead\n";
		break;
	}
}

void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << "| Health: " << enemy.health << " |State ";
	switch (enemy.state)
	{
	case HEALTHY:cout << "Healthy\n";
		break;
	case HURT:cout << "Hurt\n";
		break;
	case CRITCAL:cout << "Critical\n";
		break;
	case DEAD:cout << "Dead\n";
		break;
	}
	cout <<endl;
}

int main()
{
	Enemy enemies[3] = { {100,HEALTHY,HEALTHY},{60,HEALTHY,HEALTHY},{40,HEALTHY,HEALTHY} };

	int turn = 1;

	while (true)
	{
		cout << "\n--- TURN " << turn << " ---\n";
		bool alldead=true;

		for (int i = 0; i <3 ; i++)
		{
			if (enemies[i].state == DEAD)
				continue;
			enemies[i].health -= 25;

			Enemystate newstate = determinenextstate(enemies[i]);

			if (newstate!=enemies[i].state)
			{
				onExitstate(enemies[i], i);// this only runs on transition
				enemies[i].previoustate = enemies[i].state;
				enemies[i].state = newstate;
				onEnterstate(enemies[i], i);// this runs once 
			}
			printenemy(enemies[i], i); //this runs every turn
			onUpdatestate(enemies[i], i);
			if (enemies[i].state !=DEAD)
				alldead=false;
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
